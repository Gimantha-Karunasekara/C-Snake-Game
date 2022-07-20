#include <stdio.h>
#include "food.h"


int repeat = 1, r = 0;

void generateFood(LinkedList* snake, int* foodCords ,int row_map,int col_map)
{
    LinkedListNode* current;

    repeat = 1;
    while (repeat == 1)
    {
        foodCords[0] = randomGen(1, row_map); /* Generate random coordinates for the food location */
        foodCords[1] = randomGen(1, col_map);
        repeat = 0;
        current = snake->head;

        while (current != NULL)
        {
            if(current->row == foodCords[0] && current->column == foodCords[1])  /* check wheather the food overlaps with the snake */
            {
                repeat = 1;
            }
            current = current->next;
        }
        
       
    }
    
    
}


