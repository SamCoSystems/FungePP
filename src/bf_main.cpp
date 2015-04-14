#include "bf_utils.h"
#include "bf_ops.h"

#include <unistd.h>

void do_op(char C)
{
  switch(C)
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': push(C-'0'); break;
    case '+': addition(); break;
    case '-': subtraction(); break;
    case '*': multiplication(); break;
    case '/': division(); break;
    case '%': modulo(); break;
    case '^': north(); break;
    case '>': east(); break;
    case 'V':
    case 'v': south(); break;
    case '<': west(); break;
    case '?': spin(); break;
    case '!': lnot(); break;
    case '`': gt(); break;
    case '_': hif(); break;
    case '|': vif(); break;
    case '"': tsm(); break;
    case ':': dup(); break;
    case '\\': swap(); break;
    case '$': chomp(); break;
    case '#': jump(); break;
    case 'p': put(); break;
    case 'g': get(); break;
    case 'H': gate(); break;
    case '.': print_i(); break;
    case ',': print_c(); break;
    case '&': input_i(); break;
    case '~': input_c(); break;
    case '@': hacf(); break;
    default: /* DO NOTHING! */ break;
  }
}

int main(int argc, char **argv)
{
  if(argc <= 1)
  {
    cout << "Usage: F++ <file>" << endl;
    cout << "  Loads and runs the befunge program <file>" << endl;
    return 0;
  }
  
  init_rand();
  init_grid(argv[1]);

  while(_RUN)
  {
    char C = _GRID[_Y][_X];

    if(C != 0 && (_MODE == _NORMAL || C == '"'))
    {
      //cout << "in normal mode, doing op " << C << endl;
      do_op(C);
    }
    else if(C != 0)
    {
      //cout << "in string mode, pushing " << C << endl;
      push(C);
    }
    
    move();
  }
  cout << endl;
  return 0;
}
