/*
** myLibLapin.cpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:42:54 2017 Selim Rinaz
** Last update Thu Mar 30 17:12:01 2017 Selim Rinaz
*/

#include <unistd.h>
#include "myQt.hpp"

int		myQt::openWindow(int x, int y)
{
  this->window = bunny_start((x * 20), (y * 20), 0, "The Game");
  if (!this->window)
    {
      return (1);
    }
  bunny_display(this->window);
  return (0);
}

int		myQt::refreshWindow()
{
  return (0);
}

int		myQt::closeWindow()
{
  bunny_stop(this->window);
  return (0);
}

int		myQt::clearWindow()
{
  bunny_clear(&this->window->buffer, BLACK);
  bunny_display(this->window);
  return (0);
}

int		myQt::getKey()
{
  return (0);
}

int		myQt::buildCell(int x, int y, e_color col)
{
  t_bunny_position	position;
  t_bunny_pixelarray	*pixarray;
  t_bunny_window	*window;

  (void)col;
  window = bunny_start(800, 800, 0, "The Game");
  if (!window)
    {
      return (1);
    }
  bunny_display(window);
  if (NULL == (pixarray = bunny_new_pixelarray(20, 20)))
    return (1);
  position.x = x * 20;
  position.y = y * 20;
  // bunny_blit(&window->buffer, &pixarray->clipable, &position);
  bunny_display(window);
  return (0);
}

int		main()
{
  myQt		Qt;

  // lapin.openWindow(40, 40);
  // lapin.clearWindow();
  lapin.buildCell(3, 3, myQt::E_BLACK);
  sleep(10);
  // lapin.closeWindow();
  return (EXIT_SUCCESS);
}
