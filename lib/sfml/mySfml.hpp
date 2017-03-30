//
// mySfml.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/lib/sfml
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Thu Mar 30 15:07:11 2017 Antoine
// Last update Thu Mar 30 15:10:33 2017 Antoine
//

#ifndef MYSFML_HPP_
# define MYSFML_HPP_

# include "./../../graphic/IGraphic.hpp"

class           mySfml : public IGraphic
{
public:
  virtual int   openWindow(int x, int y);
  virtual int   refreshWindow();
  virtual int   clearWindow();
  virtual int   closeWindow();
  virtual int   getKey();

  // BuildCell                                                               
  virtual int   buildCell(int x, int y, e_color col);
  int		setCell();
// private:                                                                                            
public:
  sf::RenderWindow      _wd;
  sf::Event             _event;
  int                   _y = 0;
  int                   _x = 0;
  int                   _cellY = 0;
  int                   _cellX = 0;
  int                   _marginY = 0;
  int                   _marginX = 0;
};

#endif
