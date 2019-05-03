#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node
{
   struct node* next;
   struct node* last;
   void* value;
} Node;

typedef struct
{
   unsigned int size;
   Node* head;
   Node* tail;
} List;

List* newList(void);

void listAdd(List* list, void* val);

void listAddIndex(List* list, void* val, int index);

void listAddSorted(List* list, void* val, int (*cmp)(const void*, const void*));

void sortList(List* list, int (*cmp)(const void*, const void*));

void* listGet(List* list, unsigned int index);

void* listDelete(List* list, unsigned int index);

void deleteList(List* list);

void printList(List* list, void (*print)(const void*));

int listContains(List* list, void* val, int (*cmp)(const void*, const void*));

#endif
