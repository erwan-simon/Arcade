//
// main.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 14:11:45 2017 Simon
// Last update Fri Mar 31 14:40:06 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"
#include "Launcher.hpp"

int             main(int ac, char **av)
{
  Launcher	l;

  if (ac != 2)
    {
      std::cerr << "Need an argument" << std::endl;
      return (1);
    }
  return (0);
}
