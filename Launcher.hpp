//
// Launcher.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Fri Mar 31 13:51:50 2017 Simon
// Last update Wed Apr  5 17:47:47 2017 Simon
//

#ifndef LAUNCHER_HPP_
# define LAUNCHER_HPP_

#include "./games/include/IGame.hpp"
#include "./graphic/IGraphic.hpp"

class Launcher {
public:
  Launcher(std::string &lib);
  ~Launcher();

  void		launch();
  void		changeLib(IGraphic::e_key key);
  void		changeGame(IGraphic::e_key key);
  void		writeMenu();
  void		buildFrame();
  int		interact(IGraphic::e_key key);
  void		play();
  void		graphPlay();

public:
  IGraphic*	_lib;
  IGame*	_game;

private:
  // Graphic lib
  int		_current_lib;
  void*		_dh_lib;
  std::string*	_lib_name;

  // Game lib
  int		_current_game;
  void*		_dh_game;
  std::string*	_game_name;
};

#endif
