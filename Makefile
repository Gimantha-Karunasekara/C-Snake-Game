CC = gcc
CFLAGS = -g -Wall -pedantic -ansi 
OBJ = snakeGame.o food.o terminal.o random.o message.o loadSnake.o linkedList.o
EXEC = snake

ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE
UNBEATABLE: clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

snakeGame.o : snakeGame.c main.h 
	$(CC) $(CFLAGS) -c snakeGame.c 

food.o : food.c food.h 
	$(CC) $(CFLAGS) -c food.c 

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c 

random.o : random.c random.h
	$(CC) $(CFLAGS) -c random.c 

message.o : message.c
	$(CC) $(CFLAGS) -c message.c 

loadSnake.o : loadSnake.c loadSnake.h 
	$(CC) $(CFLAGS) -c loadSnake.c 

linkedList.o : linkedList.c 
	$(CC) $(CFLAGS) -c linkedList.c 

clean: 
	rm -f $(EXEC) $(OBJ)



