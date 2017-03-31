/*
** myLibLapin.hpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:44:50 2017 Selim Rinaz
** Last update Fri Mar 31 15:11:33 2017 Selim Rinaz
*/

#ifndef MYLIBLAPIN_HPP_
# define MYLIBLAPIN_HPP_

# include <lapin.h>
# include "IGraphic.hpp"

class			myLibLapin : public IGraphic
{
  t_bunny_window	*window;

public:
  virtual int		openWindow(int x, int y);
  virtual int		refreshWindow();
  virtual int		closeWindow();
  virtual e_key		getKey();
  virtual int		clearWindow();
  virtual int		buildCell(int x, int y, e_color col);
};

#endif /* !MYLIBLAPIN_HPP_ */
