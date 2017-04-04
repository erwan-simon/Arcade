//
// Snake.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:22:12 2017 Simon
// Last update Tue Apr  4 14:09:13 2017 Antoine
//

#include "Snake.hpp"
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"

struct arcade::WhereAmI&		Snake::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&		Snake::_getMap() const
{
  return (*this->_map);
}

void		Snake::_goUp()
{
  
}

void		Snake::_goDown()
{

}

void		Snake::_goRight()
{

}

void		Snake::_goLeft()
{

}

// void		Snake::_goForward()
// {

// }

void		Snake::_play()
{
  
}

void		Snake::_pause()
{

}

void		Snake::_gameOver(IGame::e_end)
{
  
}
void		Snake::_initMap()
{
  int			total = (this->_map->width * this->_map->height * sizeof(arcade::TileType));
  int			i = 0;
  int			save = 0;

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

Snake::Snake(int width, int height)
{
  int			total = (width * height * sizeof(arcade::TileType));
  
  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  this->_map->width = width;
  this->_map->height = height;
  std::cout << "map->width == " << width << " | map->height == "<< height << " | total == "<< total <<std::endl;
  
  this->_initMap();
}

int		main()
{
  Snake		snake(40, 40);
}
