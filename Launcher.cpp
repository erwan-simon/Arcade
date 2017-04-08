/*
** Launcher.cpp for Launcher in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 17:04:13 2017 Selim Rinaz
** Last update Sat Apr  8 17:30:05 2017 Selim Rinaz
*/

#include <signal.h>
#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <string>
#include <chrono>
#include <thread>
#include "IGame.hpp"
#include "IGraphic.hpp"
#include "Launcher.hpp"

using namespace std::chrono;

void	Launcher::drawMap()
{
  int		a = 1;
  int		x = 0;
  int		y = 0;
  std::string	s = ".";
  std::string	o = "O";
  
  for (y = 0; y != 40; y++)
    {
      for (x = 0; x != 40; x++)
	{
	  if (this->_game->_getMap().tile[(y * 40) + x] == static_cast<arcade::TileType>(1))
	    this->_lib->buildCell(x, y, IGraphic::E_BLUE);
	  else if (this->_game->_getMap().tile[(y * 40) + x] == static_cast<arcade::TileType>(6))
	    this->_lib->writeStuff(x, y, s);
	  else if (this->_game->_getMap().tile[(y * 40) + x] == static_cast<arcade::TileType>(7))
	    this->_lib->writeStuff(x, y, o);
	  if (this->_game->_whereAmI().position[0].x == x &&
	      this->_game->_whereAmI().position[0].y == y)
	    this->_lib->buildCell(x, y, IGraphic::E_YELLOW);
	  while (a != this->_game->_whereAmI().lenght)
	    {
	      if (this->_game->_whereAmI().position[a].x == x &&
		  this->_game->_whereAmI().position[a].y == y)
		this->_lib->buildCell(x, y, IGraphic::E_GREEN);
	      a++;
	    }
	  a = 1;
	}
    }
}

void				Launcher::graphPlay()
{
  this->_end = IGame::E_NONE;
  time_point<system_clock>	t = system_clock::now();

  this->_lib->clearWindow();
  while (1)
    {
      t += milliseconds(200);
      std::this_thread::sleep_until(t);
      if (this->interact(this->_lib->getKey()) == -1)
	return ;
      if ((this->_end = this->_game->_graphPlay()) != IGame::E_NONE)
	break ;
      this->drawMap();
      this->_lib->refreshWindow();
      this->_lib->clearWindow();
    }
  this->_score = this->_game->_getScore();
  if(this->_dh_game != NULL)
    dlclose(this->_dh_game);
  this->_game = NULL;
}

Launcher::Launcher(std::string &lib)
{
  IGraphic* (*launch)();
  DIR *dir;
  int	a = 0;
  struct dirent *ent;
  static const std::regex graph("lib_arcade_[^_.]+.so");
  static const std::regex game("libarcade_[^_.]+.so");
  this->_lib_name = new std::string[4];
  this->_game_name = new std::string[3];
  this->_current_lib = -1;
  this->_game = NULL;
  this->_lib = NULL;
  this->_dh_lib = NULL;
  this->_dh_game = NULL;
  this->_score = 0;
  if ((dir = opendir("./lib")) != NULL)
    {
      while (a != 3 && (ent = readdir(dir)) != NULL)
	{
	  if (regex_match(ent->d_name, graph))
	    {
	      this->_lib_name[a] = "./lib/";
	      this->_lib_name[a] += ent->d_name;
	      if (lib == this->_lib_name[a])
		this->_current_lib = a;
	      a++;
	    }
	}
      closedir(dir);
    }
  else
      throw std::runtime_error("lib: no such directory");
  a = 0;
  if ((dir = opendir("./games")) != NULL)
    {
      while (a != 2 && (ent = readdir(dir)) != NULL)
	{
	  if (regex_match(ent->d_name, game))
	    {
	      this->_game_name[a] = "./games/";
	      this->_game_name[a] += ent->d_name;
	      a++;
	    }
	}
      closedir(dir);
    }
  else
    throw std::runtime_error("games: no such directory");
  if (this->_current_lib == -1)
    throw std::runtime_error("lib " + lib + "does not exists");
  this->_dh_lib = dlopen(this->_lib_name[this->_current_lib].c_str(), RTLD_LAZY);
  if (this->_dh_lib == NULL)
    throw std::runtime_error(this->_lib_name[this->_current_lib] + ": dhandle error");
  launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib, "launch_lib"));
  if (launch == NULL)
    throw std::runtime_error(this->_lib_name[this->_current_lib] + ": launch lib error");
  this->_lib = launch();
}

Launcher::~Launcher()
{
  if(this->_dh_lib != NULL)
    dlclose(this->_dh_lib);
}

void		Launcher::changeLib(IGraphic::e_key key)
{
  IGraphic*	(*launch)();
  this->_lib->closeWindow();
  if(this->_dh_lib != NULL)
    dlclose(this->_dh_lib);
  if (key == IGraphic::E_2 && this->_current_lib != 0)
    this->_current_lib -= 1;
  else if (key == IGraphic::E_3 && this->_lib_name[this->_current_lib + 1] != "")
    this->_current_lib += 1;
  this->_dh_lib = dlopen(this->_lib_name[this->_current_lib].c_str(), RTLD_LAZY);
  if (this->_dh_lib == NULL)
    throw std::runtime_error(this->_lib_name[this->_current_lib] + ": dhandle lib error");
  launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib, "launch_lib"));
  if (launch == NULL)
    throw std::runtime_error(this->_lib_name[this->_current_lib] + ": launch lib error");
  this->_lib = launch();
  this->_lib->openWindow(40, 40);
}

