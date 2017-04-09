/*
** Pacman.cpp for Pacman in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:56:56 2017 Selim Rinaz
// Last update Sun Apr  9 20:01:30 2017 Simon
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include "Launcher.hpp"
#include "IGraphic.hpp"
#include "Protocol.hpp"
#include "Pacman.hpp"

Pacman::Pacman(int width, int height)
{
  this->_score = 0;
  this->_state = E_PREDATOR;
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

void	Pacman::_setHeading(IGraphic::e_key key)
{
  this->_heading = key;
}

void		Pacman::_move(IGraphic::e_key key)
{
  if (key == IGraphic::E_LEFT && this->_position->position[0].y == 19
      && this->_position->position[0].x == 0)
    this->_position->position[0].x = 39;
  else if (key == IGraphic::E_RIGHT && this->_position->position[0].y == 19
	   && this->_position->position[0].x == 39)
    this->_position->position[0].x = 0;
  else if (key == IGraphic::E_LEFT &&
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

static bool		check(arcade::Position const * position, int x, int y)
{
  for (int i = 1; i != 5; i++)
    {
      if (position[i].x == x && position[i].y == y)
	return (false);
    }
  return (true);
}

void			Pacman::_evilMove()
{
  std::vector<int>	way;
  
  for (int i = 1; i != 5; i++)
    {
      if (this->_map->tile[20 * 40 + 17] != static_cast<arcade::TileType>(1)
	  && this->_position->position[i].y == 20
	  && this->_position->position[i].x >= 17
	  && this->_position->position[i].x <= 21)
	this->_position->position[i].x -= 1;
      else
	{
	  if (this->_map->tile[this->_position->position[i].y * 40 + this->_position->position[i].x + 1] != static_cast<arcade::TileType>(1) && check(this->_position->position, this->_position->position[i].x + 1, this->_position->position[i].y))
	    way.push_back(0);
	  if (this->_map->tile[this->_position->position[i].y * 40 + this->_position->position[i].x - 1] != static_cast<arcade::TileType>(1) && check(this->_position->position, this->_position->position[i].x - 1, this->_position->position[i].y))
	    way.push_back(1);
	  if (this->_map->tile[(this->_position->position[i].y + 1) * 40 + this->_position->position[i].x] != static_cast<arcade::TileType>(1) && check(this->_position->position, this->_position->position[i].x, this->_position->position[i].y + 1))
	    way.push_back(2);
	  if (this->_map->tile[(this->_position->position[i].y - 1) * 40 + this->_position->position[i].x] != static_cast<arcade::TileType>(1) && check(this->_position->position, this->_position->position[i].x, this->_position->position[i].y - 1))
	    way.push_back(3);
	  std::random_shuffle(way.begin(), way.end());
	  if (way.size() != 0)
	    {
	      if (way.at(0) == 0)
		this->_position->position[i].x += 1;
	      else if (way.at(0) == 1)
		this->_position->position[i].x -= 1;
	      else if (way.at(0) == 2)
		this->_position->position[i].y += 1;
	      else if (way.at(0) == 3)
		this->_position->position[i].y -= 1;
	    }
	  way.clear();
	}
    }
}

IGame::e_end	Pacman::_graphPlay()
{
  IGame::e_end	end;
  static int	free = 0;
  static int	save = 0;

  if (free == 50)
    this->_map->tile[20 * 40 + 17] = static_cast<arcade::TileType>(0);
  free++;
  if (save != 0 && save == free - 50)
    {
      save = 0;
      this->_state = E_PREDATOR;
    }
  if (this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
      == static_cast<arcade::TileType>(6))
    {
      this->_score += 1;
      this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
	= static_cast<arcade::TileType>(0);
    }
  else if (this->_map->tile[this->_position->position[0].y * 40 + this->_position->position[0].x]
	   == static_cast<arcade::TileType>(7))
    {
      this->_score += 10;
      save = free;
      this->_state = E_PREY;
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
  for (int a = 1; a < 5; a++)
    {
      if (this->_position->position[0].y == this->_position->position[a].y
	  && this->_position->position[0].x == this->_position->position[a].x)
	{
	  if (this->_state == E_PREDATOR)
	    return (IGame::E_LOSE);
	  else
	    {
	      this->_score += 100;
	      this->_position->position[a].y = 20;
	      this->_position->position[a].x = 18 + a;
	    }
	}	
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
}

extern "C"
{
  void			Play()
  {
    uint16_t		i = 0;
    arcade::CommandType	c;
    Pacman		p(40, 40);

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
