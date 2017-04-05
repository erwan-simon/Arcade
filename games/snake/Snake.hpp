//
// Snake.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:18:01 2017 Simon
// Last update Wed Apr  5 14:54:38 2017 Simon
//

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include <cstdlib>
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

  // Input
  virtual void                          _move(IGraphic::e_key);
  virtual int				_getKey(IGraphic::e_key);

  // the game
  virtual void                          Play();
  virtual void                          _pause();
  virtual void                          _gameOver(IGame::e_end);
  virtual void                          _initMap();
  
  void                                  _printMap();
private:
  Launcher                              *_launch;
  struct arcade::GetMap                 *_map;
  struct arcade::WhereAmI               *_position;
};

#endif
