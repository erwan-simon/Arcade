//
// launcher.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Wed Mar 29 17:30:33 2017 Simon
// Last update Thu Mar 30 11:16:55 2017 Simon
//

#include <iostream>
#include <dlfcn.h>
#include "./graphic/IGraphic.hpp"

int	main(int argc, char **argv)
{
  if (ac < 2)
    {
      std::cerr << "Usage : ./exemple4 <libXXX.so>" << std::endl;
      return(1);
    }

  IAssistant* (*external_creator)();
  void* dlhandle;

  dlhandle = dlopen(av[1], RTLD_LAZY);
  if (dlhandle == NULL)
    return(1);

  external_creator = reinterpret_cast<IAssistant* (*)()>(dlsym(dlhandle, "create_assistant"));
  if (external_creator == NULL)
    return(1);

  IAssistant* bob = external_creator(); //Object included from the library !

  bob->talk(); //Call the code of an unknown object from the code !

  dlclose(dlhandle);

  return (0);
}
