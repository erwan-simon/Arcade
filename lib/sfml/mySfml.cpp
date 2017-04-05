//
// mySfml.cpp for  in /home/antoine/Rendu/C++/cpp_arcade/lib/sfml
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Thu Mar 30 15:11:07 2017 Antoine
// Last update Tue Apr  4 15:04:17 2017 Simon
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "mySfml.hpp"

mySfml::mySfml()
  : _wd(), _event(), _y(), _x(), _cellY(), _cellX()
{
}

static sf::Color	colorCell(IGraphic::e_color col)
{
  if (col == IGraphic::E_WHITE)
    return (sf::Color::White);
  if (col == IGraphic::E_YELLOW)
    return (sf::Color::Yellow);
  if (col == IGraphic::E_RED)
    return (sf::Color::Red);
  if (col == IGraphic::E_BLUE)
    return (sf::Color::Blue);
  if (col == IGraphic::E_PINK)
    return (sf::Color::Magenta);
  if (col == IGraphic::E_GREEN)
    return (sf::Color::Green);
  return (sf::Color::Black);
}

int	mySfml::openWindow(int x, int y)
{
  this->_cellX = 0;
  this->_cellY = 0;
  this->_wd.create(sf::VideoMode(x * 20, y * 20), "Arcade", sf::Style::Close);
  this->setCell();
  this->_wd.display();
  return (0);
}

int	mySfml::refreshWindow()
{
  // sf::Vector2u size = this->_wd.getSize();

  // this->_y = size.y;
  // this->_x = size.x;
  // this->_wd.pollEvent(this->_event);
  this->setCell();
  this->_wd.display();
  return (0);
}

int	mySfml::clearWindow()
{
  this->_wd.clear(sf::Color::Black);
  return (0);
}

int	mySfml::closeWindow()
{
  this->_wd.close();
  return (0);
}

IGraphic::e_key	mySfml::getKey()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    return (E_LEFT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    return (E_RIGHT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    return (E_DOWN);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    return (E_UP);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    return (E_2);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    return (E_3);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    return (E_4);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    return (E_5);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
    return (E_8);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
    return (E_9);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return (E_ESC);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    return (E_ENT);
  return (E_NONE);
}

int	mySfml::setCell()
{
  sf::Vector2u size = this->_wd.getSize();


  this->_x = size.x;
  this->_y = size.x;
  // this->_cellY = this->_cellX;
  this->_cellX = this->_x / 40;
  this->_cellY = this->_y / 40;
  
  // if (size.y > size.x)
  //   {
  //     this->_x = size.x;
  //     this->_y = size.x;
  //     // this->_cellY = this->_cellX;
  //     this->_cellX = this->_x / 40;
  //     this->_cellY = this->_y / 40;
  //     // this->_cellX = this->_cellY;
  //   }
  // else
  //   {
  //     this->_y = size.y;
  //     this->_x = size.y;
  //     // this->_cellY = this->_cellX;
  //     this->_cellX = this->_x / 40;
  //     this->_cellY = this->_y / 40;
  //     // this->_cellX = this->_cellY;
  //   }
  // std::cout << "size.x = " << size.x << " | size.y = " << size.y << std::endl;
  // std::cout << "Cellx = " << this->_cellX * 40 << " | Celly = " << this->_cellY * 40
  // 	    << std::endl << std::endl;;
  this->_wd.pollEvent(this->_event);
  return (0);
}

int	mySfml::buildCell(int x, int y, IGraphic::e_color col)
{
  sf::RectangleShape rectangle(sf::Vector2f(this->_cellX, this->_cellY));
  // rectangle.setSize(sf::Vector2f(this->_cellX, this->_cellX));
  rectangle.setFillColor(colorCell(col));
  rectangle.setPosition(x * this->_cellX, y * this->_cellY);
  this->_wd.draw(rectangle);
  return (0);
}

int	mySfml::writeStuff(int x, int y, std::string& text)
{
  sf::Text      tx;
  sf::Font      font;
  std::string   s;

  if (!font.loadFromFile("./lib/sfml/Roboto.ttf"))
    exit (84);
  tx.setFont(font);
  tx.setCharacterSize(20);
  tx.setColor(sf::Color::Red);
  tx.setString(text);
  tx.setPosition(sf::Vector2f(x * this->_cellX, y * this->_cellY));
  unsigned int  i = 0;
  while(i < text.size())
    {
      s = text.at(i);
      tx.setString(s);
      tx.setPosition(sf::Vector2f((x * this->_cellX) + (i * this->_cellX), y * this->_cellY));
      this->_wd.draw(tx);
      i += 1;
    }
  return (0);
}

extern "C"
{
  IGraphic* launch_lib()
  {
    return new mySfml();
  }
}
