//
// Pacman.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 14:51:47 2017 Simon
// Last update Wed Apr  5 16:37:51 2017 Simon
//

#include "../../Launcher.hpp"
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <string>
#include <chrono>
#include "Pacman.hpp"

struct arcade::WhereAmI&		Pacman::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&		Pacman::_getMap() const
{
  return (*this->_map);
}

void		Pacman::_move(IGraphic::e_key key)
{
  if (key == IGraphic::E_LEFT && this->_map->tile[(this->_position->position[0].y * 40) + this->_position->position[0].x - 1] != static_cast<arcade::TileType>(1))
    this->_position->position[0].x -= 1;
  else if (key == IGraphic::E_RIGHT && this->_map->tile[(this->_position->position[0].y * 40) + this->_position->position[0].x + 1] != static_cast<arcade::TileType>(1))
    this->_position->position[0].x += 1;
  else if (key == IGraphic::E_UP && this->_map->tile[((this->_position->position[0].y - 1) * 40) + this->_position->position[0].x] != static_cast<arcade::TileType>(1))
    this->_position->position[0].y -= 1;
  else if (key == IGraphic::E_RIGHT && this->_map->tile[((this->_position->position[0].y + 1) * 40) + this->_position->position[0].x] != static_cast<arcade::TileType>(1))
    this->_position->position[0].y += 1;
}

int		Pacman::_getKey(IGraphic::e_key key)
{
  if (key == IGraphic::E_LEFT || key == IGraphic::E_RIGHT || key == IGraphic::E_UP || key == IGraphic::E_DOWN)
    this->_move(key);
  // else
  //   this->_launch->interact(key);
  else if (key == IGraphic::E_ESC)
    return (-1);
  return (0);
}

void		Pacman::Play()
{
  
}

void		Pacman::_pause()
{

}

void		Pacman::_gameOver(IGame::e_end end)
{
  (void) end;
}

void		Pacman::_drawMap()
{
  int		x = 0;
  int		y = 0;
  std::string	s = ".";
  
  for (y = 0; y != 40; y++)
    {
      for (x = 0; x != 40; x++)
	{
	  if (this->_map->tile[(y * 40) + x] == static_cast<arcade::TileType>(1))
	    this->_launch->_lib->buildCell(x, y, IGraphic::E_BLUE);
	  else if (this->_map->tile[(y * 40) + x] == static_cast<arcade::TileType>(6))
	    this->_launch->_lib->writeStuff(x, y, s);
	  if (this->_position->position[0].x == x && this->_position->position[0].y == y)
	    this->_launch->_lib->buildCell(x, y, IGraphic::E_YELLOW);
	  else if ((this->_position->position[1].x == x && this->_position->position[1].y == y)
		   || (this->_position->position[2].x == x && this->_position->position[2].y == y)
		   || (this->_position->position[3].x == x && this->_position->position[3].y == y)
		   || (this->_position->position[4].x == x && this->_position->position[4].y == y))
	    this->_launch->_lib->buildCell(x, y, IGraphic::E_GREEN);
	}
    }
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
  if (this->_map->tile[1 * 40 + 1] != static_cast<arcade::TileType>(6)
      || this->_map->tile[38 * 40 + 1] != static_cast<arcade::TileType>(6)
      || this->_map->tile[38 * 40 + 38] != static_cast<arcade::TileType>(6)
      || this->_map->tile[1 * 40 + 38] != static_cast<arcade::TileType>(6)
      || this->_map->tile[17 * 40 + 20] != static_cast<arcade::TileType>(6))
    exit (84);
  this->_position->position[0].x = 20;
  this->_position->position[0].y = 17;

  this->_position->position[1].x = 1;
  this->_position->position[1].y = 1;

  this->_position->position[2].x = 38;
  this->_position->position[2].y = 1;

  this->_position->position[3].x = 1;
  this->_position->position[3].y = 38;

  this->_position->position[4].x = 38;
  this->_position->position[4].y = 38;
}

Pacman::Pacman(int width, int height, Launcher& launcher)
{
  this->_launch = &launcher;
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
  this->_heading = IGraphic::E_NONE;
  this->_initMap();
  this->_initPosition();
}

void				Pacman::_graphPlay()
{
  this->_launch->_lib->clearWindow();
  while (1)
    {
      this->_drawMap();
      if (this->_getKey(this->_launch->_lib->getKey()) == -1)
	break ;
      this->_launch->_lib->refreshWindow();
      this->_launch->_lib->clearWindow();
    }
}

extern "C"
{
  IGame*	launch_game(int x, int y, Launcher& launcher)
  {
    return new Pacman(x, y, launcher);
  }
}
