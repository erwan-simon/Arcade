//
// myNcurses.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:03:04 2017 Simon
// Last update Tue Mar 28 19:38:56 2017 Simon
//

#ifndef MYNCURSES_HPP_
# define MYNCURSES_HPP_

# include "../Graphic/IGraphic.hpp"

class myNcurses : public IGraphic
{
public:
  // Window
  virtual int	openWindow(int x, int y);
  virtual int	refreshWindow();
  virtual void	getStatus();
  virtual int	closeWindow();
  virtual int	getKey();

  // BuildCell
  virtual int	buildCell(int x, int y, e_color col);

private:
  WINDOW	*win;
};

#endif
