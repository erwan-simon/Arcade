//
// Ghost.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Sat Apr  8 12:51:22 2017 Simon
// Last update Sat Apr  8 17:45:29 2017 Simon
//

#include <vector>
#include <algorithm>
#include "Ghost.hpp"

Ghost::Ghost()
{
  this->_state = PREDATOR;
  this->_heading = IGraphic::E_LEFT;
  this->_initial_heading = IGraphic::E_LEFT;
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

static bool	check(arcade::Position & position, int x, int y)
{
  // for (int i = 1; i != 5; i++)
  //   {
  //     if (position[i].x == x && position[i].y == y)
  // 	return (false);
  //   }
  return (true);
}

void			Ghost::move(arcade::GetMap const & map, arcade::Position & people)
{
  std::vector<int>	way;

  // if (map.tile[20 * 40 + 17] == static_cast<arcade::TileType>(0) &&
  //     people.position[]->x >= 17 && this->_position->x <= 21 && this->_position->y == 20)
  //   this->_heading = IGraphic::E_LEFT;
  // else
  //   if (this->_position->x == 16 && this->_position->y == 20)
  //     this->_heading = IGraphic::E_DOWN;
  // else
  //   {
  //     if (map.tile[this->_position->y * 40 + this->_position->x + 1]
  // 	  != static_cast<arcade::TileType>(1)
  // 	  && check(people, this->_position->x + 1, this->_position->y))
  // 	way.push_back(0);
  //     else if (this->_position->x != 0 &&
  // 	       map.tile[this->_position->y * 40 + this->_position->x - 1]
  // 	  != static_cast<arcade::TileType>(1)
  // 	  && check(people, this->_position->x - 1, this->_position->y))
  // 	way.push_back(1);
  //     else if (this->_position->y != 39 &&
  // 	       map.tile[(this->_position->y + 1) * 40 + this->_position->x]
  // 	       != static_cast<arcade::TileType>(1)
  // 	       && check(people, this->_position->x, this->_position->y + 1))
  // 	way.push_back(2);
  //     else if (this->_position->y != 0 &&
  // 	       map.tile[(this->_position->y - 1) * 40 + this->_position->x]
  // 	       != static_cast<arcade::TileType>(1)
  // 	       && check(people, this->_position->x, this->_position->y - 1))
  // 	way.push_back(3);
  //     // else
  //     // 	{
      	  // if (this->_heading == IGraphic::E_UP)
      	  //   this->_position->y -= 1;
      	  // else if (this->_heading == IGraphic::E_DOWN)
      	  //   this->_position->y += 1;
      	  // else if (this->_heading == IGraphic::E_LEFT)
      	  //   this->_position->x -= 1;
      	  // else if (this->_heading == IGraphic::E_RIGHT)
      	  //   this->_position->y += 1;
  //     //}
  //     std::random_shuffle(way.begin(), way.end());
  //     if (way.at(0) == 0)
  // 	this->_position->x += 1;
  //     else if (way.at(0) == 1)
  // 	this->_position->x -= 1;
  //     else if (way.at(0) == 2)
  // 	this->_position->y += 1;
  //     else if (way.at(0) == 3)
  // 	this->_position->y -= 1;
  //   }
}
