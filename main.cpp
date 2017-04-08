/*
** main.cpp for main in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 17:05:27 2017 Selim Rinaz
** Last update Sat Apr  8 17:05:28 2017 Selim Rinaz
*/

#include <iostream>
#include <dlfcn.h>
#include "IGame.hpp"
#include "IGraphic.hpp"
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
