
#include "../src/bf_utils.h"

int main()
{
  init_grid((char*)"test_utils.bef");
  for(int r=0;r<20;r++)
  {
    for(int c=0;c<20;c++)
    {
      cout << (_GRID[r][c] ? (char)_GRID[r][c] : ' ');
    }
    cout << endl;
  }

  cout << endl << endl;

  push(5);
  cout << "pushed 5, popping " << pop() << endl;

  push(6);
  cout << "pushed 6, peeking " << peek() << endl;

  cout << "popping " << pop() << endl;

  cout << "PC " << _X << "," << _Y << endl;
  move();
  cout << "PC moved, now at " << _X << "," << _Y << endl;


  return 0;
}
