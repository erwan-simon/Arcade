/*
** myNcurses.cpp for myNcurses in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:44:52 2017 Selim Rinaz
// Last update Sat Apr  8 19:23:21 2017 Antoine
*/

#include <ncurses.h>
#include "myNcurses.hpp"

void	myNcurses::openWindow(const int &x, const int &y)
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
  //ERREUR !!!!!! :
  this->win = newwin(y, x, 0, 0);
}

void	myNcurses::refreshWindow()
{
  refresh();
}

void	myNcurses::clearWindow()
{
  clear();
}

void	myNcurses::closeWindow()
{
  //ERREUR !!! :
  delwin(this->win);
  curs_set(1);
  endwin();
}

IGraphic::e_key	myNcurses::getKey() const
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
  case '2':
    return (IGraphic::E_2);
  case '3':
    return (IGraphic::E_3);
  case '4':
    return (IGraphic::E_4);
  case '5':
    return (IGraphic::E_5);
  case '8':
    return (IGraphic::E_8);
  case '9':
    return (IGraphic::E_9);
  case 27:
    return (IGraphic::E_ESC);
  }
  return (IGraphic::E_NONE);
}

void	myNcurses::buildCell(const int &x, const int &y, const IGraphic::e_color &col)
{
  attron(COLOR_PAIR(col));
  mvprintw(y, (x * 2), "OO");
  attroff(COLOR_PAIR(col));
}

void		myNcurses::writeStuff(const int &x, const int &y, const std::string &text)
{
  unsigned int	a = 0;

  while (a < text.size() * 2)
    {
      mvprintw(y, (x * 2) + a, "%c", text.at(a / 2));
      a += 2;
    }
}

extern "C"
{
  IGraphic* launch_lib()
  {
    return new myNcurses();
  }
}
