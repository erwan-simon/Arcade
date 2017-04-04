//
// Pacman.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 14:51:47 2017 Simon
// Last update Tue Apr  4 16:48:02 2017 Simon
//

#include "../../Launcher.hpp"
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"
#include <iostream>
#include <fstream>
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

void		Pacman::_goUp()
{
  
}

void		Pacman::_goDown()
{

}

void		Pacman::_goRight()
{

}

void		Pacman::_goLeft()
{

}

// void		Pacman::_goForward()
// {

// }

void		Pacman::_play()
{
  
}

void		Pacman::_pause()
{

}

void		Pacman::_gameOver(IGame::e_end)
{
  
}

static std::string&	getFile()
{
  struct stat		stat;
  int			rc = stat("./games/pacman/map.txt", &sta);

  if (rc == 0 || (statst_size != 1639 && stat.st_size != 1640))
    {
      std::cerr << "A problem occured with map.txt" << std::endl;
      exit(84);
    }
  
}

void		Pacman::_initMap()
{
  int		total = (this->_map->width * this->_map->height * sizeof(arcade::TileType));
  int		i = 0;
  int		save = 0;
  std::string	map;

  map = getFile();
  while (i < total)
    {
      std::cout << "itération == " << i << std::endl;
      if (i == 0 && i == (total - this->_map->width))
  	{
  	  for (int y = 0; y < this->_map->width; y++)
  	    {
  	      this->_map->tile[i] = static_cast<arcade::TileType>(1); //BLOCK
  	      i = i + 1;
  	    }
  	}
      this->_map->tile[i] = static_cast<arcade::TileType>(0);  //EMPTY
      i = i + 1;
    }
}

Pacman::Pacman(int width, int height, Launcher& launcher)
{
  int	total = (width * height * sizeof(arcade::TileType));

  this->_launch = &launcher;
  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  this->_map->width = width;
  this->_map->height = height;
  std::cout << "map->width == " << width << " | map->height == "
	    << height << " | total == "<< total <<std::endl;  
  this->_initMap();
}
