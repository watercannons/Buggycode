// tabledemo.cpp - demonstration program for Table

#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <string>
#include "table.h"

#define THREADS (4)
#define KEY_MAX_LENGTH (256)
#define KEY_COUNT (1024 * 32) // number of entries we make into the hashtable
#define TABLE_SIZE KEY_COUNT/2 // this is fine since we resolve collisions in the hashtable with chaining(using a linked list)

using namespace std;

/*
	Multi-threaded hashtable example:

					NULL<-C0	L0
			NULL<-e4<-e1<-C1	L1
				NULL<-e3<-C2	L2
				NULL<-e2<-C3	L3

		C0-C3 are the buckets of the hashtable e1-4 are the elements in the hashtable and L0-L3 are the locks for each bucket. Collisions in this hashtable are resolved by chaining. For example e1 and e4 hash
		to the same bucket and to resolve the collision a linked list is created where the bucket C1 points to e1 and the "next" pointer of e1 points to e4.
	Example of put():
		Initial state:
					NULL<-C0	L0
			NULL<-e4<-e1<-C1	L1
				NULL<-e3<-C2	L2
				NULL<-e2<-C3	L3

		put(e5)
			hash(e5) = 3 so we place e5 in bucket C3 by first grabbing lock L3

					NULL<-C0	L0
			NULL<-e4<-e1<-C1	L1
				NULL<-e3<-C2	L2
				NULL<-e2<-C3	|L3|
			
			Then adding e5 to the end of the linked list for bucket C3

					NULL<-C0	L0
			NULL<-e4<-e1<-C1	L1
				NULL<-e3<-C2	L2
			NULL<-e5<-e2<-C3	|L3|

			Finally we release the lock (L3) which completes the put operation

					NULL<-C0	L0
			NULL<-e4<-e1<-C1	L1
				NULL<-e3<-C2	L2
			NULL<-e5<-e2<-C3	L3

	Remove works in a similar way as put, but it removes the entity for a given key.
	
*/


Table *mytable;
void *workerThread(void *);

int main() {
    int i;
    int ret;
    mytable = new Table(TABLE_SIZE); 
    pthread_t tids[THREADS];
    for(i = 0; i < THREADS; i++)
    {
	  // create the worker threads to place a specific range of values into the hashtable
      ret = pthread_create(tids+i, NULL, workerThread, (void*) (intptr_t) i); 
		// if it failed to create a thread for some reason we give up and exit        
		if(ret) 
        {
            printf("Something went wrong. %d\n", ret);
            exit(1);
        }
    }
	// wait for all the threads to finish
    for(i = 0; i < THREADS; i++) 
    {
        pthread_join(tids[i], NULL);
    }

    // Now, destroy the table
    delete mytable;

    return EXIT_SUCCESS;
}
void *workerThread(void *arg)
{
    int index;
    int keys = KEY_COUNT/THREADS;
    int offset = keys * (intptr_t) arg;
    char numstr[21];

    // First, populate the hash map with ascending values from the range given to a particular worker thread
    for (index=offset; index<(keys + offset); index++)
    {
        sprintf(numstr,"somekey%d",index);
        mytable->put(index, std::string(numstr));
    }
    // Now, check all of the expected values are there for the worker's range
    for (index=offset; index<(keys + offset); index++)
    {
        std::string temp = mytable->get(index);
        assert(temp!="");
    }

    // Remove all the values from the hashtable for the worker's range
    for (index=offset; index<(keys + offset); index++)
    {
        assert(mytable->remove(index));
    }
    return 0;
}
