#ifndef BF_UTIL_H
#define BF_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

const int _MAX_R = 4096;
const int _MAX_C = 4096; //per Funge++ spec

unsigned int _GRID[_MAX_R][_MAX_C];

const int _MAX_S = 1024; //per Funge++ spec

int _STACK[_MAX_S];
int _STACK_T = 0;

const int _DR[] =  { -1, 0, 1, 0 };
const int _DC[] = { 0, 1, 0, -1 };

const int _NORTH = 0;
const int _EAST = 1;
const int _SOUTH = 2;
const int _WEST = 3;

const int _NORMAL = 0;
const int _STRING = 1;

//program variables
int _DIRECTION = _EAST;
int _X = 0;
int _Y = 0;
int _MODE = _NORMAL;
int _RUN = true;


void push(int i)
{
  _STACK[_STACK_T++] = i;
}

int pop()
{
  return _STACK[--_STACK_T];
}

int peek()
{
  return _STACK[_STACK_T-1];
}

void move()
{
  _X += _DC[_DIRECTION];
  _Y += _DR[_DIRECTION];
}

void init_rand()
{
  srand(time(NULL));
}

void init_grid(char* filename)
{
  ifstream infile(filename);
  if(infile.is_open())
  {
    int r = 0;
    char* line;
    while(!infile.eof())
    {
      infile.getline(line, _MAX_C);
      for(int c=0;line[c];c++) _GRID[r][c]=line[c];
      r++;
    }
  }
  infile.close();
}

#endif //BF_UTIL_H
