/*
** myLibLapin.cpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:42:54 2017 Selim Rinaz
** Last update Wed Apr  5 11:05:54 2017 Selim Rinaz
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
  // bunny_set_key_response(&this->getKey);
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
  return (0);
}

myLibLapin::e_key	myLibLapin::getKey()
{
  if (bunny_get_keyboard()[BKS_LEFT])
    return (E_LEFT);
  if (bunny_get_keyboard()[BKS_RIGHT])
    return (E_RIGHT);
  if (bunny_get_keyboard()[BKS_DOWN])
    return (E_DOWN);
  if (bunny_get_keyboard()[BKS_UP])
    return (E_UP);
  if (bunny_get_keyboard()[BKS_2])
    return (E_2);
  if (bunny_get_keyboard()[BKS_3])
    return (E_3);
  if (bunny_get_keyboard()[BKS_4])
    return (E_4);
  if (bunny_get_keyboard()[BKS_5])
    return (E_5);
  if (bunny_get_keyboard()[BKS_8])
    return (E_8);
  if (bunny_get_keyboard()[BKS_9])
    return (E_9);
  if (bunny_get_keyboard()[BKS_ESCAPE])
    return (E_ESC);
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

int			myLibLapin::writeStuff(int x, int y, std::string &text)
{
  t_bunny_position	position;
  t_bunny_pixelarray	*pixarray;
  size_t		i;
  std::string		file;

  if (NULL == (pixarray = bunny_new_pixelarray(20, 20)))
    return (1);
  for (i = 0; i < text.length(); i++)
    {
      position.x = x * this->width;
      position.y = y * this->height;
      fill_color(pixarray, BLACK);
      file = "./Fonts/";
      file += toupper(text.c_str()[i]);
      file += ".png";
      bunny_load_pixelarray(file.c_str());
      bunny_blit(&this->window->buffer, &pixarray->clipable, &position);
      x += 1;
    }
  return (0);
}

extern "C"
{
  IGraphic* launch_lib()
  {
    return new myLibLapin();
  }
}

// int		main()
// {
//   myLibLapin	Lapin;
//   int		i;
//   Lapin.openWindow(40, 40);
//   while (1)
//     {
//       for (i = 1; i != 40; i++)
//       	Lapin.buildCell(0, i, IGraphic::E_RED);
//       for (i = 0; i != 39; i++)
//       	Lapin.buildCell(i, 0, IGraphic::E_BLUE);
//       for (i = 0; i != 39; i++)
//       	Lapin.buildCell(39, i, IGraphic::E_GREEN);
//       for (i = 1; i != 40; i++)
//       	Lapin.buildCell(i, 39, IGraphic::E_YELLOW);
//       Lapin.refreshWindow();
//     }
//   Lapin.closeWindow();
//   return (EXIT_SUCCESS);
// }
