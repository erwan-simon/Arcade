//
// Snake.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:22:12 2017 Simon
// Last update Wed Apr  5 15:36:09 2017 Antoine
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

int		Snake::_getKey(IGraphic::e_key key)
{
  if (key == IGraphic::E_LEFT || key == IGraphic::E_RIGHT || key == IGraphic::E_UP || key == IGraphic::E_DOWN)
    this->_move(key);
  // else                                                                    
  //   this->_launch->interact(key);                                                   
  else if (key == IGraphic::E_ESC)
    return (-1);
  return (0);

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
{}

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

void            Snake::_drawMap()
{
  int           x = 0;
  int           y = 0;
  std::string   s = ".";

  for (y = 0; y != 40; y++)
    {
      for (x = 0; x != 40; x++)
        {
          if (this->_map->tile[(y * 40) + x] == static_cast<arcade::TileType>(1))
            this->_launch->_lib->buildCell(x, y, IGraphic::E_BLUE);
          // else if (this->_map->tile[(y * 40) + x] == static_cast<arcade::TileType>(6))
          //   this->_launch->_lib->writeStuff(x, y, s);
        }
    }
}

void            Snake::_graphPlay()
{
    this->_launch->_lib->clearWindow();
  while (1)
    {
      this->_drawMap();
      if (this->_getKey(this->_launch->_lib->getKey()) == -1)
        break ;
      // this->_launch->getLib()->refreshWindow();  
    }
}

Snake::Snake(int width, int height, Launcher &launch)
{
  int   total = (width * height * sizeof(arcade::TileType));

  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  this->_map->width = width;
  this->_map->height = height;
  this->_launch = &launch;
  this->_initMap();
  this->_graphPlay();
}

extern "C"
{
  IGame*        launch_game(int x, int y, Launcher& launcher)
  {
    return new Snake(x, y, launcher);
  }
}
