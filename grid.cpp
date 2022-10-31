#include "grid.h"
#include <iostream>
#include <random>
#include <string>

using namespace std;
void initArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }
}

void printGrid(int array[], int size, int rows) {
  for (int i = 1; i <= size; i++) {
    if (i % rows == 0) {
      std::cout << array[i - 1] << std::endl;
    } else {
      std::cout << array[i - 1] << " ";
    }
  }
}

int atDiagonalTopLeft(int array[], int columns, int index) {
  return array[index - 1 - columns - 1];
}
int atDiagonalTopRight(int array[], int columns, int index) {
  return array[index - 1 - columns + 1];
}
int atDiagonalBottomLeft(int array[], int columns, int index) {
  return array[index - 1 + columns - 1];
}
int atDiagonalBottomRight(int array[], int columns, int index) {
  return array[index - 1 + columns + 1];
}
int atTop(int array[], int columns, int index) {
  return array[index - 1 - columns];
}
int atBottom(int array[], int columns, int index) {
  return array[index - 1 + columns];
}
int atLeft(int array[], int columns, int index) { 
  return array[index - 1 - 1]; 
  }
int atRight(int array[], int columns, int index) {
  return array[index - 1 + 1];
}
