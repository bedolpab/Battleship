#include "util.h"
#include <iostream>
#include <random>
#include <string>

#define COLUMNS 16
#define ROWS 16

using namespace std;

void info() { cout << "Coordinate structure: (x, y)" << endl; }

void hit(int i) {
  int y = i / COLUMNS;
  int x = i % COLUMNS;
  cout << "HIT AT: (" + to_string(x) + ", " + to_string(y) + ")" << endl;
}

void miss(int i) {
  int y = i / COLUMNS;
  int x = i % COLUMNS;
  cout << "MISS AT: (" + to_string(x) + ", " + to_string(y) + ")" << endl;
}

void nearMiss(int i) {
  int y = i / COLUMNS;
  int x = i % COLUMNS;
  cout << "NEAR MISS AT: (" + to_string(x) + ", " + to_string(y) + ")" << endl;
}
