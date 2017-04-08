//
// Pacman.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 14:51:47 2017 Simon
// Last update Sat Apr  8 15:11:08 2017 Simon
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
#include <fstream>
#include "Pacman.hpp"
#include "Ghost.hpp"

Pacman::Pacman(int width, int height)
{
  this->_score = 0;
  this->_heading = IGraphic::E_RIGHT;
  if ((this->_map = (struct arcade::GetMap *)
       malloc(sizeof(struct arcade::GetMap)
	      + (width * height * sizeof(arcade::TileType)))) == NULL)
    exit(84);
  if ((this->_position = (struct arcade::WhereAmI *)
       malloc(sizeof(struct arcade::WhereAmI)
	      + (5 * sizeof(struct arcade::Position)))) == NULL)
    exit (84);
  this->_initMap();
  this->_initPosition();
}

Pacman::~Pacman()
{
  delete (this->_ghost);
  free(this->_map);
  free(this->_position);
}

struct arcade::WhereAmI&	Pacman::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&		Pacman::_getMap() const
{
  return (*this->_map);
}

int	Pacman::_getScore() const
{
  return (this->_score);
}

Ghost &	Pacman::_getGhost() const
{
  return (*this->_ghost);
}

void	Pacman::_setHeading(IGraphic::e_key key)
{
  this->_heading = key;
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

void	Pacman::_evilMove()
{
  for (int i = 0; i != 5; i++)
    {
      if (this->_ghost[i].getState() == Ghost::PREDATOR)
	{
	  if (this->_ghost[i].getPosition().x == this->_position->position[0].x + 1 &&
	      this->_ghost[i].getPosition().y == this->_position->position[0].y)
	    this->_position->position[i + 1].x += 1;
	  else if (this->_ghost[i].getPosition().x == this->_position->position[0].x - 1 &&
		   this->_ghost[i].getPosition().y == this->_position->position[0].y)
	    this->_position->position[i + 1].x -= 1;
	  else if (this->_ghost[i].getPosition().x == this->_position->position[0].x &&
		   this->_ghost[i].getPosition().y == this->_position->position[0].y + 1)
	    this->_position->position[i + 1].y += 1;
	  else if (this->_ghost[i].getPosition().x == this->_position->position[0].x &&
		   this->_ghost[i].getPosition().y == this->_position->position[0].y - 1)
	    this->_position->position[i + 1].y -= 1;
	  else
	    this->_ghost[i].move(*this->_map, this->_position->position[0]);
	}
      else
	this->_ghost[i].move(*this->_map, this->_position->position[0]);
    }
}

IGame::e_end	Pacman::_graphPlay()
{
  IGame::e_end	end;
  static int	free = 0;

  if (free == 50)
    {
      this->_map->tile[20 * 40 + 17] = static_cast<arcade::TileType>(0);
      this->_map->tile[20 * 40 + 22] = static_cast<arcade::TileType>(0);
    }
  free++;
  if (this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
      == static_cast<arcade::TileType>(6))
    {
      this->_score += 1;
      this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
	= static_cast<arcade::TileType>(0);
    }
  end = this->_gameOver();
  this->_move(this->_heading);
  end = this->_gameOver();
  this->_evilMove();
  end = this->_gameOver();
  return (end);
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
  int		i = 0;
  std::string	*map;

  this->_map->type = arcade::CommandType::GET_MAP;
  this->_map->width = 40;
  this->_map->height = 40;
  if ((map = getFile()) == NULL)
    exit(84);
  while (i < this->_map->width * this->_map->height)
    {
      if (map->at(i) == 'O')
	this->_map->tile[i] = static_cast<arcade::TileType>(1); // BLOCK
      else if (map->at(i) == ' ')
	this->_map->tile[i] = static_cast<arcade::TileType>(6);  // BONUS
      else if (map->at(i) == 'X')
	this->_map->tile[i] = static_cast<arcade::TileType>(7); // BONUS ANTI-FANTOME
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
  this->_position->type = arcade::CommandType::WHERE_AM_I;
  this->_position->lenght = 5;
  if (this->_map->tile[20 * 40 + 18] != static_cast<arcade::TileType>(6)
      || this->_map->tile[20 * 40 + 19] != static_cast<arcade::TileType>(6)
      || this->_map->tile[20 * 40 + 20] != static_cast<arcade::TileType>(6)
      || this->_map->tile[20 * 40 + 21] != static_cast<arcade::TileType>(6)
      || this->_map->tile[23 * 40 + 19] != static_cast<arcade::TileType>(6))
    {
      std::cerr << "map problem : can't place protagonists" << std::endl;
      exit (84);
    }
  this->_position->position[0].x = 19;
  this->_position->position[0].y = 23;

  this->_position->position[1].x = 18;
  this->_position->position[1].y = 20;

  this->_position->position[2].x = 19;
  this->_position->position[2].y = 20;

  this->_position->position[3].x = 20;
  this->_position->position[3].y = 20;

  this->_position->position[4].x = 21;
  this->_position->position[4].y = 20;

  this->_ghost = new Ghost[4];
  this->_ghost[0].setPosition(this->_position->position[1]);
  this->_ghost[1].setPosition(this->_position->position[2]);
  this->_ghost[2].setPosition(this->_position->position[3]);
  this->_ghost[3].setPosition(this->_position->position[4]);  
}

extern "C"
{
  void			Play()
  {
    uint16_t		i = 0;
    arcade::CommandType	c;
    Pacman		p(40, 40);
    std::ofstream	o;

    while (std::cin.read(reinterpret_cast<char *>(&i), sizeof(uint16_t)))
      {
	c = static_cast<arcade::CommandType>(i);
	if (c == arcade::CommandType::WHERE_AM_I)
	  std::cout.write(reinterpret_cast<char *>(&p._whereAmI()), static_cast<std::streamsize>(sizeof(arcade::WhereAmI) + (sizeof(arcade::Position) * 5)));
	else if (c == arcade::CommandType::GET_MAP)
	  std::cout.write(reinterpret_cast<char *>(&p._getMap()), static_cast<std::streamsize>(sizeof(arcade::GetMap) + (sizeof(arcade::TileType) * 1600)));
	else if (c == arcade::CommandType::GO_UP)
	  p._setHeading(IGraphic::E_UP);
	else if (c == arcade::CommandType::GO_DOWN)
	  p._setHeading(IGraphic::E_DOWN);
	else if (c == arcade::CommandType::GO_LEFT)
	  p._setHeading(IGraphic::E_LEFT);
	else if (c == arcade::CommandType::GO_RIGHT)
	  p._setHeading(IGraphic::E_RIGHT);
	else if (c == arcade::CommandType::PLAY)
	  p._graphPlay();
      }
  }

  IGame*	launch_game(int x, int y)
  {
    return new Pacman(x, y);
  }
}
