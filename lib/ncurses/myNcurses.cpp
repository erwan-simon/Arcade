//
// myNcurses.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:02:29 2017 Simon
// Last update Tue Mar 28 19:39:05 2017 Simon
//

#include "myNcurses.hpp"
#include "ncurse.h"

int	myNcurses::openWindow(int x, int y)
{
  
}

int	myNcurses::refreshWindow()
{

}

void	myNcurses::closeWindow()
{

}

int	myNcurses::getKey()
{
  
}

int	myNcurses::buildCell(int x, int y, e_color col)
{
  mvprintw(y, x, this->win, " ");
}
