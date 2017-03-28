//
// IGame.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/games/include
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Tue Mar 28 14:24:06 2017 Antoine
// Last update Tue Mar 28 14:52:42 2017 Antoine
//

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "Protocol.hpp"

class				IGame
{
public:
  virtual struct WhereAmI	_whereAmI() const = 0;
  virtual struct GetMap		_getMap() const = 0;
				// Imput
  virtual void			_goUp() = 0;
  virtual void			_goDown() = 0;
  virtual void			_goLeft() = 0;
  virtual void			_goRight() = 0;
  virtual void			_goForward() = 0;
  // virtual void			_shoot() = 0;
  // virtual void			_illegal() = 0;
  virtual void			_play() = 0;

private:
  struct GetMap			_map;
  struct WhereAmI		_position;
};

#endif /* !IGAME_HPP_ */
