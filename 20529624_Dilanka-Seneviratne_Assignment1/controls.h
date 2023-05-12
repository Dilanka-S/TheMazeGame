#ifndef CONTROLS_H
#define CONTROLS_H

int direction(char input);
int win(char***mapArray,int row,int col,int winRow,int winCol);
void game(char*** mapArray,int rows,int columns,int winRow,int winCol,int playerRow,int playerCol,int visibility);
#endif