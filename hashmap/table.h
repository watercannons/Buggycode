#ifndef TABLE_H
#define TABLE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "entry.h"
#include <pthread.h>

using namespace std;
class Table
{
	public:
		Table(unsigned int max_entries = 100);
		~Table();
		void put(unsigned int key, std::string data);
		void put(Entry e);
		std::string get(unsigned int key) const;
		bool remove(unsigned int key);
		Entry* getEntry()const;
		unsigned int getnumEntries() const;
	private:
		unsigned int hash(unsigned int key) const;
		class entrynode
		{
			public:
			entrynode(Entry e, entrynode* f = NULL)
			{
				entr = e;
				fore = f;
			}
			Entry entr;
			entrynode* fore;
		};
		entrynode** hashtable;
		pthread_mutex_t *locks;
		unsigned int size;
		unsigned int numOfentries;
};
std::ostream& operator<< (std::ostream &out, const Table &t);
#endif
