//
// kickoff.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar  7 12:06:51 2017 Simon
// Last update Mon Mar 27 11:29:06 2017 Simon
//

#include <dlfcn.h>
#include <cstdlib>
#include "game.hpp"

typedef void (*openFct)();

int	main()
{
  void *handle;
  openFct open;
  IGame	*game;

  handle = dlopen("libDyn.so", RTLD_GLOBAL | RTLD_NOW);
  if (handle == NULL)
    return (1);
  open = (openFct)dlsym(handle, "handle");
  if (open == NULL)
    return (-1);
  game = open();
  game->start();
  delete game;
  dlclose(handle);
  return (0);
}
