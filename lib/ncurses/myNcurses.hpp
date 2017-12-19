/*
** myNcurses.hpp for myNcurses in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 16:40:15 2017 Selim Rinaz
// Last update Sun Apr  9 13:06:59 2017 Simon
*/

#ifndef MYNCURSES_HPP_
# define MYNCURSES_HPP_

# include "IGraphic.hpp"

class myNcurses : public IGraphic
{
public:
  myNcurses() {};
  virtual ~myNcurses() {};
  
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

private:
  WINDOW			*win;
};

#endif
