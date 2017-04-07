//
// Pacman.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 15:01:55 2017 Simon
// Last update Fri Apr  7 16:10:14 2017 Simon
//

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include "../include/IGame.hpp"

class	Pacman : public IGame {
public:
  Pacman(int width, int height);

  // Getters
  virtual struct arcade::WhereAmI&	_whereAmI() const;
  virtual struct arcade::GetMap&	_getMap() const;
  virtual int				_getScore() const;
  virtual void				_setHeading(IGraphic::e_key key);
  
  // Input
  virtual void				_move(IGraphic::e_key);
  void					_evilMove();
  // virtual void			_goForward();
  // virtual void                       _shoot();
  // virtual void                       _illegal();

  // the game
  virtual IGame::e_end			_graphPlay();
  virtual void				Play();
  virtual void				_pause();
  virtual IGame::e_end			_gameOver();

  virtual void				_initMap();
  virtual void				_initPosition();

private:
  struct arcade::GetMap			*_map;
  struct arcade::WhereAmI		*_position;
  IGraphic::e_key			_heading;
  int					_score;
};

#endif
