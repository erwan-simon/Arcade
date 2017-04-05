//
// Pacman.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 14:51:47 2017 Simon
// Last update Wed Apr  5 11:07:03 2017 Simon
//

#include "../../Launcher.hpp"
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include "Pacman.hpp"

struct arcade::WhereAmI&		Pacman::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&		Pacman::_getMap() const
{
  return (*this->_map);
}

void		Pacman::_move(IGraphic::e_key)
{

}

void		Pacman::_getKey(IGraphic::e_key key)
{
  if (key == IGraphic::E_LEFT || key == IGraphic::E_RIGHT || key == IGraphic::E_UP || key == IGraphic::E_DOWN)
    this->_move(key);
  else
    this->_launch->interact(key);
}

void		Pacman::Play()
{
  
}

void		Pacman::_pause()
{

}

void		Pacman::_gameOver(IGame::e_end end)
{
  
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

}

Pacman::Pacman(int width, int height, Launcher& launcher)
{
  int	total = (width * height * sizeof(arcade::TileType));

  this->_launch = &launcher;
  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  this->_map->width = width;
  this->_map->height = height;
  this->_initMap();
}

void	Pacman::_graphPlay()
{
  this->_launch->_lib->clearWindow();
  while (1)
    {
      this->_drawMap();
      // this->_getKey(this->_launch->_lib->getKey());
      if (this->_launch->_lib->getKey() == IGraphic::E_ESC)
       	break ;
      // this->_launch->getLib()->refreshWindow();
    }
}

extern "C"
{
  IGame*	launch_game(int x, int y, Launcher& launcher)
  {
    return new Pacman(x, y, launcher);
  }
}
