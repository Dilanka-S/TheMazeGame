#ifndef MAPIO_H
#define MAPIO_H

/*
void getMetadata(int *** metadataTable, int * metadataAmount, int * mapRow, int * mapCol);
*/
void mapReader(int visibility);
void displayMap(char*** mapArray,int rows,int columns,int visibility);
#endif