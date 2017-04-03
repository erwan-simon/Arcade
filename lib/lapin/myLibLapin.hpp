/*
** myLibLapin.hpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:44:50 2017 Selim Rinaz
** Last update Mon Apr  3 12:07:07 2017 Selim Rinaz
*/

#ifndef MYLIBLAPIN_HPP_
# define MYLIBLAPIN_HPP_

# include <lapin.h>
# include "IGraphic.hpp"

class			myLibLapin : public IGraphic
{
  t_bunny_window	*window;
  unsigned int		width;
  unsigned int		height;

public:
  virtual int		openWindow(int x, int y);
  virtual int		refreshWindow();
  virtual int		closeWindow();
  virtual e_key		getKey();
  virtual int		clearWindow();
  virtual int		buildCell(int x, int y, e_color col);
  virtual int		writeStuff(int x, int y, std::string &text);
};

#endif /* !MYLIBLAPIN_HPP_ */
