//
// main.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 14:11:45 2017 Simon
// Last update Sat Apr  8 16:12:23 2017 Antoine
//

#include <iostream>
#include <stdexcept>
#include <exception>
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
  try {
    Launcher	l(temp);
    l.launch();
  }
  catch(std::exception const& error)
    {
      std::cerr << "ERROR : " << error.what() << std::endl;
      return (84);
    }
  return (0);
}
