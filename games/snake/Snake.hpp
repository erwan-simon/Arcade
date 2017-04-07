//
// Snake.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:18:01 2017 Simon
// Last update Fri Apr  7 12:14:07 2017 Antoine
//

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include <cstdlib>
#include <ctime>
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"
#include "./../include/IGame.hpp"
#include "../../Launcher.hpp"

class					Snake : public IGame
{
public:
  Snake(int width, int height, Launcher &launch);

  // Getters
  virtual struct arcade::WhereAmI&      _whereAmI() const;
  virtual struct arcade::GetMap&        _getMap() const;
  virtual int				_getScore() const;
  
  // Setter
  virtual void				_setHeading(IGraphic::e_key);
  void					_popFood();
  // Input
  virtual void                          _move(IGraphic::e_key);
  void					_setMove(int, int);

  // the game
  virtual void                          Play();
  virtual void                          _pause();
  virtual void                          _gameOver(IGame::e_end);
  virtual void				_graphPlay();
  virtual void                          _initMap();
  virtual void                          _initPosition();
  void                                  _printMap();
  
private:
  Launcher                              *_launch;
  struct arcade::GetMap                 *_map;
  struct arcade::WhereAmI               *_position;
  int					_score;
  int					_food;
  IGraphic::e_key			_heading;
};

#endif
