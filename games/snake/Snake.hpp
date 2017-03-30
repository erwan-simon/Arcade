//
// Snake.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:18:01 2017 Simon
// Last update Wed Mar 29 17:27:21 2017 Simon
//

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include "../include/IGames.hpp"

class Snake {
public:
  // Getters
  virtual struct WhereAmI	_whereAmI() const;
  virtual struct GetMap		_getMap() const;

  // Input
  virtual void			_goUp();
  virtual void			_goDown();
  virtual void			_goLeft();
  virtual void			_goRight();
  // virtual void			_goForward();
  // virtual void                       _shoot();
  // virtual void                       _illegal();

  // the game
  virtual void			_play();
  virtual void			_pause();
  virtual void			_gameOver(IGames::e_end);

private:
  struct GetMap			_map;
  struct WhereAmI		_position;
};

#endif
