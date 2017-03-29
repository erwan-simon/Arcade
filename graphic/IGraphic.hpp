//
// IGraphic.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/graphic
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Tue Mar 28 13:40:59 2017 Antoine
// Last update Wed Mar 29 15:27:10 2017 Simon
//

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

  // Window
  virtual int		openWindow(int x, int y) = 0;
  virtual int		refreshWindow() = 0;
  virtual int		clearWindow() = 0;
  virtual int		closeWindow() = 0;
  virtual int		getKey() = 0;

  // BuildCell
  virtual int		buildCell(int x, int y, e_color col) = 0;
};

#endif
