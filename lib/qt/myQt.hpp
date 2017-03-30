/*
** myLibLapin.hpp for myLibLapin in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Tue Mar 28 17:44:50 2017 Selim Rinaz
** Last update Thu Mar 30 17:11:21 2017 Selim Rinaz
*/

#ifndef MYQT_HPP_
# define MYQT_HPP_

# include <>
# include "IGraphic.hpp"

class			myQt : public IGraphic
{
  t_bunny_window	*window;

public:
  virtual int		openWindow(int x, int y);
  virtual int		refreshWindow();
  virtual int		closeWindow();
  virtual int		getKey();
  virtual int		clearWindow();
  virtual int		buildCell(int x, int y, e_color col);
};

#endif /* !MYQT_HPP_ */
