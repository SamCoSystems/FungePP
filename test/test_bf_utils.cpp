
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
  return 0;
}
