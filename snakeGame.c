#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "main.h"
#include "terminal.h"

int i = 0,j = 0,skipPrint = 0,gameover = 0,invalidMove = 0, override = 0, foodInMap = 0, foodEaten = 0, extend = 0,foodGoal = 0;
char inp, updateChar = '-';
int row_map = 0,snake_length = 0,col_map = 0;
int* foodCords;

LinkedList* snake;
LinkedList* snakeTemp;


void draw()
{
    LinkedListNode* current;
    LinkedListNode* current2;
                    
    system("clear");

    if (foodInMap != 1) /* Generate food if not available in the map */
    {
        generateFood(snake, foodCords, row_map , col_map);
        foodInMap = 1;
    }
    if (snake->head->row == foodCords[0] && snake->head->column == foodCords[1]) /*check if the snake(head) have eaten the food */ 
    {
        foodEaten++;
        foodInMap = 0;
        skipPrint = 1;
        if (foodEaten == foodGoal) /*check if the food goal is achieved*/
        {
            gameover = 2;
        }
        extend = 1;
    }

    for (i = 0; i <= row_map + 1; i++) 
    {
        for (j = 0; j <= col_map + 1; j++) 
        {
            skipPrint = -1;

            if ((foodCords[0] == i && foodCords[1] == j) && foodInMap == 1) /* check if the currunt coordinate is the coordinate of food */
            {
                printf("@");
                skipPrint = 1;
            }
            
            current = snake->head;

            while(current != NULL) /*iterate through the snake */
            {
                int skipSnakePrint = 0;
                if ((current->row == i && current->column == j) && current != snake->head) 
                {
                    
                    current2 = current->prev;
                    while(current2 != NULL)
                    {
                        #ifdef UNBEATABLE
                        if(current->column == current2->column && current->row == current2->row) /* if a snake body part already exists do nothing*/
                        {
                            skipSnakePrint = 1;
                            skipPrint = 1;
                            override = 1;
                        }
                        #endif

                        if((current->column == current2->column && current->row == current2->row) && override == 0) /* if a snake body part already exists you lose */
                        {
                            skipSnakePrint = 1;
                            skipPrint = 1;
                            gameover = 1;
                        } 
                        current2 = current2->prev;
                    }   
                }
                
                
                if ((current->row == i && current->column == j) && skipSnakePrint == 0) /* check if the current coordinates is a part of the snake*/
                {
                    skipPrint = 1;
                    printf("%c" , current->charcter);
                }
                current = current->next;
            }
            

            if ((i == 0 ||  j == 0 ||  j == col_map + 1 || i == row_map + 1) && skipPrint < 0) /* check if the current coordinates are the boundary*/
            {
                printf("*");
            }
            else if(skipPrint < 0) /* for everything else print " "*/
                printf(" ");
            
        }
        printf("\n");
    }
    printf("Food eaten %d/%d\n",foodEaten,foodGoal); /*print food goal and progress*/
    message(gameover, invalidMove); /* print message if any */
}


