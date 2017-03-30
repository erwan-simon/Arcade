/*
** IGraphic.hpp for IGraphic in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Wed Mar 29 15:05:04 2017 Selim Rinaz
// Last update Thu Mar 30 16:39:46 2017 Simon
*/

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

#include <iostream>
#include <string>
#include <array>

class		IGraphic
{
public:
  typedef enum {
    E_BLACK,
    E_WHITE,
    E_YELLOW,
    E_RED,
    E_BLUE,
    E_PINK,
    E_GREEN
  }			e_color;

  typedef enum {
    E_NONE = -1,
    E_LEFT = 0,
    E_RIGHT,
    E_UP,
    E_DOWN
  }			e_key;

  // Window
  virtual int		openWindow(int x, int y) = 0;
  virtual int		refreshWindow() = 0;
  virtual int		clearWindow() = 0;
  virtual int		closeWindow() = 0;
  virtual e_key		getKey() = 0;

  // BuildCell
  virtual int		buildCell(int x, int y, e_color col) = 0;
};

#endif
