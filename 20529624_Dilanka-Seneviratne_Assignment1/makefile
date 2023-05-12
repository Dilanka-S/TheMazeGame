CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = mazeMain.o map.o mapIO.o controls.o terminal.o menus.o
EXEC = maze

ifdef DARK
CFLAGS += -D DARK
DARK : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

mazeMain.o : mazeMain.c map.h mapIO.h controls.h mapIO.h
	$(CC) $(CFLAGS) mazeMain.c -c 
map.o : map.c map.h 
	$(CC) $(CFLAGS) map.c -c 
mapIO.o : mapIO.c map.h controls.h terminal.h mapIO.h
	$(CC) $(CFLAGS) mapIO.c -c 
controls.o : controls.c controls.h mapIO.h terminal.h menus.h
	$(CC) $(CFLAGS) controls.c -c 
menus.o : menus.c terminal.h
	$(CC) $(CFLAGS) menus.c -c 	
terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c 
	
clean :
	rm -f $(EXEC) $(OBJ)
