/*
** myLibLapin.cpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:42:54 2017 Selim Rinaz
** Last update Wed Mar 29 14:58:47 2017 Selim Rinaz
*/

#include <unistd.h>
#include "myLibLapin.hpp"

int		myLibLapin::openWindow(int x, int y)
{
  this->window = bunny_start(x, y, 0, "The Game");
  if (!this->window)
    {
      return (1);
    }
  bunny_display(this->window);
  return (0);
}

int		myLibLapin::refreshWindow()
{
  return (0);
}

int		myLibLapin::closeWindow()
{
  bunny_stop(this->window);
  return (0);
}

int		myLibLapin::getKey()
{
  return (0);
}

int		myLibLapin::buildCell(int x, int y, e_color col)
{
  (void)x, y, col;
  return (0);
}

int		main()
{
  myLibLapin	lapin;

  lapin.openWindow(600, 800);
  sleep(2);
  lapin.closeWindow();
  return (EXIT_SUCCESS);
}
	
