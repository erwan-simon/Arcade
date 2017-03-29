//
// main.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:43:13 2017 Simon
// Last update Wed Mar 29 13:58:16 2017 Simon
//

#include <ncurses.h>
#include "myNcurses.hpp"

int		main(int argc, char **argv)
{
  myNcurses	mn;
  int		x;
  int		y;

  x = 0;
  y = 0;
  if (argc != 3)
    return (84);
  mn.openWindow(atoi(argv[1]), atoi(argv[2]));
  while (1)
    {
      mn.buildCell(x, y, IGraphic::RED);
      mn.refreshWindow();
      switch (mn.getKey()) {
      case KEY_UP:
	y--;
	break;
      case KEY_DOWN:
	y++;
	break;
      case KEY_LEFT:
	x--;
	break;
      case KEY_RIGHT:
	x++;
	break;
      }
    }
  mn.closeWindow();
  return 0;
}
