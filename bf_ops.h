#ifndef BF_OPS
#define BF_OPS

#include <iostream>
#include "bf_utils.h"

using namespace std;

typedef void (*bf_op)();

//for divide and modulo by 0
unsigned int copout()
{
  unsigned int i;
  cout << "Enter a number: ";
  cin >> i;
  return i;
}

//Arithmetic
void plus() { push(pop()+pop()); }
void subtract() { unsigned int a=pop(), b=pop(); push(b-a); }
void multiply() { push(pop()*pop()); }
void division() { unsigned int a=pop(), b=pop(); push(a==0?copout():b/a); }
void modulo() { unsigned int a=pop(), b=pop(); push(a==0?copout():b%a; }

//Directional
void north() { _DIRECTION = _NORTH; }
void east() { _DIRECTION = _EAST; }
void south() { _DIRECTION = _SOUTH; }
void west() { _DIRECTION = _WEST; }
void spin() { _DIRECTION = rand() % 4; }

//Conditional
void lnot() { push(!pop()); }
void gt() { unsigned int a=pop(), b=pop(); push(b>a); }
void hif() { if(pop()) west(); else east(); }
void vif() { if(pop()) north(); else south(); }

//Control
void tsm() { _MODE = !_MODE; }
void dup() { push(peek()); }
void swap() { unsigned int a=pop(), b=pop(); push(a); push(b); }
void chomp() { pop(); }
void jump() { move(); }
void put() { unsigned int y=pop(), x=pop(), v=pop(); _GRID[y][x]=v; }
void get() { unsigned int y=pop(), x=pop(), push((int)_GRID[y][x]); }
void gate() { unsigned int y=pop(), x=pop(), d=pop(); _X = x; _Y = y; _DIRECTION = d % 4; }

//I/O
void print_i() { cout << pop(); }
void print_c() { char c = pop(); cout << c; }
void input_i() { unsigned int v; cin >> v; push(v); }
void input_c() { char c; cin >> c; push(c); }
void hacf() { _RUN = false; }


#endif