#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    int column;
    int row;
    char charcter;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;
    
}LinkedListNode;

typedef struct 
{
    LinkedListNode* head;
    LinkedListNode* tail;
}LinkedList;

void insertFirst(LinkedList* list,int inColumn,int inRow, char inCharacter);
void insertLast(LinkedList* list,int inColumn,int inRow, char inCharacter);
int getLength(LinkedList* list);
void freeLinkedList(LinkedList* list);

#endif
