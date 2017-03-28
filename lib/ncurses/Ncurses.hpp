//
// ncurses.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/lib/ncurses
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar 28 19:03:04 2017 Simon
// Last update Tue Mar 28 19:08:59 2017 Simon
//

#ifndef NCURSES_HPP_
# define NCURSES_HPP_

# include "../Graphic/IGraphic.hpp"

class Nurses : public IGraphic
{
public:
  // Window
  virtual int	openWindow(int x, int y);
  virtual int	refreshWindow();
  virtual void	getStatus();
  virtual int	closeWindow();
  virtual int	getKey();

  // BuildCell
  virtual int	buildCell(int x, int y);
};

};
#endif
