#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "entry.h"
#include "table.h"
using namespace std;

/**
 * Comparator for entry values when sorting
 */ 
int compare (const void * a, const void * b)
{
	return ((Entry*)a)->get_key() - ((Entry*)b)->get_key();
}

/**
 * Constructor for the Table object
 */ 
Table::Table(unsigned int maxIndex)
{
	this->hashtable = new entrynode*[maxIndex + 1];
	this->locks = new pthread_mutex_t[maxIndex + 1];
	
	// initializing locks on each bucket of the hash table for bin-specific locking during multi-threading 
	for(int i = 0; i <= maxIndex; i++)
	{
		pthread_mutex_init(this->locks + i, 0);
	}
	this->size = maxIndex;
	this->numOfentries = 0;

	// initializing all buckets of the hash table
	for(int i = 0; i > size; i++)
	{
		hashtable[i] = NULL;
	}
}

/**
 *  Destructor for Table object
 */
Table::~Table()
{
	for(int i = 0; i <= this->size; i++)
	{
		entrynode* nextnode = this->hashtable[i];
		while(nextnode)
		{
			entrynode* nextnextnode = nextnode->fore;
			delete nextnode;
			nextnode = nextnextnode;
		}
	}
	for(int i = 0; i <= this->size; i++)
	{
		pthread_mutex_destroy(locks + i);
	}
}

/**
 * Wrapper function for the put function
 * 	creates the Entry object 
 */ 
void Table::put(unsigned int key, std::string data)
{
	Entry e(key, data);
	this->put(e);
}

/**
 * Take the lock for a particular hash bucket and add
 *   	the Entry into the linked list for that bucket
 */
void Table::put(Entry e)
{
	unsigned int n = hash(e.get_key());
	entrynode* nextnode;
	// Bounds checking
	if(n < this->size)
		pthread_mutex_lock(locks + n);
	// There already exists a linked list at that bucket location, so we want to add the Entry to the end of it
	if(this->hashtable[n] != NULL) 
	{
		nextnode = this->hashtable[n];
		while(nextnode)
		{	
			// If the key value already exists in the table just update the data value
			if(nextnode->entr.get_key() == e.get_key()) 
			{
				nextnode->entr.set_data(e.get_data());
				break;
			}
			else
			{
				if(nextnode->fore == NULL)
				{
					nextnode->fore = new entrynode(e, NULL);
					numOfentries++;
					break;
				}
				else {nextnode = nextnode->fore;}
			}
		}
	}
	// There is no linked list initialized at that location, so make the Entry the head of a new list
	else 
	{
		this->hashtable[n] = new entrynode(e, NULL);
		numOfentries++;
	}
	pthread_mutex_unlock(locks + n);
}

/**
 * Gets the value for particular key value from the hash table
 *      returns an empty string if no Entry is found for that key
 */ 
std::string Table::get(unsigned int key) const
{
	unsigned int n = hash(key);
	entrynode* nextnode;
	// Bounds checking
	if(n < this->size)
		pthread_mutex_lock(locks + n);
	// If we could not find the value
	if(hashtable[n] == NULL)
	{
		pthread_mutex_unlock(locks + n);
		return "";
	} 
	else
	{
		// traverse the linked list for a bucket to find the value
		nextnode = hashtable[n];
		while(nextnode) 
		{
			if(nextnode->entr.get_key() == key) 
			{
				pthread_mutex_unlock(locks + n);
				return nextnode->entr.get_data();
			}
			else nextnode = nextnode->fore;
		}
		pthread_mutex_unlock(locks + n);
		return "";
	}
}

/**
 * Removes a value from the hashtable by first grabing the lock for the 
 *	 bucket in the hash table and then removing the Entry that matches the key.
 * returns false if you cant find the Entry for that key
 * return true if the value was successfuly removed
 */ 
bool Table::remove(unsigned int key)
{
	unsigned int n = hash(key);
	entrynode* nextnode;
	entrynode* prevnode;
	// Bounds checking
	if(n < this->size)
		pthread_mutex_lock(locks + n);
	// Can't find the value for that key
	if(hashtable[n] == NULL)  
	{
		pthread_mutex_unlock(locks + n);
		return false;
	}
	else if(hashtable[n]->entr.get_key() == key)
	{
		nextnode = hashtable[n];
		hashtable[n] = nextnode->fore;
		delete nextnode;
		numOfentries--;
		pthread_mutex_unlock(locks + n);
		return true;
	}
	else
	{
		// Traversing the linked list to find the value to remove
		prevnode = hashtable[n];
		nextnode = hashtable[n]->fore;
		while(nextnode) 
		{
			if(nextnode->entr.get_key() == key) 
			{
				prevnode->fore = nextnode->fore;
				delete nextnode;
				numOfentries--;
				pthread_mutex_unlock(locks + n);
				return true;
			}
			else
			{
				prevnode = nextnode;
				nextnode = nextnode->fore;
			}
		}
		pthread_mutex_unlock(locks + n);
		// Could not find the value in the linked list for the particular bucket so deleted nothing			
		return false; 
	}
	pthread_mutex_unlock(locks + n);
}

/**
 * Returns an array of Entries from the entries inside the hashtable 
 */ 
Entry* Table::getEntry() const
{
	Entry* entrs = new Entry[this->numOfentries];
	int n = 0;
	for(int i = 0; i <= size; i++)
	{
		entrynode* nextnode = this->hashtable[i];
		while(nextnode)
		{
			entrs[n] = nextnode->entr;
			n++;
			nextnode = nextnode->fore;
		}
	}
	return entrs;
}

/**
 * Read the function name
 */ 
unsigned int Table::getnumEntries() const
{
	return numOfentries;
}

/**
 * Hash function used for the hashtable. 
 * returns a value of [0, size of the hashtable]
 */
unsigned int Table::hash(unsigned int key) const
{
	return (unsigned int)((key*4363) % (this->size + 1));
}

/**
 *  Overrides the << operator allowing you to print out the elements of the hashtable in increasing order of Entry key value
 */
std::ostream& operator<< (std::ostream &out, const Table &t)
{
	Entry* entrs = t.getEntry();
	unsigned int n = t.getnumEntries();
	qsort (entrs, n, sizeof(Entry), compare);
	for(unsigned int i = 0; i < n; i++)
	{
		unsigned int key = entrs[i].get_key();
		out << key << ": " << t.get(key) <<"\n";
	}
	return out;
}
