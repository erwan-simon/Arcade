//
// Snake.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:22:12 2017 Simon
// Last update Thu Apr  6 10:48:46 2017 Simon
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

int	Snake::_getScore() const
{
  return (this->_score);
}

void	Snake::_setHeading(IGraphic::e_key key)
{
  this->_heading = key;
}

void            Snake::Play()
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

void            Snake::_initPosition()
{
  int		a = 1;

  this->_position->lenght = 5;
  this->_position->position[0].x = 20;
  this->_position->position[0].y = 17;
  while (a != this->_position->lenght)
    {
      this->_position->position[a].x = 20 + a;
      this->_position->position[a].y = 17;  
      a++;
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

void            Snake::_graphPlay()
{
  this->_move(this->_heading);
}

Snake::Snake(int width, int height, Launcher &launch)
{
  int   total = (width * height * sizeof(arcade::TileType));

  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  if ((this->_position = (struct arcade::WhereAmI *)
       malloc(sizeof(struct arcade::WhereAmI)
	      + (this->_position->lenght * sizeof(struct arcade::Position)))) == NULL)
    exit(84);
  this->_map->width = width;
  this->_map->height = height;
  this->_launch = &launch;
  this->_initMap();
  this->_initPosition();
  this->_graphPlay();
}

extern "C"
{
  IGame*        launch_game(int x, int y, Launcher& launcher)
  {
    return new Snake(x, y, launcher);
  }
}
