/*
** Snake.hpp for Snake.hpp in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:50:42 2017 Selim Rinaz
** Last update Sat Apr  8 16:50:43 2017 Selim Rinaz
*/

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include <random>
#include "IGraphic.hpp"
#include "Protocol.hpp"
#include "IGame.hpp"
#include "Launcher.hpp"

class					Snake : public IGame
{
public:
  Snake(int width, int height);

  // Getters
  virtual struct arcade::WhereAmI&      _whereAmI() const;
  virtual struct arcade::GetMap&        _getMap() const;
  virtual int				_getScore() const;
  
  // Setter
  virtual void				_setHeading(IGraphic::e_key);
  void					_popFood();
  int					_checkFood(int);
  void					_eat();
  int					_checkPos();
  // Input
  virtual void                          _move(IGraphic::e_key);
  void					_setMove(int, int);

  // the game
  virtual IGame::e_end			_gameOver();
  virtual IGame::e_end			_graphPlay();
  virtual void                          _initMap();
  virtual void                          _initPosition();
  void                                  _printMap();
  
private:
  struct arcade::GetMap                 *_map;
  struct arcade::WhereAmI               *_position;
  int					_score;
  int					_food;
  IGraphic::e_key			_heading;
  bool					_state;
};

#endif
