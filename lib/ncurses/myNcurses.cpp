//
// myNcurses.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:02:29 2017 Simon
// Last update Fri Mar 31 12:50:46 2017 Simon
//

#include <ncurses.h>
#include "myNcurses.hpp"

int	myNcurses::openWindow(int x, int y)
{
  initscr();
  cbreak();
  noecho();
  timeout(0);
  keypad(stdscr, TRUE);
  start_color();
  use_default_colors();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(3, COLOR_RED, COLOR_RED);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(6, COLOR_GREEN, COLOR_GREEN);
  curs_set(0);
  if ((this->win = newwin(y, x, 0, 0)) == NULL)
    return (84);
  this->size_cell_y = 1;
  this->size_cell_x = 2;
  this->default_x = x;
  this->default_y = y;
  this->nb_line = y - 1;
  this->nb_col = x - 1;
  return (0);
}

int	myNcurses::refreshWindow()
{
  refresh();
  return (0);
}

int	myNcurses::clearWindow()
{
  clear();
  return (0);
}

int	myNcurses::closeWindow()
{
  if (delwin(this->win) != 0)
    return (84);
  curs_set(1);
  endwin();
  return (0);
}

IGraphic::e_key	myNcurses::getKey()
{
  switch (getch()) {
  case KEY_LEFT:
    return (IGraphic::E_LEFT);
  case KEY_RIGHT:
    return (IGraphic::E_RIGHT);
  case KEY_UP:
    return (IGraphic::E_UP);
  case KEY_DOWN:
    return (IGraphic::E_DOWN);
  }
  return (IGraphic::E_NONE);
}

int	myNcurses::buildCell(int x, int y, IGraphic::e_color col)
{
  int	a;
  int	b;
  
  attron(COLOR_PAIR(col));
  for (a = 0; a < this->size_cell_y; a++)
    {
      for (b = 0; b < this->size_cell_x; b++)
	mvprintw((y * this->size_cell_y) + a, (x * this->size_cell_x) + b, " ");
    }
  attroff(COLOR_PAIR(col));
  return (0);
}


extern "C"
{
  IGraphic* launch_lib()
  {
    return new myNcurses();
  }
}
