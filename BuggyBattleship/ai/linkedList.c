#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

List* newList()
{
   return calloc(1, sizeof(List));
}

void listAdd(List* list, void* val)
{
   Node* n = calloc(1, sizeof(Node));
   n->value = val;
   n->last = list->tail;
   if (list->tail != NULL)
   {
      list->tail = list->tail->next = n;
   }
   else
   {
      list->head = list->tail =  n;
   }
   list->size++;
}

void printList(List* list, void (*print)(const void*))
{
   Node* n;
   if (!list)
   {
      return;
   }
   n = list->head;
   printf("[");
   while (n && n != list->tail)
   {
      print(n->value);
      printf(", ");
      n = n->next;
   }
   if (list->tail)
   {
      print(n->value);
   }
   printf("]\n");   
}

static void addBefore(List* list, Node* n, Node* elm)
{
   if ((n->next = elm))
   {
      if ((n->last = elm->last))
      {
         n->last->next = n;
      }
      else
      {
         list->head = n;
      }
      elm->last = n;
   }
   else
   {
      if (!(n->last = list->tail))
      {
         list->head = n;
      }
      else
      {
         list->tail->next = n;
      }
      list->tail = n;
   }
}

void listAddIndex(List* list, void* val, int index)
{
   Node* n = calloc(1, sizeof(Node));
   Node* elm = list->head;
   n->value = val;
   while (elm && index-- > 0)
   {
      elm = elm->next;
   }
   addBefore(list, n, elm);
   list->size++;
}

void sortList(List* list, int (*cmp)(const void*, const void*))
{
   List* sorted = newList();
   Node* n = list->head;
   Node* elm;
   Node* next;
   while (n)
   {
      next = n->next;
      elm = sorted->head;
      while (elm && cmp(n->value, elm->value) > 0)
      {
         elm = elm->next;
      }
      addBefore(sorted, n, elm);
      n = next;
   }
   *list = *sorted;
   free(sorted);
}

int listContains(List* list, void* val, int (*cmp)(const void*, const void*))
{
   Node* n = list->head;
   while (n)
   {
      if (!cmp(n->value, val))
      {
         return 1;
      }
   }
   return 0;
}

void listAddSorted(List* list, void* val, int (*cmp)(const void*, const void*))
{
   Node* n = calloc(1, sizeof(Node));
   Node* elm = list->head;
   n->value = val;
   while (elm && cmp(val, elm->value) > 0)
   {
      elm = elm->next;
   }
   addBefore(list, n, elm);
   list->size++;
}

void* listGet(List* list, unsigned int index)
{
   Node* n = list->head;
   while (n && index-- > 0)
   {
      n = n->next;
   }
   return n? n->value : NULL;
}

void* listDelete(List* list, unsigned int index)
{
   Node* n = list->head;
   void* res;
   if (index >= list->size)
   {
      return NULL;
   }
   if (index == --list->size)
   {
      n = list->tail;
      res = n->value;
      if ((list->tail = n->last) != NULL)
      {
         list->tail->next = NULL;
      }
      else
      {
         list->head = NULL;
      }
      free(n);
      return res;
   }
   else if (index == 0)
   {
      res = n->value;
      list->head = n->next;
      list->head->last = NULL;
      free(n);
      return res;
   }
   while (index-- > 0)
   {
      n = n->next;
   }
   n->last->next = n->next;
   res = n->value;
   free(n);
   return res;
}

void deleteList(List* list)
{
   Node* n;
   Node* tmp;
   if (!list)
   {
      return;
   }
   n = list->head;
   while (n)
   {
      tmp = n;
      n = n->next;
      free(tmp->value);
      free(tmp);
   }
   free(list);
}
