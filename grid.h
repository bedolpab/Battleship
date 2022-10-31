#ifndef GRID_H
#define GRID_H

void initArray(int array[], int size);
void printGrid(int array[], int size, int rows);
int atDiagonalTopLeft(int array[], int columns, int index);
int atDiagonalTopRight(int array[], int columns, int index); 
int atDiagonalBottomLeft(int array[], int columns, int index);
int atDiagonalBottomRight(int array[], int columns, int index); 
int atTop(int array[], int columns, int index);
int atBottom(int array[], int columns, int index); 
int atLeft(int array[], int columns, int index);
int atRight(int array[], int columns, int index); 


#endif