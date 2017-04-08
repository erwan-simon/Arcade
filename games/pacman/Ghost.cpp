//
// Ghost.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Apr  8 12:51:22 2017 Simon
// Last update Sat Apr  8 15:14:06 2017 Simon
//

#include "Ghost.hpp"

Ghost::Ghost()
{
  this->_state = PREDATOR;
  this->_heading = IGraphic::E_LEFT;
  this->_initial_heading = IGraphic::E_LEFT;
  this->_position = NULL;
}

Ghost::~Ghost()
{
}

Ghost::e_state	Ghost::getState() const
{
  return (this->_state);
}

IGraphic::e_key	Ghost::getHeading() const
{
  return (this->_heading);
}

IGraphic::e_key	Ghost::getInitialHeading() const
{
  return (this->_initial_heading);
}

arcade::Position &	Ghost::getPosition() const
{
  return (*this->_position);
}

void	Ghost::setState(Ghost::e_state state)
{
  this->_state = state;
}

void	Ghost::setHeading(IGraphic::e_key key)
{
  this->_heading = key;
}

void	Ghost::setInitialHeading(IGraphic::e_key key)
{
  this->_initial_heading = key;
}

void	Ghost::setPosition(arcade::Position & pos)
{
  this->_position = &pos;
}

void	Ghost::move(arcade::GetMap const & map, arcade::Position const & hero)
{

}