void moveSnake()
{
    int count;
    LinkedListNode*  current;
    LinkedListNode* tempCurrent;
    invalidMove = 0;

    snakeTemp = (LinkedList*)malloc(sizeof(LinkedList));
    snakeTemp->head = NULL;
    snakeTemp->tail = NULL;

    current = snake->head;

    /*make a copy of snake*/
    while (current != NULL)
    {
        insertLast(snakeTemp,current->column,current->row,current->charcter);
        current = current->next;
    }

    disableBuffer();
    scanf(" %c", &inp); /* Get input */
    enableBuffer();

        switch (inp) 
        {
        case 'a': /* for moving left */
            if (snake->head->next->column == snake->head->column - 1) /* check wheather trying to move backwards */
            {
                invalidMove = 2;
            }
            else if (snake->head->column - 1 == 0) /* check wheater trying to move out of the map */
            {
                invalidMove = 1;
            }
             
            else
            {
                current = snake->head;
                tempCurrent = snakeTemp->head;
                snake->head->charcter = '<'; /*change head character*/
                count = 0;
                while (current != NULL)
                {
                    /*change coordinates and characters of the snake*/
                    if (count == 0)
                    {
                        current->next->column = current->column;
                        current->next->row = current->row;
                        current->column--;
                    }
                    else if(current->next != NULL)
                    {
                        current->next->column = tempCurrent->column;
                        current->next->row = tempCurrent->row;
                        current->next->charcter = tempCurrent->charcter;
                    }
                    if (current->next == NULL && extend != 1)
                    {
                        current->charcter = '#';
                    }
                    
                    tempCurrent = tempCurrent->next;
                    current = current->next;
                    count++;
                }
                snake->head->next->charcter = updateChar;
                updateChar = '-'; /* Keep upcoming character for the part next to the head stored */

            }
            break;
        case 's': /* for moving down */
            if (snake->head->next->row == snake->head->row + 1)  /* check wheather trying to move backwards */
            {
                invalidMove = 2;
            }
            else if (snake->head->row + 1 == row_map + 1) /* check wheater trying to move out of the map */
            {
                invalidMove = 1;
            }
            else
            {
                current = snake->head;
                tempCurrent = snakeTemp->head;
                snake->head->charcter = 'v'; /*change head character*/
                count = 0;
                while (current != NULL)
                {
                    /*change coordinates and characters of the snake*/
                    if (count == 0)
                    {
                        current->next->column = current->column;
                        current->next->row = current->row;
                        current->row++;
                        
                    }
                    else if(current->next != NULL)
                    {
                        current->next->column = tempCurrent->column;
                        current->next->row = tempCurrent->row;
                        current->next->charcter = tempCurrent->charcter;
                    }
                    if (current->next == NULL && extend != 1)
                    {
                        current->charcter = '#';
                    }
                    
                    tempCurrent = tempCurrent->next;
                    current = current->next;
                    count++;
                }
                
                snake->head->next->charcter = updateChar;
                updateChar = '|'; /* Keep upcoming character for the part next to the head stored */

            }
            break;
        case 'd': /* for moving right */
            if (snake->head->next->column == snake->head->column + 1)  /* check wheather trying to move backwards */
            {
                invalidMove = 2;
            }
            else if (snake->head->column + 1 == col_map + 1) /* check wheater trying to move out of the map */
            {
                invalidMove = 1;
            }
            else 
            {
                current = snake->head;
                tempCurrent = snakeTemp->head;
                snake->head->charcter = '>'; /*change head character*/
                count = 0;
                while (current != NULL)
                {
                    /*change coordinates and characters of the snake*/
                    if (count == 0)
                    {
                        current->next->column = current->column;
                        current->next->row = current->row;
                        current->column++;
                        
                    }
                    else if(current->next != NULL)
                    {
                        current->next->column = tempCurrent->column;
                        current->next->row = tempCurrent->row;
                        current->next->charcter = tempCurrent->charcter;
                    }
                    if (current->next == NULL && extend != 1)
                    {
                        current->charcter = '#';
                    }
                    
                    tempCurrent = tempCurrent->next;
                    current = current->next;
                    count++;
                }
                snake->head->next->charcter = updateChar;
                updateChar = '-'; /* Keep upcoming character for the part next to the head stored */
            }
            break;
        case 'w': /* for moving up */
            if (snake->head->next->row == snake->head->row - 1)  /* check wheather trying to move backwards */
            {
                invalidMove = 2;
            }
            else if (snake->head->row - 1 == 0) /* check wheater trying to move out of the map */
            {
                invalidMove = 1;
            }
            else
            {
                current = snake->head;
                tempCurrent = snakeTemp->head;
                snake->head->charcter = '^'; /*change head character*/
                count = 0;
                while (current != NULL)
                {
                    /*change coordinates and characters of the snake*/
                    if (count == 0)
                    {
                        current->next->column = current->column;
                        current->next->row = current->row;
                        current->row--;
                        
                    }
                    else if(current->next != NULL)
                    {
                        current->next->column = tempCurrent->column;
                        current->next->row = tempCurrent->row;
                        current->next->charcter = tempCurrent->charcter;
                    }
                    if (current->next == NULL && extend != 1)
                    {
                        current->charcter = '#';
                    }
                    
                    tempCurrent = tempCurrent->next;
                    current = current->next;
                    count++;
                }
                snake->head->next->charcter = updateChar;
                updateChar = '|'; /* Keep upcoming character for the part next to the head stored */
            }
            
            break;
        case 'x':   /* 'x' key to Exit the game */
            gameover = 3;
            break;
        default: /* invalid input */
            invalidMove = 3;
            break;
        }
        if (extend == 1) /*Grow snake if have eaten food*/
        {
            insertLast(snake,snakeTemp->tail->column, snakeTemp->tail->row,'#');
            extend = 0;
        }

        freeLinkedList(snakeTemp); 
}

int main(int argc, char * argv[])
{
   
    if (argc > 3 || argc < 3)
    {
        printf("Too many arguments or too few\nFormat is: ./snake <snake_file_name> <food_amount_to_win>\n");
    }
    else 
    {

        /* Allocating memory*/
        snake = (LinkedList*)malloc(sizeof(LinkedList));
        snake->head = NULL;
        snake->tail = NULL;
        foodCords = (int*)malloc (2 * sizeof(int*));

        /* Read file and initialize cordinates and characters of the snake*/
        read(argv[1],snake, &row_map, &col_map);
        foodGoal = atoi(argv[2]);

        if (initMessage(foodGoal,row_map,col_map,getLength(snake)))
        {
            printf("\nAbort...\n");
        }
        else
        {
            initRandom();
            draw();

            while (gameover == 0)
            {
                moveSnake();
                draw();
            }
        }

        free(foodCords);
        freeLinkedList(snake); 

    }

    return 0;
}
