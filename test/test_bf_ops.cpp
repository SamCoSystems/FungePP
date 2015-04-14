
#include "../src/bf_utils.h"
#include "../src/bf_ops.h"

int main()
{
  push(5);
  push(5);
  addition();
  cout << "pushed 5, 5, and added, top now " << pop() << endl;

  push(5);
  push(4);
  subtraction();
  cout << "pushed 5, 5, and subtracted, top now " << pop() << endl;

  push(2);
  push(5);
  multiplication();
  cout << "pushed 2, 5 and multiplied, top now " << pop() << endl;
  
  push(9);
  push(3);
  division();
  cout << "pushed 9, 3 and divided, top now " << pop() << endl;

  push(9);
  push(0);
  division();
  cout << "pushed 9, 0 and divided, top now " << pop() << endl;

  push(9);
  push(3);
  modulo();
  cout << "pushed 9, 3 and modulosed, top now " << pop() << endl;

  push(9);
  push(0);
  modulo();
  cout << "pushed 9, 0 and modulosed, top now " << pop() << endl;

}
