//
// launcher.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:30:33 2017 Simon
// Last update Fri Mar 31 17:20:31 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <string>
#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"
#include "Launcher.hpp"

Launcher::Launcher(std::string &lib)
{
  IGraphic* (*launch)();
  DIR *dir;
  int	a = 0;
  int	chose = -1;
  struct dirent *ent;
  static const std::regex r("lib_arcade_[^_.]+.so");
  this->_lib_name = new std::string[3];

  if ((dir = opendir("./lib")) != NULL)
    {
    while (a != 3 && (ent = readdir(dir)) != NULL)
      {
	if (regex_match(ent->d_name, r))
	  {
	    this->_lib_name[a] = "./lib/";
	    this->_lib_name[a] += ent->d_name;
	    if (lib == this->_lib_name[a])
	      chose = a;
	    a++;
	  }
      }
    closedir(dir);
    }
  else
    {
      std::cerr << "no file lib" << std::endl;
      return ;
    }
  if (chose == -1)
    {
      std::cerr << "lib " << lib << "does not exists" << std::endl;
      return ;
    }
  this->_dh_lib = dlopen(this->_lib_name[chose].c_str(), RTLD_LAZY);
  if (this->_dh_lib == NULL)
    {
      std::cerr << "dhandle error" << std::endl;
      return ;
    }
  launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib, "launch_lib"));
  if (launch == NULL)
    {
      std::cerr << "launch lib error" << std::endl;
      return ;
    }
  this->_lib = launch();
}

Launcher::~Launcher()
{
  dlclose(this->_dh_lib);
}

void		Launcher::changeLib(int *a)
{
  IGraphic* (*launch)();
  this->_lib->closeWindow();
  dlclose(this->_dh_lib);
  *a = (*a == 0 ? 1 : 0);
  this->_dh_lib = dlopen(this->_lib_name[*a].c_str(), RTLD_LAZY);
  if (this->_dh_lib == NULL)
    {
      std::cerr << "dhandle error" << std::endl;
      return ;
    }
  launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib, "launch_lib"));
  if (launch == NULL)
    {
      std::cerr << "launch lib error" << std::endl;
      return ;
    }
  this->_lib = launch();
  this->_lib->openWindow(40, 40);
}

void		Launcher::launch()
{
  int		i;
  int		a;

  a = 1;
  this->_lib->openWindow(40, 40);
  while (1)
    {
      for (i = 1; i != 40; i++)
      	this->_lib->buildCell(0, i, IGraphic::E_RED);
      for (i = 0; i != 39; i++)
      	this->_lib->buildCell(i, 0, IGraphic::E_BLUE);
      for (i = 0; i != 39; i++)
      	this->_lib->buildCell(39, i, IGraphic::E_GREEN);
      for (i = 1; i != 40; i++)
      	this->_lib->buildCell(i, 39, IGraphic::E_YELLOW);
      if (this->_lib->getKey() == IGraphic::E_3)
	this->changeLib(&a);
      this->_lib->refreshWindow();
      this->_lib->clearWindow();
    }
  this->_lib->closeWindow();
}
