#ifndef MAIN_H
#define MAIN_H

int initMessage(int foodGoal, int rows, int columns, int length);
void message(int gameover, int invalidMove);
void shuffleSnake(char* move, int* snake_length, char* updateChar , char* snakeChar);
void initRandom();
int randomGen(int low, int high);
void generateFood(LinkedList* snake, int* foodCords ,int row_map,int col_map);
void read(char* fileName,LinkedList* snake, int* rows, int* columns);

#endif
