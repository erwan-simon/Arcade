//
// main.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:43:13 2017 Simon
// Last update Wed Mar 29 15:02:21 2017 Simon
//

#include <ncurses.h>
#include "myNcurses.hpp"

int		main(int argc, char **argv)
{
  myNcurses	mn;
  int		x;
  int		y;
  int		max_x;
  int		max_y;
  int		i;

  x = 1;
  y = 1;
  if (argc != 3)
    return (84);
  if (mn.openWindow(atoi(argv[1]), atoi(argv[2])) == 84)
    return (84);
  max_x = atoi(argv[1]) - 1;
  max_y = atoi(argv[2]) - 1;
  while (1)
    {
      for (i = 0; i != atoi(argv[1]); i++)
	mn.buildCell(i, 0, IGraphic::BLUE);
      for (i = 0; i != atoi(argv[1]); i++)
	mn.buildCell(i, atoi(argv[2]), IGraphic::BLUE);
      for (i = 0; i != atoi(argv[2]); i++)
	mn.buildCell(0, i, IGraphic::BLUE);
      for (i = 0; i != atoi(argv[2]) + 1; i++)
	mn.buildCell(atoi(argv[1]), i, IGraphic::BLUE);
      mn.buildCell(x, y, IGraphic::RED);
      mn.refreshWindow();
      switch (mn.getKey()) {
      case KEY_UP:
	y -= (y == 1 ? 0 : 1);
	mn.clearWindow();
	break;
      case KEY_DOWN:
	y += (y == max_y ? 0 : 1);
	mn.clearWindow();
	break;
      case KEY_LEFT:
	x -= (x == 1 ? 0 : 1);
	mn.clearWindow();
	break;
      case KEY_RIGHT:
	x += (x == max_x ? 0 : 1);
	mn.clearWindow();
	break;
      }
    }
  if (mn.closeWindow() == 84)
    return (84);
  return (0);
}
