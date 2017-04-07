//
// Snake.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/snake
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:22:12 2017 Simon
// Last update Fri Apr  7 20:19:58 2017 Antoine
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

void	Snake::_setMove(int newX, int newY)
{
  int		i = this->_position->lenght;

  while (i > 0)
    {
      this->_position->position[i].x = this->_position->position[i - 1].x;
      this->_position->position[i].y = this->_position->position[i - 1].y;
      i = i - 1;
    }
  this->_position->position[0].x = newX;
  this->_position->position[0].y = newY;
}


void            Snake::_move(IGraphic::e_key key)
{
  int		posX = this->_position->position[0].x;
  int		posY = this->_position->position[0].y;
  
  if (key == IGraphic::E_UP)
    {
      if (this->_position->position[1].y != this->_position->position[0].y - 1)
	_setMove(posX, posY - 1);
      else
	_setMove(posX, posY + 1);
    }
  else if (key == IGraphic::E_DOWN)
    {
      if (this->_position->position[1].y != this->_position->position[0].y + 1)
	_setMove(posX, posY + 1);
      else
	_setMove(posX, posY - 1);
    }
  else if (key == IGraphic::E_RIGHT)
    {
      if (this->_position->position[1].x != this->_position->position[0].x + 1)
	_setMove(posX + 1, posY);
      else
	_setMove(posX - 1, posY);
    }
  else if (key == IGraphic::E_LEFT)
    {
      if (this->_position->position[1].x != this->_position->position[0].x - 1)
	_setMove(posX - 1, posY);
      else
	_setMove(posX + 1, posY);
    }
}

int			Snake::_checkPos()
{
  int		i = 1;

  while (i < this->_position->lenght)
    {
      if ((this->_position->position[i].x == this->_position->position[0].x) &&
	  (this->_position->position[i].y == this->_position->position[0].y))
	return (1);
      i += 1;
    }
  return (0);
}

IGame::e_end	Snake::_gameOver()
{
  int		x = this->_position->position[0].x;
  int		y = this->_position->position[0].y;

  if ((this->_map->tile[y * 40 + x] == static_cast<arcade::TileType>(1)) ||
      (_checkPos() == 1))
    return (IGame::E_LOSE);
  return (IGame::E_NONE);
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

int			Snake::_checkFood(int food)
{
  int		i = 1;
  int		total = 0;

  while (i < this->_position->lenght)
    {
      total = this->_position->position[i].y * 40 + this->_position->position[i].x;
      if (total == food)
	return (1);
      i += 1;
    }
  return (0);
}

void			Snake::_popFood()
{
  std::random_device    rand;
  int                   pop = 0;
  std::mt19937          gen(rand());

  if (this->_food == 0)
    {
      while (this->_map->tile[pop] == arcade::TileType::BLOCK || this->_checkFood(pop) == 1)
	{
	  std::uniform_int_distribution<> dis(this->_map->width, this->_map->width * this->_map->height);
          pop = dis(gen);
	}
      this->_map->tile[pop] = arcade::TileType::OTHER;
      this->_food = 1;
    }
}

void		Snake::_eat()
{
  int		x = this->_position->position[0].x;
  int		y = this->_position->position[0].y;
  int		save = this->_position->lenght + 2;
  
  if (this->_map->tile[y * 40 + x] == arcade::TileType::OTHER)
    {
      this->_food -= 1;
      this->_score += 1;
      this->_map->tile[y * 40 + x] = arcade::TileType::EMPTY;
      if ((this->_position = (struct arcade::WhereAmI *)
	   realloc(this->_position, sizeof(struct arcade::WhereAmI)
		   + (save * sizeof(struct arcade::Position)))) == NULL)
	exit(84);
      this->_position->lenght += 1;
    }
}
  
void            Snake::_initPosition()
{
  int		i = 0;

  this->_position->lenght = 4;
  while (i < this->_position->lenght)
    {
      this->_position->position[i].x = 18 + i;
      this->_position->position[i].y = 20;  
      i += 1;
    }
}

void            Snake::_initMap()
{
  int           i = 0;
  int           y = 1;
  int           total = this->_map->width * this->_map->height;

  while (i < total)
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

IGame::e_end	Snake::_graphPlay()
{
  IGame::e_end	end;
  
  this->_move(this->_heading);
  this->_popFood();
  this->_eat();
  end = this->_gameOver();
  return (end);
}

Snake::Snake(int width, int height)
{
  int   t_map = (width * height * sizeof(arcade::TileType) + 1);
  int	t_pos = (5 * sizeof(struct arcade::Position));
  
  if ((this->_map = (struct arcade::GetMap *)
       malloc(sizeof (struct arcade::GetMap) + t_map)) == NULL)
    exit(84);  
  if ((this->_position = (struct arcade::WhereAmI *)
       malloc(sizeof(struct arcade::WhereAmI)+ t_pos)) == NULL)
    exit(84);
  this->_food = 0;
  this->_state = 0;
  this->_score = 0;
  this->_heading = IGraphic::E_RIGHT;
  this->_map->width = width;
  this->_map->height = height;
  this->_initMap();
  this->_initPosition();
  this->_graphPlay();
}

extern "C"
{
  IGame*        launch_game(int x, int y)
  {
    return new Snake(x, y);
  }
}
