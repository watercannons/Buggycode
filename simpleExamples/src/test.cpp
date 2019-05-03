#include <iostream>
#include <assert.h>
#include "linkedList.h"
 

using namespace std;



void createDestroyList() {
    cout << "Check that we can create and destroy a list" << endl;

    List<int>* li = new List<int>();
    delete li;
}

void insertIntoList() {
    cout << "Check that insertion works" << endl;

    List<int>* li = new List<int>();
    li->insert(1, li->zeroth());
    li->insert(2, li->zeroth());
    assert(li->size() == 2);

    delete li;
}

void retrieveElements() {
    cout << "Check that we can get the correct elements out of the list" << endl;

    List<int>* li = new List<int>();
    li->insert(1, li->zeroth());
    li->insert(2, li->zeroth());
    assert(li->size() == 2);
    
    ListItr<int> liIter = li->first();
    assert( liIter.retrieve() == 2);
    assert(!li->isEmpty());

    liIter.advance();
    assert(liIter.retrieve() == 1);
    assert(!li->isEmpty());

    delete li;
}

void removeElements() {
    cout << "Check that we can remove elements" << endl;

    List<int>* li = new List<int>();
     
    for (int i = 99; i >= 0; --i) {
        li->insert(i, li->zeroth());
	ListItr<int> fst = li->first();
    }

    // remove from the end of the list
    ListItr<int> lastIt = li->findPrevious(99);
    li->remove(99);
    assert(li->size() == 99);
    assert(li->find(99).isPastEnd());

    // remove from the middle of the list
    ListItr<int> midIt = li->findPrevious(50);
    li->remove(50);
    assert(li->size() == 98);
    assert(li->find(50).isPastEnd());

    // remove from the beginning of the list
    li->remove(0);
    assert(li->size() == 97);
    assert(li->find(0).isPastEnd());

    // check we can't remove something twice
    li->remove(0);
    assert(li->size() == 97);
    assert(li->find(0).isPastEnd());
	
    delete li;
}


void removeAfterElements() {
    cout << "Check that we can remove elements after a position" << endl;

    List<int>* li = new List<int>();
     
    for (int i = 99; i >= 0; --i) {
        li->insert(i, li->zeroth());
	ListItr<int> fst = li->first();
    }

    // remove from the end of the list
    ListItr<int> lastIt = li->findPrevious(99);
    li->removeAfter(lastIt);
    assert(li->size() == 99);
    assert(li->find(99).isPastEnd());

    // remove from the middle of the list
    ListItr<int> midIt = li->findPrevious(50);
    li->removeAfter(midIt);
    assert(li->size() == 98);
    assert(li->find(50).isPastEnd());

    // remove from the beginning of the list
    li->removeAfter(li->zeroth());
    assert(li->size() == 97);
    assert(li->find(0).isPastEnd());

    delete li;
}



void addManyToFrontList() {
    cout << "Check that we can add 100 numbers to the front of the list" << endl;
    
    List<int>* li = new List<int>();
    for (int i = 0; i < 100; ++i) {
        li->insert(i, li->zeroth());
	ListItr<int> fst = li->first();
	assert(fst.retrieve() == i);
	assert(li->size() == i+1);
    }

    delete li;
}

void addManyToBackList() {
    cout << "Check that we can add 100 numbers to the back of the list" << endl;
    
    List<int>* li = new List<int>();

    // add in -1, so that the last element will always be i-1
    li->insert(-1, li->zeroth());
    
    for (int i = 0; i < 100; ++i) {

    // This might not be a good idea.. oh well
    li = nullptr;

	// the current last element in the list is i-1, so get an iterator
	// which points to this value so we can insert i after it.
        ListItr<int> liEnd = li->find(i-1);

	li->insert(i, liEnd);

	liEnd = li->find(i-1); // reset liEnd in case it was invalidated

	liEnd.advance();
	assert(liEnd.retrieve() == i);
    }

    delete li;
}

void popMany() {
    cout << "Check that we can pop 100 numbers off the list" << endl;
    
    List<int>* li = new List<int>();
    for (int i = 0; i < 100; ++i) {
        li->insert(i, li->zeroth());
	ListItr<int> fst = li->first();
	assert(fst.retrieve() == i);
    }

    for (int i = 99; i >= 0; --i) {
        int justPopped = li->pop();
	assert(justPopped == i);
    }

    delete li;
}


void checkFront() {

    List<int>* li = new List<int>();
    
    assert(li->front() == NULL);

    li->push(1);
    assert(li->front() == 1);

    li->insert(2, li->first());
    assert(li->front() == 1);

    li->insert(0, li->zeroth());
    assert(li->front() == 0);

    li->remove(0);
    assert(li->front() == 1);
    
}

//void fuzzTest()


int main(int argc, char *argv[])
{
    createDestroyList();
    insertIntoList();
    retrieveElements();
    popMany();
    checkFront();
    removeElements();
    removeAfterElements();

    addManyToFrontList();
    addManyToBackList();

    
    
    cout << "Done" << endl;
    return 0;
}
