//
// Ghost.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Apr  8 12:38:00 2017 Simon
// Last update Sat Apr  8 17:43:34 2017 Simon
//

#ifndef GHOST_HPP_
# define GHOST_HPP_

#include "../include/IGame.hpp"

class			Ghost {
public:
  typedef enum {
    PREDATOR,
    PREY
  }			e_state;

  Ghost();
  ~Ghost();

  e_state		getState() const;
  IGraphic::e_key	getHeading() const;
  IGraphic::e_key	getInitialHeading() const;

  void			setState(e_state);
  void			setHeading(IGraphic::e_key);
  void			setInitialHeading(IGraphic::e_key);

  void			move(arcade::GetMap const &, arcade::Position &);

private:
  e_state		_state;
  IGraphic::e_key	_heading;
  IGraphic::e_key	_initial_heading;
};

#endif
