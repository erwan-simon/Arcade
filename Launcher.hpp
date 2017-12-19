/*
** Launcher.hpp for Launcher in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:52:41 2017 Selim Rinaz
** Last update Sat Apr  8 16:53:25 2017 Selim Rinaz
*/

#ifndef LAUNCHER_HPP_
# define LAUNCHER_HPP_

#include "IGame.hpp"
#include "IGraphic.hpp"

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
  void		drawMap();

private:
  IGame::e_end	_end;
  int		_score;
  // Graphic lib
  IGraphic*	_lib;
  int		_current_lib;
  void*		_dh_lib;
  std::string*	_lib_name;

  // Game lib
  IGame*	_game;
  int		_current_game;
  void*		_dh_game;
  std::string*	_game_name;
};

#endif
