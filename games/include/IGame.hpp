//
// IGame.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/games/include
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Tue Mar 28 14:24:06 2017 Antoine
// Last update Fri Mar 31 13:58:07 2017 Simon
//

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "Protocol.hpp"

class				IGame
{
public:
  typedef enum {
    E_WIN,
    E_LOSE
  }	e_end;

  // Getters
  virtual struct WhereAmI	_whereAmI() const = 0;
  virtual struct GetMap		_getMap() const = 0;

  // Input
  virtual void			_goUp() = 0;
  virtual void			_goDown() = 0;
  virtual void			_goLeft() = 0;
  virtual void			_goRight() = 0;
  // virtual void			_goForward() = 0;
  // virtual void			_shoot() = 0;
  // virtual void			_illegal() = 0;

  // the game
  virtual void			_play() = 0;
  virtual void			_pause() = 0;
  virtual void			_gameOver(e_end) = 0;

private:
//   struct GetMap		_map;
//   struct WhereAmI		_position;
};

#endif /* !IGAME_HPP_ */
