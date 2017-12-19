/*
** mySfml.hpp for mySfml in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:44:35 2017 Selim Rinaz
// Last update Sun Apr  9 13:06:29 2017 Simon
*/

#ifndef MYSFML_HPP_
# define MYSFML_HPP_

# include "IGraphic.hpp"

class				mySfml : public IGraphic
{
public:
  mySfml();
  virtual ~mySfml() {};
  
  // Window
  virtual void			openWindow(const int &x, const int &y);
  virtual void			refreshWindow();
  virtual void			clearWindow();
  virtual void			closeWindow();
  virtual IGraphic::e_key	getKey() const;

  // Draw
  virtual void			buildCell(const int &x,
					  const int &y,
					  const e_color &col);
  virtual void			writeStuff(const int &x,
					   const int &y,
					   const std::string& text);
  void				setCell();

  private:
  sf::RenderWindow		_wd;
  sf::Event			_event;
  int				_y;
  int				_x;
  int				_cellY;
  int				_cellX;
};

#endif
