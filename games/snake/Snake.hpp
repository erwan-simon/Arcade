//
// Snake.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:18:01 2017 Simon
// Last update Tue Apr  4 14:07:47 2017 Antoine
//

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include <cstdlib>
#include "./../include/IGame.hpp"

class					Snake : public IGame
{
public:
  Snake(int width, int height);
  
  // Getters
  virtual struct arcade::WhereAmI&	_whereAmI() const;
  virtual struct arcade::GetMap&	_getMap() const;

  // Input
  virtual void				_goUp();
  virtual void				_goDown();
  virtual void				_goLeft();
  virtual void				_goRight();
  // virtual void			_goForward();
  // virtual void                       _shoot();
  // virtual void                       _illegal();

  // the game
  virtual void				_play();
  virtual void				_pause();
  virtual void				_gameOver(IGame::e_end);

  void					_initMap();
private:
  struct arcade::GetMap			*_map;
  struct arcade::WhereAmI		*_position;
};

#endif
