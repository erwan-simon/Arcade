/*
** IGraphic.hpp for IGraphic in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Wed Mar 29 15:05:04 2017 Selim Rinaz
// Last update Sun Apr  9 13:16:38 2017 Simon
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
    E_DOWN,
    E_2,
    E_3,
    E_4,
    E_5,
    E_8,
    E_9,
    E_ESC
  }			e_key;

  virtual ~IGraphic() {};

  // Window
  virtual void		openWindow(const int &x, const int &y) = 0;
  virtual void		refreshWindow() = 0;
  virtual void		clearWindow() = 0;
  virtual void		closeWindow() = 0;
  virtual e_key		getKey() const = 0;

  // Draw
  virtual void		writeStuff(const int &x,
				   const int &y,
				   const std::string& text) = 0;
  virtual void		buildCell(const int &x,
				  const int &y,
				  const e_color &col) = 0;
};

#endif
