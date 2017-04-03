//
// launcher.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:30:33 2017 Simon
// Last update Mon Apr  3 17:41:29 2017 Simon
//

#include <signal.h>
#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <string>
#include <sstream>
#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"
#include "Launcher.hpp"

Launcher::Launcher(std::string &lib)
{
  IGraphic* (*launch)();
  DIR *dir;
  int	a = 0;
  struct dirent *ent;
  static const std::regex r("lib_arcade_[^_.]+.so");
  this->_lib_name = new std::string[4];
  this->_current = -1;
  if ((dir = opendir("./lib")) != NULL)
    {
    while (a != 3 && (ent = readdir(dir)) != NULL)
      {
	if (regex_match(ent->d_name, r))
	  {
	    this->_lib_name[a] = "./lib/";
	    this->_lib_name[a] += ent->d_name;
	    if (lib == this->_lib_name[a])
	      this->_current = a;
	    a++;
	  }
      }
    closedir(dir);
    }
  else
    {
      std::cerr << lib << ": no such file" << std::endl;
      exit(84);
    }
  if (this->_current == -1)
    {
      std::cerr << "lib " << lib << "does not exists" << std::endl;
      exit(84);
    }
  this->_dh_lib = dlopen(this->_lib_name[this->_current].c_str(), RTLD_LAZY);
  if (this->_dh_lib == NULL)
    {
      std::cerr << this->_lib_name[this->_current] << ": dhandle error" << std::endl;
      exit(84);
    }
  launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib, "launch_lib"));
  if (launch == NULL)
    {
      std::cerr << this->_lib_name[this->_current] << ": launch lib error" << std::endl;
      exit(84);
    }
  this->_lib = launch();
}

Launcher::~Launcher()
{
  dlclose(this->_dh_lib);
}

void		Launcher::changeLib(IGraphic::e_key key)
{
  IGraphic* (*launch)();
  this->_lib->closeWindow();
  dlclose(this->_dh_lib);
  if (key == IGraphic::E_2 && this->_current != 0)
    this->_current -= 1;
  else if (key == IGraphic::E_3 && this->_lib_name[this->_current + 1] != "")
    this->_current += 1;
  this->_dh_lib = dlopen(this->_lib_name[this->_current].c_str(), RTLD_LAZY);
  if (this->_dh_lib == NULL)
    {
      std::cerr << this->_lib_name[this->_current] << ": dhandle error" << std::endl;
      return ;
    }
  launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib, "launch_lib"));
  if (launch == NULL)
    {
      std::cerr << this->_lib_name[this->_current] << ": launch lib error" << std::endl;
      return ;
    }
  this->_lib = launch();
  this->_lib->openWindow(40, 40);
}

void			Launcher::writeMenu()
{
  int			a = 0;
  int			y = 11;
  std::string		s;
  
  s = "Welcome in the Arcade!";
  this->_lib->writeStuff((40 - s.size()) / 2, 3, s);
  s = "Choose your graphic library below:";
  this->_lib->writeStuff(2, 8, s);
  while (this->_lib_name[a] != "")
    {
      s = this->_lib_name[a];
      this->_lib->writeStuff(5, y, s);
      a++;
      y += 2;
    }
  s = "Choose your game below:";
  this->_lib->writeStuff(2, 21, s);
  s = "Machin";
  this->_lib->writeStuff(5, 24, s);
  s = "Truc";
  this->_lib->writeStuff(5, 26, s);
}

void		Launcher::buildFrame()
{
  int		i;
  std::string	s;

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

  // Other frame
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 18, IGraphic::E_WHITE);
  for (i = 1; i != 39; i++)
    this->_lib->buildCell(i, 29, IGraphic::E_WHITE);
}

static void	sigIntHandler(int s)
{
  (void) s;
}

int		Launcher::interact()
{
  switch (this->_lib->getKey())
    {
    case IGraphic::E_2:
      this->changeLib(IGraphic::E_2);
      break ;
    case IGraphic::E_3:
      this->changeLib(IGraphic::E_3);
      break ;
    case IGraphic::E_ESC:
      return (-1);
    }
  return (0);
}

void		Launcher::launch()
{
  this->_lib->openWindow(40, 40);
  signal(SIGINT, sigIntHandler);
  while (1)
    {
      this->writeMenu();
      this->buildFrame();
      if (this->interact() == -1)
	break ;
      this->_lib->refreshWindow();
      // this->_lib->clearWindow();
    }
  this->_lib->closeWindow();
}
