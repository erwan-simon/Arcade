/*
** myLibLapin.cpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:42:54 2017 Selim Rinaz
** Last update Fri Mar 31 17:17:40 2017 Selim Rinaz
*/

#include <unistd.h>
#include "IGraphic.hpp"
#include "myLibLapin.hpp"

int			myLibLapin::openWindow(int x, int y)
{
  this->width = 20;
  this->height = 20;
  this->window = bunny_start((x * this->width), (y * this->height), 0, "The Game");
  if (!this->window)
    {
      return (1);
    }
  bunny_display(this->window);
  return (0);
}

int			myLibLapin::refreshWindow()
{
  this->width = 20;
  this->height = 20;
  bunny_display(this->window);
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

void			fill_color(t_bunny_pixelarray *pixarray, unsigned int col)
{
  int			idx;
  int			total;
  unsigned		*pixels;

  idx = 0;
  pixels = (unsigned *)pixarray->pixels;
  total = pixarray->clipable.clip_width * pixarray->clipable.clip_height;
  while (idx < total)
    {
      pixels[idx] = col;
      idx++;
    }
}

int			myLibLapin::buildCell(int x, int y, e_color col)
{
  t_bunny_position	position;
  t_bunny_pixelarray	*pixarray;

  if (NULL == (pixarray = bunny_new_pixelarray(20, 20)))
    return (1);
  position.x = x * this->width;
  position.y = y * this->height;
  switch (col) {
  case (E_BLACK) : fill_color(pixarray, BLACK);
    break;
  case (E_WHITE) : fill_color(pixarray, WHITE);
    break;
  case (E_YELLOW) : fill_color(pixarray, YELLOW);
    break;
  case (E_RED) : fill_color(pixarray, RED);
    break;
  case (E_BLUE) : fill_color(pixarray, BLUE);
    break;
  case (E_PINK) : fill_color(pixarray, PINK);
    break;
  case (E_GREEN) : fill_color(pixarray, GREEN);
    break;
  }
  bunny_blit(&this->window->buffer, &pixarray->clipable, &position);
  return (0);
}

// int		main()
// {
//   myLibLapin	lapin;

//   lapin.openWindow(40, 40);
//   while (1)
//     {
//       lapin.clearWindow();
//       lapin.buildCell(3, 3, myLibLapin::E_BLUE);
//       lapin.refreshWindow();
//     }
//   lapin.closeWindow();
//   return (EXIT_SUCCESS);
// }
