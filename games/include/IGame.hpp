/*
** IGame.hpp for IGame in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:54:55 2017 Selim Rinaz
** Last update Sat Apr  8 16:54:56 2017 Selim Rinaz
*/

#ifndef IGAME_HPP_
# define IGAME_HPP_

#include "IGraphic.hpp"
#include "Protocol.hpp"

class				IGame
{
public:
  typedef enum {
    E_NONE,
    E_WIN,
    E_LOSE
  }	e_end;

  // Getters
  virtual arcade::WhereAmI&	_whereAmI() const = 0;
  virtual arcade::GetMap&	_getMap() const = 0;
  virtual int			_getScore() const = 0;
  virtual void			_setHeading(IGraphic::e_key) = 0;

  // Input
  virtual void			_move(IGraphic::e_key) = 0;
  
  // the game
  virtual e_end			_graphPlay() = 0;
  virtual e_end			_gameOver() = 0;

  virtual void                  _initMap() = 0;
  virtual void			_initPosition() = 0;
};

#endif /* !IGAME_HPP_ */
