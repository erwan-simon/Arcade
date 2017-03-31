//
// main.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 14:11:45 2017 Simon
// Last update Fri Mar 31 17:19:22 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"
#include "Launcher.hpp"

int             main(int ac, char **av)
{
  std::string	temp;
  
  if (ac != 2)
    {
      std::cerr << "Need an argument" << std::endl;
      return (1);
    }
  temp = av[1];
  Launcher	l(temp);
  l.launch();
  return (0);
}
