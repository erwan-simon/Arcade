//
// launcher.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:30:33 2017 Simon
// Last update Fri Mar 31 15:43:59 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include <dirent.h>
#include <regex>
#include <string>
#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"
#include "Launcher.hpp"

Launcher::Launcher()
{
  IGraphic* (*launch)();
  DIR *dir;
  struct dirent *ent;
  static const std::regex r("lib_arcade_[^_.]+.so");
  int	a;
  std::string s;
  this->_dh_lib = new void *[3];
  this->_lib = new IGraphic *[3];

  a = 0;
  if ((dir = opendir("./lib")) != NULL)
    {
    while (a != 3 && (ent = readdir(dir)) != NULL)
      {
	if (regex_match(ent->d_name, r))
	  {
	    s = "./lib/";
	    s += ent->d_name;
	    this->_dh_lib[a] = dlopen(s.c_str(), RTLD_LAZY);
	    if (this->_dh_lib[a] == NULL)
	      {
		std::cerr << "dhandle error" << std::endl;
		return ;
	      }
	    launch = reinterpret_cast<IGraphic* (*)()>(dlsym(this->_dh_lib[a], "launch_lib"));
	    if (launch == NULL)
	      {
		std::cerr << "launch lib error" << std::endl;
		return ;
	      }
	    this->_lib[a] = launch();
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
}

Launcher::~Launcher()
{
  if (this->_dh_lib[0])
    dlclose(this->_dh_lib[0]);
  if (this->_dh_lib[1])
    dlclose(this->_dh_lib[0]);
  if (this->_dh_lib[2])
    dlclose(this->_dh_lib[0]);
}

static void	changeLib()
{

}

static int	test(IGraphic &lib)
{
  int	i;
  
  while (1)
    {
      for (i = 1; i != 40; i++)
      	lib.buildCell(0, i, IGraphic::E_RED);
      for (i = 0; i != 39; i++)
      	lib.buildCell(i, 0, IGraphic::E_BLUE);
      for (i = 0; i != 39; i++)
      	lib.buildCell(39, i, IGraphic::E_GREEN);
      for (i = 1; i != 40; i++)
      	lib.buildCell(i, 39, IGraphic::E_YELLOW);
      if (lib.getKey() == IGraphic::E_C)
	changeLib();
      lib.refreshWindow();
      lib.clearWindow();
    }
}
