#ifndef FOOD_H
#define FOOD_H

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


int randomGen(int low, int high);

#endif
