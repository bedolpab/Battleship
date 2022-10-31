#include "grid.h"
#include "util.h"
#include <iostream>
#include <random>
#include <string>

#define COLUMNS 16
#define ROWS 16
#define MAX_SHIPS 10
#define MAX_SHIPS_PER_ROW 1
#define SHIP 1
#define EMPTY 1

using namespace std;

int main() {
  // Define grid
  int grid[COLUMNS * ROWS];
  const int SIZE = (sizeof(grid) / sizeof(grid[0]));

  // Tracking vars
  int TOTAL_SHIPS = 0;
  int SHIP_PER_ROW = 0;

  // seed random generator
  srand(time(NULL));

  info();

  // initialize all values
  initArray(grid, SIZE);

  // Create grid
  for (int i = 1; i <= SIZE; i++) {
    if (TOTAL_SHIPS != MAX_SHIPS) {
      int random = rand() & 1;

      // Per row (not including final column)
      if (i % ROWS > 0) {
        if (SHIP_PER_ROW < MAX_SHIPS_PER_ROW) {
          grid[i - 1] = random;
          if (random == 1) {
            SHIP_PER_ROW++;
            TOTAL_SHIPS++;
          }
        } else {
          grid[i - 1] = 0;
        }
      }

      // Fill final column
      if (i % ROWS == 0) {
        if (SHIP_PER_ROW < MAX_SHIPS_PER_ROW) {
          grid[i - 1] = random;
          if (random == 1) {
            SHIP_PER_ROW++;
            TOTAL_SHIPS++;
          }
        } else {
          grid[i - 1] = 0;
        }
        SHIP_PER_ROW = 0;
      }
    }
  }

  // Print grid
  printGrid(grid, SIZE, ROWS);

  // Scanner
  for (int i = 1; i <= SIZE; i++) {
    // Check top row
    if (i <= COLUMNS) {
      // Check top left corner
      if (i == 1) {
        if (grid[i - 1] == SHIP) {
          hit(i);
        } else if (atBottom(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalBottomRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else {
          miss(i);
        }
      } 
      // Check top right corner
      else if (i == COLUMNS) {
        if (grid[i - 1] == SHIP) {
          hit(i);
        } else if (atLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atBottom(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalBottomLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else {
          miss(i);
        }
      } 
      else {
        if (grid[i - 1] == SHIP) {
          hit(i);
        } else if (atBottom(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalBottomLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalBottomRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else {
          miss(i);
        }
      }                             
    } 
    // Check bottom row
    else if (i > SIZE - COLUMNS) {
      // Check bottom left corner
      if (i == SIZE - COLUMNS) {
        if (grid[i - 1] == SHIP) {
          hit(i);
        } else if (atLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atTop(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalTopRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else {
          miss(i);
        }
      } 
      // Check bottom right corner
      else if (i == SIZE) {
        if (grid[i - 1] == SHIP) {
          hit(i);
        } else if (atLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atTop(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalTopRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else {
          miss(i);
        }
      } 
      // Check rest of bottom row
      else {
        if (grid[i - 1] == SHIP) {
          hit(i);
        } else if (atTop(grid, COLUMNS, i) == SHIP) {
          hit(i);
        } else if (atLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalTopLeft(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else if (atDiagonalTopRight(grid, COLUMNS, i) == SHIP) {
          nearMiss(i);
        } else {
          miss(i);
        }
      }
    } 
    // Check left most column
    else if (i == COLUMNS + 1) { 
      if (grid[i - 1] == SHIP) {
        hit(i);
      } else if (atTop(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atBottom(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atRight(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalTopRight(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalBottomRight(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else {
        miss(i);
      }
    } 
    // Check right most column
    else if (i % COLUMNS == 0) { 
      if (grid[i - 1] == SHIP) {
        hit(i);
      } else if (atTop(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atBottom(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atLeft(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalTopLeft(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalBottomLeft(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else {
        miss(i);
      }
    } 
    // Check entire centered grid
    else { 
      if (grid[i - 1] == SHIP) {
        hit(i);
      } else if (atTop(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atRight(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atBottom(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atLeft(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalTopLeft(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalTopRight(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalBottomLeft(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else if (atDiagonalBottomRight(grid, COLUMNS, i) == SHIP) {
        nearMiss(i);
      } else {
        miss(i);
      }
    }
  }
  return 0;
}
