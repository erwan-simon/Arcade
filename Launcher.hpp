//
// Launcher.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 13:51:50 2017 Simon
// Last update Mon Apr  3 13:36:16 2017 Simon
//

#ifndef LAUNCHER_HPP_
# define LAUNCHER_HPP_

#include "./graphic/IGraphic.hpp"

class Launcher {
public:
  Launcher(std::string &lib);
  ~Launcher();

  void		launch();
  void		changeLib();
  void		writeMenu();
  void		buildFrame();
  int		interact();

private:
  IGraphic*	_lib;
  int		_current;
  void*		_dh_lib;
  std::string*	_lib_name;
  std::string*	_game_name;
};

#endif
