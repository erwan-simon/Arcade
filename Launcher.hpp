//
// Launcher.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 13:51:50 2017 Simon
// Last update Fri Mar 31 17:17:45 2017 Simon
//

#ifndef LAUNCHER_HPP_
# define LAUNCHER_HPP_

#include "./graphic/IGraphic.hpp"

class Launcher {
public:
  Launcher(std::string &lib);
  ~Launcher();

  void		launch();
  void		changeLib(int *);
private:
  IGraphic*	_lib;
  void*		_dh_lib;
  std::string*	_lib_name;
};

#endif
