//
// mySfml.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/lib/sfml
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Thu Mar 30 15:07:11 2017 Antoine
// Last update Tue Apr  4 10:53:41 2017 Antoine
//

#ifndef MYSFML_HPP_
# define MYSFML_HPP_

# include "./../../graphic/IGraphic.hpp"

class				mySfml : public IGraphic
{
public:
  mySfml();
  virtual int			openWindow(int x, int y);
  virtual int			refreshWindow();
  virtual int			clearWindow();
  virtual int			closeWindow();
  virtual IGraphic::e_key	getKey();

  // Draw
  virtual int			buildCell(int x, int y, e_color col);
  virtual int			writeStuff(int x, int y, std::string& text);
  int				setCell();

  // private:
public:
  sf::RenderWindow		_wd;
  sf::Event			_event;
  int				_y;
  int				_x;
  int				_cellY;
  int				_cellX;
  // int				_marginY;
  // int				_marginX;
};

#endif
