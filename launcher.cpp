//
// launcher.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:30:33 2017 Simon
// Last update Thu Mar 30 16:45:08 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"

int	test(IGraphic &lib)
{
  int	i;
  
  while (1)
    {
      for (i = 0; i != 40; i++)
	lib.buildCell(0, i, IGraphic::E_RED);
      for (i = 0; i != 40; i++)
	lib.buildCell(i, 0, IGraphic::E_BLUE);
      for (i = 0; i != 40; i++)
	lib.buildCell(40, i, IGraphic::E_GREEN);
      for (i = 0; i != 40; i++)
	lib.buildCell(i, 40, IGraphic::E_YELLOW);
      lib.refreshWindow();
    }
}

int	main(int ac, char **av)
{
  if (ac < 2)
    {
      std::cerr << "Usage : ./exemple4 <libXXX.so>" << std::endl;
      return (1);
    }

  IGraphic* (*launch_lib)();
  void* dlhandle;

  dlhandle = dlopen(av[1], RTLD_LAZY);
  if (dlhandle == NULL)
    return (1);
  launch_lib = reinterpret_cast<IGraphic* (*)()>(dlsym(dlhandle, "launch_lib"));
  if (launch_lib == NULL)
    return (1);
  IGraphic* lib = launch_lib(); //Object included from the library !
  lib->openWindow(40, 40);
  test(*lib);
  lib->closeWindow();
  dlclose(dlhandle);
  return (0);
}
