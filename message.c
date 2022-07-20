#include <stdio.h>

void message(int gameover, int invalidMove)
{
    if (gameover == 1)
    {
        printf("You lose !\n");
    }
    else if (gameover == 2)
    {
        printf("You won !\n");
    }
    else if (gameover == 3)
    {
        printf("Quit\n");
    }
    else if (invalidMove == 1)
    {
        printf("Cant go outside the map !\n");
    }
    else if (invalidMove == 2)
    {
        printf("Can't go backward !\n");
    }
    else if(invalidMove == 3)
    {
        printf("Invalid key\n");
    }
    
}

int initMessage(int foodGoal, int rows, int columns, int length)
{
    int inValid = 0;
    
    if (rows == 0 && columns == 0 && length == 0)
    {
        printf("Parameters empty !");
        inValid = 1;  
    }
    else if (rows < 5 || columns < 5)
    {
        printf("No. of Columns and Rows should be more than 5");
        inValid = 1;
    }
    else if (length < 3)
    {
        printf("Minimum snake length is 3 ");
        inValid = 1;
    }
    else if (foodGoal < 2)
    {
        printf("Minimum food amount to win is 2 ");
        inValid = 1;
    }
    
    
    return inValid;

}
