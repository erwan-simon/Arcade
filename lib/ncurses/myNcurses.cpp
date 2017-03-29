//
// myNcurses.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:02:29 2017 Simon
// Last update Wed Mar 29 14:01:15 2017 Simon
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
  this->nb_line = y;
  this->nb_col = x;
  return (0);
}

int	myNcurses::refreshWindow()
{
  getmaxyx(stdscr, this->nb_col, this->nb_line);
  refresh();
  return (0);
}

int	myNcurses::clearWindow()
{

}

void	myNcurses::getStatus()
{

}

int	myNcurses::closeWindow()
{
  if (delwin(this->win) != 0)
    return (84);
  curs_set(1);
  endwin();
  return (0);
}

int	myNcurses::getKey()
{
  return (getch());
}

int	myNcurses::buildCell(int x, int y, IGraphic::e_color col)
{
  if (x > nb_col || y > nb_line)
    return (84);
  attron(COLOR_PAIR(col));
  mvprintw(y, x, "a");
  attroff(COLOR_PAIR(col));
  return (0);
}