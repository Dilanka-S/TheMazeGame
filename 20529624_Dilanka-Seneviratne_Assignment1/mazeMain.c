/*
Student Name    : D.V.Seneviratne
Curtin ID       : 20529624
SLIIT ID        : IT21120916
UNIT            : COMP 1000
ASSIGNMENT NAME : ASSIGNMENT 1 - YEAR 1 SEMESTER 2

File Name       : mazeMain.c
Description     : main function containing the conditional compilation 
                  and passing user's preferred visbility to the mapReader() function 
*/
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "controls.h"
#include "mapIO.h"
#include "menus.h"

/*main method for passing the visbility as well as to enable the DARK feature for conditional compilation*/
int main(int args, char* argv[]){
    int visibility;
    if(args!=2){
        /*To notify the user regarding any errors related to the argument*/
        printf("An error has occurred, please try again with a valid argument!\n");
    }else{
        #ifdef DARK
        visibility = 0;
        visibility = atoi(argv[1]);
        /*Checking is the user runs the maze executable with a valid visibility level that is a non zero integer */
        if(visibility<0){
            printf("An error has occurred, please enter a valid visibility amount!\n For example : ./maze 0\n");
        }else{
            mapReader(visibility);
        }
        #endif
    }
    return 0;
}