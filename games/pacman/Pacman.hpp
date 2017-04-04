//
// Pacman.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 15:01:55 2017 Simon
// Last update Tue Apr  4 17:00:59 2017 Simon
//

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include "../include/IGame.hpp"

class	Pacman : public IGame {
public:
  Pacman(int width, int height, Launcher& launcher);

  // Getters
  virtual struct arcade::WhereAmI&	_whereAmI() const;
  virtual struct arcade::GetMap&	_getMap() const;

  // Input
  virtual void				_move(IGraphic::e_key);
  virtual void				_getKey(IGraphic::e_key);
  // virtual void			_goForward();
  // virtual void                       _shoot();
  // virtual void                       _illegal();

  // the game
  virtual void				Play();
  virtual void				_pause();
  virtual void				_gameOver(IGame::e_end);

  void					_initMap();
private:
  Launcher				*_launch;
  struct arcade::GetMap			*_map;
  struct arcade::WhereAmI		*_position;
};

#endif