void		Launcher::changeGame(IGraphic::e_key key)
{
  IGame*	(*launch)(int, int, Launcher&);

  if(this->_dh_game != NULL)
    dlclose(this->_dh_game);
  if (key == IGraphic::E_4 && this->_current_game != 0)
    this->_current_game -= 1;
  else if (key == IGraphic::E_5 && this->_game_name[this->_current_game + 1] != "")
    this->_current_game += 1;
  this->_dh_game = dlopen(this->_game_name[this->_current_game].c_str(), RTLD_LAZY);
  if (this->_dh_game == NULL)
    throw std::runtime_error(this->_game_name[this->_current_game] + ": dhandle game error");
  launch = reinterpret_cast<IGame* (*)(int, int, Launcher&)>(dlsym(this->_dh_game, "launch_game"));
  if (launch == NULL)
    throw std::runtime_error(this->_game_name[this->_current_game] + ": lauch game error");
  this->_game = launch(40, 40, *this);
  this->graphPlay();
}

void		Launcher::play()
{
  IGame*	(*launch)(int, int, Launcher&);

  this->_dh_game = dlopen(this->_game_name[this->_current_game].c_str(), RTLD_LAZY);
  if (this->_dh_game == NULL)
    throw std::runtime_error(this->_game_name[this->_current_game] + ": dhandle game error");
  launch = reinterpret_cast<IGame* (*)(int, int, Launcher&)>(dlsym(this->_dh_game, "launch_game"));
  if (launch == NULL)
    throw std::runtime_error(this->_game_name[this->_current_game] + ": lauch game error");
  this->_game = launch(40, 40, *this);
  this->graphPlay();
  if(this->_dh_game != NULL)
    dlclose(this->_dh_game);
}

void			Launcher::writeMenu()
{
  int			a = 0;
  int			y = 12;
  std::string		s;
  std::string		score;

  s = "Welcome in the Arcade!";
  this->_lib->writeStuff((40 - s.size()) / 2, 3, s);
  s = "Choose your graphic library below:";
  this->_lib->writeStuff(3, 9, s);
  while (this->_lib_name[a] != "")
    {
      s = this->_lib_name[a];
      this->_lib->writeStuff(6, y, s);
      a++;
      y += 2;
    }
  s = "Choose your game below:";
  this->_lib->writeStuff(3, 21, s);
  y = 24;
  a = 0;
  while (this->_game_name[a] != "")
    {
      s = this->_game_name[a];
      this->_lib->writeStuff(6, y, s);
      a++;
      y += 2;
    }
  if (this->_end != IGame::E_NONE)
    {
      score = std::to_string(this->_score);
      if (this->_end == IGame::E_WIN)
	s = "YOU WON! CONGRATULATION (no one ever did it (especially not us))";
      else
	s = "You lost! (bouh qu'il est mauvais)";
      this->_lib->writeStuff((40 - s.size()) / 2, 33, s);
      s = "Your Score : ";
      s += score;
      this->_lib->writeStuff((40 - s.size()) / 2, 35, s);
    }
  
}

void		Launcher::buildFrame()
{
  int		i;

  // Base frame
  for (i = 1; i != 40; i++)
    this->_lib->buildCell(0, i, IGraphic::E_WHITE);
  for (i = 0; i != 39; i++)
    this->_lib->buildCell(i, 0, IGraphic::E_WHITE);
  for (i = 0; i != 39; i++)
    this->_lib->buildCell(39, i, IGraphic::E_WHITE);
  for (i = 1; i != 40; i++)
    this->_lib->buildCell(i, 39, IGraphic::E_WHITE);

  // Title frame
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 1, IGraphic::E_RED);
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 5, IGraphic::E_RED);
  for (i = 2; i != 5; i++)
    this->_lib->buildCell(1, i, IGraphic::E_RED);
  for (i = 2; i != 5; i++)
    this->_lib->buildCell(38, i, IGraphic::E_RED);

  // Separation frame
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 6, IGraphic::E_WHITE);
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 18, IGraphic::E_WHITE);
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 29, IGraphic::E_WHITE);

  // Selector
  for (i = 3; i != 5; i++)
    this->_lib->buildCell(i, 12 + (2 * this->_current_lib), IGraphic::E_YELLOW);
  for (i = 3; i != 5; i++)
    this->_lib->buildCell(i, 24 + (2 * this->_current_game), IGraphic::E_YELLOW);  
}

static void	sigIntHandler(int s)
{
  (void) s;
}

int		Launcher::interact(IGraphic::e_key key)
{
  if (key == IGraphic::E_2 || key == IGraphic::E_3)
    this->changeLib(key);
  else if (key == IGraphic::E_ESC)
    return (-1);
  else if (key == IGraphic::E_4)
    {
      if (this->_game == NULL)
	this->_current_game -= (this->_current_game == 0 ? 0 : 1);
      else
	this->changeGame(key);
    }
  else if (key == IGraphic::E_5)
    {
      if (this->_game == NULL)
	this->_current_game += (this->_current_game == 0 ? 1 : 0);
      else
	this->changeGame(key);
    }
  else if (key == IGraphic::E_ENT)
    this->play();
  else if (this->_game != NULL && (key == IGraphic::E_RIGHT || key == IGraphic::E_LEFT ||
				   key == IGraphic::E_UP || key == IGraphic::E_DOWN))
    this->_game->_setHeading(key);
  return (0);
}

void		Launcher::launch()
{
  this->_end = IGame::E_NONE;
  this->_current_game = 0;
  this->_lib->openWindow(40, 40);
  signal(SIGINT, sigIntHandler);
  while (1)
    {
      this->writeMenu();
      this->buildFrame();
      if (this->interact(this->_lib->getKey()) == -1)
	break ;
      this->_lib->refreshWindow();
      this->_lib->clearWindow();
    }
  this->_lib->closeWindow();
}
