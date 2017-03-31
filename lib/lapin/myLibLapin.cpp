/*
** myLibLapin.cpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:42:54 2017 Selim Rinaz
** Last update Fri Mar 31 16:18:43 2017 Selim Rinaz
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

void            fill_color(t_bunny_pixelarray *pixarray, void *color)
{
  int           idx;
  int           total;
  unsigned      *pixels;

  idx = 0;
  pixels = (unsigned *)pixarray->pixels;
  total = pixarray->clipable.clip_width * pixarray->clipable.clip_height;
  while (idx < total)
    {
      pixels[idx] = *color;
      idx++;
    }
}

int			myLibLapin::buildCell(int x, int y, e_color col)
{
  t_bunny_position	position;
  t_bunny_pixelarray	*pixarray;
  t_bunny_window	*window;

  if (NULL == (pixarray = bunny_new_pixelarray(20, 20)))
    return (1);
  position.x = x * 20;
  position.y = y * 20;
  switch (col) {
  case (E_BLACK) : fill_color(pixarray, BLACK);
  case (E_WHITE) : fill_color(pixarray, WHITE);
  case (E_YELLOW) : fill_color(pixarray, YELLOW);
  case (E_RED) : fill_color(pixarray, RED);
  case (E_BLUE) : fill_color(pixarray, BLUE);
  case (E_PINK) : fill_color(pixarray, PINK);
  case (E_GREEN) : fill_color(pixarray, GREEN);
    }
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
  sleep(5);
  lapin.closeWindow();
  return (EXIT_SUCCESS);
}
