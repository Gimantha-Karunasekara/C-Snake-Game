#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "loadSnake.h"

/*read method - reads the method and assigns values to parameters*/
void read(char* fileName,LinkedList* snake, int* rows, int* columns)
{
    FILE* f;
    f = fopen(fileName,"r");
    if (f == NULL)
    {
        perror("Error file can not be opend");
    }
    else
    {
        int lineNum = 0;
        char line[SIZE];
        while (fgets(line,SIZE,f))
        {
            int i = 0, col = 0 , row = 0;
            char character;
            char* strSplit;

            strSplit = strtok(line, " ");
            while (strSplit != NULL)
            {
                if (lineNum == 0)
                {
                    switch (i)
                    {
                    case 0:
                        *rows = atoi(strSplit); /*assign number of rwos*/
                        break;
                    case 1:
                        *columns = atoi(strSplit); /*assign number of columns*/
                        break;
                    
                    default:
                        break;
                    }
                }
                else
                {
                    switch (i)
                    {
                    case 0:
                        row = atoi(strSplit);
                        break;
                    case 1:
                        col = atoi(strSplit);
                        break;
                    case 2:
                        character = *strSplit;    
                        break;
                    default:
                        break;
                    }
                }
                strSplit = strtok(NULL," ");
                i++;
            }
            if (lineNum != 0)
            {
                insertFirst(snake, col+1,row+1,character); /*insert snake node values*/
            }   
            lineNum++;
            
        }
        if(ferror(f)) 
        {
            perror("Error in file reading !'\n");
        } 
        fclose(f);
    }
}
