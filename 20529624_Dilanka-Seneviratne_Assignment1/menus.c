/*
Student Name    : D.V.Seneviratne
Curtin ID       : 20529624
SLIIT ID        : IT21120916
UNIT            : COMP 1000
ASSIGNMENT NAME : ASSIGNMENT 1 - YEAR 1 SEMESTER 2

File Name       : menus.c
Description     : Contains the functions;
                  welcomeMessage() : A custom welcome message that will be displayed 
                  once the user starts playing the game
                  exitDisplay() : A custom exit message that will be displayed once
                  the user reached the goal and wins the game

                  Also
                  There are some other functions here that have been commented out 
                  that were a few of my experiments trying to make the user inteface
                  more pleasing to the user :)
*/
#include<stdio.h>
#include"terminal.h"

void welcomeMessage(){
    printf("*================================*\n");
    printf("|            WELCOME             |\n");
    printf("|              TO                |\n");
    printf("|          THE MAZE GAME         |\n");
    printf("*================================*\n");
}
/*
void menu(){
    int menuSelection=0;
    printf("\nKindly make a selection from the below mentioned menu options\n");
    printf("(1) Instructions regarding the controls of the game\n");
    printf("(2) Play THE MAZE GAME\n");
    printf("(3) Exit\n");
    printf("Your selection : ");
    scanf("%d",&menuSelection);
    switch (menuSelection)
    {
    case 1:
        instructions();
        break;
    default:
        printf("Incorrect Menu Selection please try again");
        break;
    }
    printf("\nThe selection was %d",menuSelection);
}
*/
/*
void instructions(){
    printf("\nThe instructions of how the game works are as follows\n");
    printf("Enter ""w"" to move upwards ""^""\n");
    printf("Enter ""a"" to move left ""<""\n");
    printf("Enter ""d"" to move right "">""\n");
    printf("Enter ""s"" to move down ""v""\n");
    printf("Keep in mind that you cannot cross the walls which are marked as ""o""\n");
    printf("or cross borders which are marked as ""|""\n");
    printf("\nWould you like to play the game now?");
}
*/
void exitDisplay(){
    printf("*================================*\n");
    printf("|            THANK YOU           |\n");
    printf("|           FOR PLAYING          |\n");
    printf("|          THE MAZE GAME         |\n");
    printf("|                                |\n");
    printf("|   Created by D.V.Seneviratne   |\n");
    printf("*================================*\n");

}
/*
void toTheGame(){
    int selection;
    printf("Do you want full visibiility?\n(1) Yes\n(2) No\n");
    scanf("%d",selection);
    switch(selection){
        case 1 :
            disableBuffer(); 
            system("./maze 0");
            enableBuffer();
            break;
        case 2 :
            printf("Enter the visibility you want : 2,3,4,or 5");
            scanf(" %d",&selection);
            break;
        default : 
            printf("Incorrect menu selection\n");
            break;
    }
}
*/
/*
void visbility(int visibility){
    switch (visibility)
    {
    case 2:
        disableBuffer(); 
        system("./maze 2");
        enableBuffer();        
        break;
    case 3:
        disableBuffer(); 
        system("./maze 3");
        enableBuffer();        
        break;    
    default:
        printf("/n");
        break;
    }

}
*/
