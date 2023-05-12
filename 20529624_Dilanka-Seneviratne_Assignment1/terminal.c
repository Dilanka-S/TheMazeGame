/*
Student Name    : D.V.Seneviratne
Curtin ID       : 20529624
SLIIT ID        : IT21120916
UNIT            : COMP 1000
ASSIGNMENT NAME : ASSIGNMENT 1 - YEAR 1 SEMESTER 2

File Name       : terminal.c
Description     : Contains the functions;
                  disableBuffer() : To disbale the buffer and get user inputs
                  without the requirement of having to play enter to make a much
                  more fluid experience
                  clear() : To clear the terminal screen through the system library function
                  enableBuffer() : To enable the buffer again if you want to do any other work in the same terminal
                  so that the enter button option would be working
*/
#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include"terminal.h"

void disableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}
void clear(void){
    system("clear");
}
void enableBuffer()
{
    struct termios mode;

    tcgetattr(0, &mode);
    mode.c_lflag |= (ECHO | ICANON);
    tcsetattr(0, TCSANOW, &mode);
}
