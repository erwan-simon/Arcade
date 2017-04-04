//
// Snake.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:22:12 2017 Simon
// Last update Tue Apr  4 16:55:26 2017 Antoine
//

#include "Snake.hpp"

struct arcade::WhereAmI&                Snake::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&          Snake::_getMap() const
{
  return (*this->_map);
}

void            Snake::_play()
{

}

void            Snake::_getKey(IGraphic::e_key key)
{

}

void            Snake::_move(IGraphic::e_key key)
{
  if (key == IGraphic::E_UP)
    {

    }
  else if (key == IGraphic::E_DOWN)
    {

    }
  else if (key == IGraphic::E_RIGHT)
    {

    }
  else if (key == IGraphic::E_LEFT)
    {

    }
  else
    {

    }
}

void            Snake::_pause()
{

}

void            Snake::_gameOver(IGame::e_end)
{

}

void            Snake::_printMap()
{
  int           i = 0;
  int           y = 1;

  while (i < 40)
    {
      if (i >= 10)
        std::cout << " |" << i;
      else
        std::cout << " | " << i;
      i += 1;
    }
  std::cout << std::endl << std::endl;
  i = 0;
  while (i < 1600)
    {
      std::cout << " | "  << static_cast<int>(this->_map->tile[i]);
      if (y == 40)
	{
          y = 0;
          std::cout << std::endl;
	}
      i += 1;
      y += 1;
    }
}
void            Snake::_initMap()
{
  int           i = 0;
  int           y = 1;
  int           total = this->_map->width * this->_map->height;

  while (i <= total)
    {
      if (y == this->_map->width)
        {
          this->_map->tile[i] = static_cast<arcade::TileType>(1); //BLOCK                               
          y = 0;
        }
      else if (y == 1 || i <= (this->_map->width - 1) || i > (total - this->_map->width))
        this->_map->tile[i] = static_cast<arcade::TileType>(1); //BLOCK                                 
      else
	this->_map->tile[i] = static_cast<arcade::TileType>(0);  //EMPTY                                
      i += 1;
      y += 1;
    }
}

Snake::Snake(int width, int height, Launcher &launch)
{
  int   total = (width * height * sizeof(arcade::TileType));

  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  this->_map->width = width;
  this->_map->height = height;
  this->_initMap();

}

int             main()
{
  Snake         snake(40, 40);
  snake._printMap();
  // snake._getKey();                                                                                   
}
