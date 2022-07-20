#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void insertFirst(LinkedList* list,int inColumn,int inRow, char inCharacter) 
{
    LinkedListNode* newNode;
    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    
    newNode->column = inColumn;
    newNode->row = inRow;
    newNode->charcter=inCharacter;
    newNode->next = list->head;
    newNode->prev = NULL;

    if (list->head != NULL)
    {
        list->head->prev = newNode;
    }
    else
    {
       list->tail = newNode;
    }
    list->head = newNode;
}

void insertLast(LinkedList* list,int inColumn,int inRow, char inCharacter)
{
    LinkedListNode* newNode;
    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    
    newNode->column = inColumn;
    newNode->row = inRow;
    newNode->charcter=inCharacter;
    newNode->next = NULL;
    if (list->head == NULL)
    {
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        LinkedListNode* current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        list->tail = newNode;
    }
    
}

int getLength(LinkedList* list)
{
    int len = 0;
    LinkedListNode* current;
    current = list->head;
    while(current != NULL) 
    {
        len++;
        current = current->next;
    }
    return len;
}

void freeLinkedList(LinkedList* list) 
{
    LinkedListNode *node, *nextNode;
    node = list->head;
    while(node != NULL) 
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(list);
}
