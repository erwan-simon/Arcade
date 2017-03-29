/*
** IGraphic.hpp for IGraphic in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Wed Mar 29 15:05:04 2017 Selim Rinaz
** Last update Wed Mar 29 15:05:05 2017 Selim Rinaz
*/

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

#include <iostream>
#include <string>
#include <array>

class			IGraphic
{
public:
  enum		e_color
    {
      BLACK,
      WHITE,
      YELLOW,
      RED,
      BLUE,
      PINK,
      GREEN
    }

  virtual int		openWindow(int x, int y) = 0;
  virtual int		refreshWindow() = 0;
  virtual int		clearWindow() = 0;
  virtual void		getStatus() = 0;
  virtual int		closeWindow() = 0;
  virtual int		getKey() = 0;
  virtual int		buildCell(int x, int y, e_color col) = 0;
};

#endif
