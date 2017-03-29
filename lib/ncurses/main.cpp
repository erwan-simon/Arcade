//
// main.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:43:13 2017 Simon
// Last update Wed Mar 29 16:26:15 2017 Simon
//

#include <ncurses.h>
#include <time.h>
#include "myNcurses.hpp"

int		main(int argc, char **argv)
{
  myNcurses	mn;
  int		x;
  int		y;
  int		a;
  clock_t	t;
  int		max_x;
  int		max_y;
  int		i;

  x = 1;
  y = 1;
  t = 0;
  a = 0;
  if (argc != 3)
    return (84);
  if (mn.openWindow(atoi(argv[1]), atoi(argv[2])) == 84)
    return (84);
  max_x = atoi(argv[1]) - 1;
  max_y = atoi(argv[2]) - 1;
  while (1)
    {
      t = clock();
      for (i = 0; i != atoi(argv[1]); i++)
	mn.buildCell(i, 0, IGraphic::E_BLUE);
      for (i = 0; i != atoi(argv[1]); i++)
	mn.buildCell(i, atoi(argv[2]), IGraphic::E_BLUE);
      for (i = 0; i != atoi(argv[2]); i++)
	mn.buildCell(0, i, IGraphic::E_BLUE);
      for (i = 0; i != atoi(argv[2]) + 1; i++)
	mn.buildCell(atoi(argv[1]), i, IGraphic::E_BLUE);
      mn.buildCell(a, 0, IGraphic::E_GREEN);
      mn.buildCell(x, y, IGraphic::E_RED);
      mn.refreshWindow();
      switch (mn.getKey()) {
      case IGraphic::E_LEFT:
	x -= (x == 1 ? 0 : 1);
	mn.clearWindow();
	break;
      case IGraphic::E_RIGHT:
	x += (x == max_x ? 0 : 1);
	mn.clearWindow();
	break;
      case IGraphic::E_UP:
	y -= (y == 1 ? 0 : 1);
	mn.clearWindow();
	break;
      case IGraphic::E_DOWN:
	y += (y == max_y ? 0 : 1);
	mn.clearWindow();
	break;
      }
      if (a == atoi(argv[1]))
	a = 0;
      if (t != clock())
	a++;
    }
  if (mn.closeWindow() == 84)
    return (84);
  return (0);
}
