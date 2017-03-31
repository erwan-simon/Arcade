/*
** myLibLapin.cpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:42:54 2017 Selim Rinaz
** Last update Fri Mar 31 15:16:21 2017 Selim Rinaz
*/

#include <unistd.h>
#include "IGraphic.hpp"
#include "myLibLapin.hpp"

int			myLibLapin::openWindow(int x, int y)
{
  this->window = bunny_start((x * 20), (y * 20), 0, "The Game");
  if (!this->window)
    {
      return (1);
    }
  bunny_display(this->window);
  return (0);
}

int			myLibLapin::refreshWindow()
{
  return (0);
}

int			myLibLapin::closeWindow()
{
  bunny_stop(this->window);
  return (0);
}

int			myLibLapin::clearWindow()
{
  bunny_clear(&this->window->buffer, BLACK);
  bunny_display(this->window);
  return (0);
}

myLibLapin::e_key	myLibLapin::getKey()
{
  return (E_NONE);
}

int			myLibLapin::buildCell(int x, int y, e_color col)
{
  t_bunny_position	position;
  t_bunny_pixelarray	*pixarray;
  t_bunny_window	*window;

  (void)col;
  if (NULL == (pixarray = bunny_new_pixelarray(20, 20)))
    return (1);
  position.x = x * 20;
  position.y = y * 20;
  bunny_blit(&this->window->buffer, &pixarray->clipable, &position);
  bunny_display(this->window);
  return (0);
}

int		main()
{
  myLibLapin	lapin;

  lapin.openWindow(40, 40);
  lapin.clearWindow();
  lapin.buildCell(3, 3, myLibLapin::E_BLACK);
  sleep(10);
  lapin.closeWindow();
  return (EXIT_SUCCESS);
}
