//
// IGraphic.hpp for  in /home/antoine/Rendu/C++/cpp_arcade/graphic
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Tue Mar 28 13:40:59 2017 Antoine
// Last update Tue Mar 28 14:32:54 2017 Antoine
//

#include <iostream>
#include <string>
#include <array>

class		IGraphic
{
public:		// Window
  virtual int		openWindow(int x, int y) = 0;
  virtual int		refreshWindow() = 0;
  virtual void		getStatus() = 0;
  virtual int		closeWindow() = 0;
  
  // BuildCell
  virtual int		buildCell(int x, int y) = 0;
};