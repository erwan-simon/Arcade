//
// Pacman.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 14:51:47 2017 Simon
// Last update Fri Apr  7 18:54:42 2017 Simon
//

#include "../../Launcher.hpp"
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include "Pacman.hpp"

struct arcade::WhereAmI&	Pacman::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&		Pacman::_getMap() const
{
  return (*this->_map);
}

void	Pacman::_setHeading(IGraphic::e_key key)
{
  this->_heading = key;
}

int	Pacman::_getScore() const
{
  return (this->_score);
}

void			Pacman::_evilMove()
{
  int			a = 1;
  std::vector<int>	way;
  
  while (a != 5)
    {
      if (this->_map->tile[this->_position->position[a].y * 40 + this->_position->position[a].x + 1] != static_cast<arcade::TileType>(1) || (this->_position->position[a].y == this->_position->position[0].y && this->_position->position[a].x + 1 == this->_position->position[0].x))
	way.push_back(0);
      if (this->_map->tile[this->_position->position[a].y * 40 + this->_position->position[a].x - 1] != static_cast<arcade::TileType>(1) || (this->_position->position[a].y == this->_position->position[0].y && this->_position->position[a].x - 1 == this->_position->position[0].x))
	way.push_back(1);
      if (this->_map->tile[(this->_position->position[a].y + 1)* 40 + this->_position->position[a].x] != static_cast<arcade::TileType>(1) || (this->_position->position[a].y + 1 == this->_position->position[0].y && this->_position->position[a].x == this->_position->position[0].x))
	way.push_back(2);
      if (this->_map->tile[(this->_position->position[a].y - 1) * 40 + this->_position->position[a].x] != static_cast<arcade::TileType>(1) || (this->_position->position[a].y == this->_position->position[0].y - 1 && this->_position->position[a].x == this->_position->position[0].x))
	way.push_back(3);
      std::random_shuffle(way.begin(), way.end());
      if (way.at(0) == 0)
	this->_position->position[a].x += 1;
      else if (way.at(0) == 1)
	this->_position->position[a].x -= 1;
      else if (way.at(0) == 2)
	this->_position->position[a].y += 1;
      else if (way.at(0) == 3)
	this->_position->position[a].x -= 1;
      way.clear();
      a++;
    }
}

void		Pacman::_move(IGraphic::e_key key)
{
  if (key == IGraphic::E_LEFT &&
      this->_map->tile[(this->_position->position[0].y * 40) +
		       this->_position->position[0].x - 1] != static_cast<arcade::TileType>(1))
    {
      this->_position->position[0].x -= 1;
      _heading = key;
    }
  else if (key == IGraphic::E_RIGHT &&
	   this->_map->tile[(this->_position->position[0].y * 40) +
			    this->_position->position[0].x + 1] != static_cast<arcade::TileType>(1))
    {
      this->_position->position[0].x += 1;
      _heading = key;
    }
  else if (key == IGraphic::E_UP &&
	   this->_map->tile[((this->_position->position[0].y - 1) * 40) +
			    this->_position->position[0].x] != static_cast<arcade::TileType>(1))
    {
      this->_position->position[0].y -= 1;
      _heading = key;
    }
  else if (key == IGraphic::E_DOWN &&
	   this->_map->tile[((this->_position->position[0].y + 1) * 40) +
			    this->_position->position[0].x] != static_cast<arcade::TileType>(1))
    {
      this->_position->position[0].y += 1;
      _heading = key;
    }
}

void		Pacman::_pause()
{
  
}

IGame::e_end	Pacman::_gameOver()
{
  for (int a = 1; a <= 5; a++)
    {
      if (this->_position->position[0].y == this->_position->position[a].y
	  && this->_position->position[0].x == this->_position->position[a].x)
	return (IGame::E_LOSE);
    }
  for (int y = 0; y < 40; y++)
    {
      for (int x = 0; x < 40; x++)
	{
	  if (this->_map->tile[(y * 40) + x] != static_cast<arcade::TileType>(6))
	    return (IGame::E_NONE);
	}
    }
  return (IGame::E_WIN);
}

