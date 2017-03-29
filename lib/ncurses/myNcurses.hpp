//
// myNcurses.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:03:04 2017 Simon
// Last update Wed Mar 29 14:54:39 2017 Simon
//

#ifndef MYNCURSES_HPP_
# define MYNCURSES_HPP_

# include "./../../graphic/IGraphic.hpp"

class myNcurses : public IGraphic
{
public:
  // Window
  virtual int	openWindow(int x, int y);
  virtual int	refreshWindow();
  virtual int	clearWindow();
  virtual void	getStatus();
  virtual int	closeWindow();
  virtual int	getKey();

  // BuildCell
  virtual int	buildCell(int x, int y, e_color col);

private:
  WINDOW	*win;
  int		default_x;
  int		default_y;
  int		nb_line;
  int		nb_col;
  int		size_cell_x;
  int		size_cell_y;
};

#endif
