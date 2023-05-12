/*
Student Name    : D.V.Seneviratne
Curtin ID       : 20529624
SLIIT ID        : IT21120916
UNIT            : COMP 1000
ASSIGNMENT NAME : ASSIGNMENT 1 - YEAR 1 SEMESTER 2

File Name       : controls.c
Description     : Contains the functions;
                  direction() : To convert the user input char value into an integer for further convinience
                  win() : To check the win status of the player by comparing the current 
                  player location with the pre allocated win location 
                  game() : The function that contains the logical aspect of the game
                  in regards to player controls and movement.
*/
#include <stdio.h>
#include <stdlib.h>
#include "mapIO.h"
#include "menus.h"
#include "terminal.h"
#include <string.h>

int direction(char input){
    int output;
    switch (input){
    case 'w':
        output = 1;
        break;
    case 'a':
        output = 2;
        break;
    case 'd' : 
        output = 3;
        break;
    case 's' : 
        output = 4;
        break;
    default:
        output = 0;
        break;
    }
    return output;
}
int win(char***mapArray,int row,int col,int winRow,int winCol){
    int winStatus;
    if(mapArray[row][col]==mapArray[winRow][winCol]){
        winStatus=1;
    }else{
        winStatus=0;
    }
    return winStatus;
}

void game(char*** mapArray,int rows,int columns,int winRow,int winCol,int playerRow,int playerCol,int visibility){
    int row;
    int col;
    char input;
    int output;
    /*A custom welcome message that is displayed at the begining of the game */
    welcomeMessage();
    printf("\n");
    displayMap(mapArray,rows,columns,visibility);
    for(row=0;row<rows;row++){
        for(col=0;col<columns;col++){
            while(win(mapArray,playerRow,playerCol,winRow,winCol)==0){
                disableBuffer();
                scanf("%c",&input);
                output = direction(input);
                /*Switch case statement to accomodate to the variations of the controls given by the player */
                switch(output){
                    case  1:
                        /*To checkthe next space that the player is intending to move is a free space */
                        if(strcmp(mapArray[playerRow-1][playerCol]," ")==0){
                            mapArray[playerRow-1][playerCol] = "^";
                            mapArray[playerRow][playerCol] = " ";
                            playerRow = playerRow-1;
                            printf("up1\n");
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                        /*To check if the next move is the goal*/
                        }else if (win(mapArray,playerRow-1,playerCol,winRow,winCol)==1){
                            mapArray[playerRow-1][playerCol] = "^";
                            printf("\n\n         *** YOU WIN ! ***   \n\n");
                            /*A custom exit message after the play has won the maze game by reaching the goal */
                            exitDisplay();
                            printf("\n");
                        /*To display the map again in case the plaer tries to hit a border or an obstacle */
                        }else{
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                            printf("\noops! You hit a wall! Try again! \n");
                        }
                        break;
                    case 2 :
                        if(strcmp(mapArray[playerRow][playerCol-1]," ")==0){
                            mapArray[playerRow][playerCol-1] = "<";
                            mapArray[playerRow][playerCol] = " ";
                            playerCol = playerCol-1;
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                        }else if (win(mapArray,playerRow,playerCol-1,winRow,winCol)==1){
                            mapArray[playerRow-1][playerCol] = "<";
                            printf("\n\n         *** YOU WIN ! ***   \n\n");
                            exitDisplay();
                            printf("\n");
                        }else{
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                            printf("\noops! You hit a wall! Try again! \n");
                        }
                        break;
                    case 3 :
                        if(strcmp(mapArray[playerRow][playerCol+1]," ")==0){
                            mapArray[playerRow][playerCol+1] = ">";
                            mapArray[playerRow][playerCol] = " ";
                            playerCol = playerCol+1;
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                        }else if (win(mapArray,playerRow,playerCol+1,winRow,winCol)==1){
                            mapArray[playerRow+1][playerCol] = ">";
                            printf("\n\n         *** YOU WIN ! ***   \n\n");
                            exitDisplay();
                            printf("\n");
                        }else{
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                            printf("\noops! You hit a wall! Try again! \n");
                        }
                        break;                        
                    case 4 :
                        if(strcmp(mapArray[playerRow+1][playerCol]," ")==0){
                            mapArray[playerRow+1][playerCol] = "v";
                            mapArray[playerRow][playerCol] = " ";
                            playerRow = playerRow+1;
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                        }else if (win(mapArray,playerRow+1,playerCol,winRow,winCol)==1){
                            mapArray[playerRow+1][playerCol] = "v";
                            printf("\n\n         *** YOU WIN ! ***   \n\n");
                            exitDisplay();
                            printf("\n");
                        }else{
                            clear();
                            displayMap(mapArray,rows,columns,visibility);
                            printf("\noops! You hit a wall! Try again! \n");
                        }
                        break;
                    case 0 :
                        printf("Incorrect input for controls ! \n");
                        clear();
                        displayMap(mapArray,rows,columns,visibility);
                        break;
                    default:
                        printf("Try again");
                        clear();
                        displayMap(mapArray,rows,columns,visibility);
                        break;                                    
                }
                enableBuffer();                
            }
        }
    }

}