static std::string*	getFile()
{
  std::string		line;
  std::string*		res = new std::string;
  std::ifstream		myfile("./games/pacman/map.txt");

  if (myfile.is_open())
    {
      while (getline(myfile, line))
	*res += line;
      myfile.close();
    }
  else
    {
      std::cerr << (*res).size() << " A problem occured with map.txt" << std::endl;
      exit(84);
    }
  if ((*res).size() != 1600)
    {
      std::cerr << (*res).size() << " A problem occured with map.txt" << std::endl;
      exit(84);
    }
  return (res);
}

void		Pacman::_initMap()
{
  int		total = this->_map->width * this->_map->height;
  int		i = 0;
  std::string	*map;

  if ((map = getFile()) == NULL)
    exit(84);
  while (i < total)
    {
      if (map->at(i) == '1')
	this->_map->tile[i] = static_cast<arcade::TileType>(1); // BLOCK
      else if (map->at(i) == '6')
	this->_map->tile[i] = static_cast<arcade::TileType>(6);  // BONUS
      else
	{
	  std::cerr << "map.txt contains some illegal caracters" << std::endl;
	  exit(84);
	}
      i = i + 1;
    }
  delete map;
}

void	Pacman::_initPosition()
{
  this->_position->lenght = 5;
  if (this->_map->tile[1 * 40 + 1] != static_cast<arcade::TileType>(6)
      || this->_map->tile[38 * 40 + 1] != static_cast<arcade::TileType>(6)
      || this->_map->tile[38 * 40 + 38] != static_cast<arcade::TileType>(6)
      || this->_map->tile[1 * 40 + 38] != static_cast<arcade::TileType>(6)
      || this->_map->tile[17 * 40 + 20] != static_cast<arcade::TileType>(6))
    {
      std::cerr << "map problem : can't place protagonists" << std::endl;
      exit (84);
    }
  this->_position->position[0].x = 20;
  this->_position->position[0].y = 17;

  this->_position->position[1].x = 1;
  this->_position->position[1].y = 38;

  this->_position->position[2].x = 38;
  this->_position->position[2].y = 38;

  this->_position->position[3].x = 1;
  this->_position->position[3].y = 1;

  this->_position->position[4].x = 38;
  this->_position->position[4].y = 1;
}

Pacman::Pacman(int width, int height)
{
  srand(time(NULL));
  this->_score = 0;
  if ((this->_map = (struct arcade::GetMap *)
       malloc(sizeof(struct arcade::GetMap)
	      + (width * height * sizeof(arcade::TileType)))) == NULL)
    exit(84);
  if ((this->_position = (struct arcade::WhereAmI *)
       malloc(sizeof(struct arcade::WhereAmI)
	      + (5 * sizeof(struct arcade::Position)))) == NULL)
    exit (84);
  this->_map->width = width;
  this->_map->height = height;
  this->_initMap();
  this->_initPosition();
}

IGame::e_end	Pacman::_graphPlay()
{
  if (this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
      == static_cast<arcade::TileType>(6))
    {
      this->_score += 1;
      this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
	= static_cast<arcade::TileType>(0);
    }
  this->_move(this->_heading);
  this->_evilMove();
  return(this->_gameOver());
}

// extern "C"
// {
//   void			Play()
//   {
//     arcade::CommandType	c;
//     Pacman	p(40, 40);

//     while (read(0, &c, sizeof(arcade::CommandType)) > 0)
//       {
// 	if (&c == arcade::TileType::WHERE_AM_I)
// 	  fwrite(p._whereAmI(), sizeof(struct arcade::WhereAmI) + sizeof(struct arcade::Position) * 5, 0);
// 	else if (&c == arcade::TileType::GETMAP)
// 	  fwrite(0, p._getMap(), sizeof(struct arcade::GetMap) + sizeof(struct arcade::TileType) * 40 * 40);
// 	p._graphPlay();
//       }
//   }
// }

extern "C"
{
  IGame*	launch_game(int x, int y)
  {
    return new Pacman(x, y);
  }
}
