//
// IGame.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/games/include
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Tue Mar 28 14:24:06 2017 Antoine
// Last update Wed Apr  5 17:48:34 2017 Simon
//

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "./../../graphic/IGraphic.hpp"
#include "Protocol.hpp"

class				IGame
{
public:
  typedef enum {
    E_WIN,
    E_LOSE
  }	e_end;

  // Getters
  virtual arcade::WhereAmI&	_whereAmI() const = 0;
  virtual arcade::GetMap&	_getMap() const = 0;

  // Input
  virtual void			_move(IGraphic::e_key) = 0;
  virtual int			_getKey(IGraphic::e_key) = 0;
  // virtual void			_goForward() = 0;
  // virtual void			_shoot() = 0;
  // virtual void			_illegal() = 0;

  // the game
  virtual void			Play() = 0;
  virtual void			_graphPlay() = 0;
  virtual void			_pause() = 0;
  virtual void			_gameOver(e_end) = 0;

  virtual void                  _initMap() = 0;
  virtual void			_initPosition() = 0;
  virtual void			_drawMap() = 0;
};

#endif /* !IGAME_HPP_ */
