//
// IGraphic.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/graphic
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Tue Mar 28 13:40:59 2017 Antoine
// Last update Wed Mar 29 13:59:29 2017 Simon
//

#include <iostream>
#include <string>
#include <array>

class		IGraphic
{
public:
  typedef enum {
    BLACK,
    WHITE,
    YELLOW,
    RED,
    BLUE,
    PINK,
    GREEN
  } e_color;

  // Window
  virtual int		openWindow(int x, int y) = 0;
  virtual int		refreshWindow() = 0;
  virtual int		clearWindow() = 0;
  virtual void		getStatus() = 0;
  virtual int		closeWindow() = 0;
  virtual int		getKey() = 0;

  // BuildCell
  virtual int		buildCell(int x, int y, e_color col) = 0;
};
