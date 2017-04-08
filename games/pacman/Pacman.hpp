/*
** Pacman.hpp for Pacman in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:52:07 2017 Selim Rinaz
// Last update Sat Apr  8 18:47:12 2017 Simon
*/

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include "IGame.hpp"

class	Pacman : public IGame {
public:
  typedef enum {
    E_PREY,
    E_PREDATOR
  }					e_state;
  
  Pacman(int width, int height);
  ~Pacman();
  
  // Getters
  virtual struct arcade::WhereAmI&	_whereAmI() const;
  virtual struct arcade::GetMap&	_getMap() const;
  virtual int				_getScore() const;
  
  virtual void				_setHeading(IGraphic::e_key key);

  // Input
  virtual void				_move(IGraphic::e_key);
  void					_evilMove();

  // the game
  virtual IGame::e_end			_graphPlay();
  virtual IGame::e_end			_gameOver();

  virtual void				_initMap();
  virtual void				_initPosition();

private:
  e_state				_state;
  struct arcade::GetMap			*_map;
  struct arcade::WhereAmI		*_position;
  IGraphic::e_key			_initial_heading;
  IGraphic::e_key			_heading;
  int					_score;
};

#endif
