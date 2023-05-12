/*
Student Name    : D.V.Seneviratne
Curtin ID       : 20529624
SLIIT ID        : IT21120916
UNIT            : COMP 1000
ASSIGNMENT NAME : ASSIGNMENT 1 - YEAR 1 SEMESTER 2

File Name       : mapIO.c
Description     : Contains the functions;
                  mapReader() : To read the metadata from the provided map file
                  and create a string array named mapArray, through a char*** and pass the 
                  values to the game() function
                  displayMap() : To display the mapArray that is modified through the game()
                  function.
*/
#include <stdio.h>
#include <stdlib.h>
#include"map.h"
#include"controls.h"
#include"terminal.h"
#include <string.h>

/*
void getMetadata(int *** metadataTable, int * metadataAmount, int * mapRow, int * mapCol);
*/

/*The map reader function that reads the metadata and information from the map file*/
void mapReader(int visibility){
    int rows;
    int columns;
    int row;
    int col;
    int metadataAmount;
    int** table;
    int winRow;
    int winCol;
    int playerRow;
    int playerCol;
    int wallRow;
    int wallCol;
    char*** mapArray;
    /*Declaration of variables at the beginning of the function to meet C89 coding standards */

    /*Calling the function in the map file to allocate the map infromation into the variables*/
    getMetadata(&table,&metadataAmount,&rows,&columns);
    mapArray = (char***)malloc(sizeof(char**)*rows);

    /*printf("Table %d metadataamt %d row %d cols %d \n",table,metadataAmount,rows,columns);*/
    /*printf("table smthn %d \n",table[0][0]);*/
    for(row=0;row<rows;row++){
        mapArray[row] = (char**)malloc(sizeof(char*)*columns);
    }
    for(row=0;row<rows;row++){
        for(col=0;col<columns;col++){
            mapArray[row][col] = " ";
        }
    }
    /*Filling the map border*/ 
    mapArray[0][0] = "#";
    mapArray[rows-1][0] = "#";
    mapArray[0][columns-1] = "#";
    mapArray[rows-1][columns-1] = "#";
    for(row=1;row<rows-1;row++){
        mapArray[row][0] = "|";
    }
    for(row=1;row<rows-1;row++){
        mapArray[row][columns-1] = "|";
    }
    for(col=1;col<columns-1;col++){
        mapArray[0][col] = "=";
    }
    for(col=1;col<columns-1;col++){
        mapArray[rows-1][col] = "=";
    }
    /*Allocating the map obstacles*/
    for(row=2;row<metadataAmount;row++){
        wallRow=table[row][0];
        wallCol=table[row][1];
        mapArray[wallRow][wallCol] = "o";
    }
    /*Allocating the win location */ 
    winRow = table[1][0];
    winCol = table[1][1];
    mapArray[winRow][winCol] = "x";
    /*Allocating the players's starting location */
    playerRow = table[0][0];
    playerCol = table[0][1];
    mapArray[playerRow][playerCol]= "^";

    /*Passing the values to the game function */
    game(mapArray,rows,columns,winRow,winCol,playerRow,playerCol,visibility);
    /*Freeing the manually allocated space (malloc) */
    free(table);
    for(row=0;row<rows;row++){
        free(mapArray[row]);
    }
    table=NULL;
    mapArray=NULL;
}
/*Display method to display the mapArray data */
void displayMap(char*** mapArray,int rows,int columns,int visibility){
    int row;
    int column;
    int row2;
    int column2;

    for(row=0;row<rows;row++){
        for(column=0;column<columns;column++){
            if(visibility==0){
                printf("%s",(mapArray[row][column]));
            }else if ((strcmp(mapArray[row][column],"<")== 0) || (strcmp(mapArray[row][column],">")== 0) || (strcmp(mapArray[row][column],"^")== 0) || (strcmp(mapArray[row][column],"v") == 0)){
                for(row2=row-visibility;row2<=(row+visibility);row2++){
                    for(column2=column-visibility;column2<=(column+visibility);column2++){
                        if((row2 >=0)&&(row2<=(rows-1))&&(column2>=0)&&(column2<=(columns-1))){
                            printf("%s",mapArray[row2][column2]);
                        }
                    }
                    printf("\n");
                }
            }

        }
        printf("\n");
    }    
}
