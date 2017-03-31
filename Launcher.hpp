//
// Launcher.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 13:51:50 2017 Simon
// Last update Fri Mar 31 15:12:23 2017 Simon
//

#ifndef LAUNCHER_HPP_
# define LAUNCHER_HPP_

#include "./graphic/IGraphic.hpp"

class Launcher {
public:
  Launcher();
  ~Launcher();

private:
  IGraphic**	_lib;
  void**	_dh_lib;
};

#endif
