//
// launcher.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:30:33 2017 Simon
// Last update Thu Mar 30 15:11:19 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include "./graphic/IGraphic.hpp"

int	main(int ac, char **av)
{
  if (ac < 2)
    {
      std::cerr << "Usage : ./exemple4 <libXXX.so>" << std::endl;
      return (1);
    }

  IGraphic* (*external_creator)();
  void* dlhandle;

  dlhandle = dlopen(av[1], RTLD_LAZY);
  if (dlhandle == NULL)
    return (1);

  external_creator = reinterpret_cast<IGraphic* (*)()>(dlsym(dlhandle, "create_assistant"));
  if (external_creator == NULL)
    return (1);

  IGraphic* bob = external_creator(); //Object included from the library !
  bob->openWindow(40, 40);
  bob->closeWindow();
  dlclose(dlhandle);

  return (0);
}
