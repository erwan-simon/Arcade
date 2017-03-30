//
// mySfml.cpp for  in /home/antoine/Rendu/C++/cpp_arcade/lib/sfml
// 
// Made by Antoine
// Login   <antoine@epitech.eu>
// 
// Started on  Thu Mar 30 15:11:07 2017 Antoine
// Last update Thu Mar 30 15:27:47 2017 Antoine
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "mySfml.hpp"

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
  this->_wd.create(sf::VideoMode(x * 20, y * 20), "Arcade");
  this->_wd.display();
  this->setCell();
  return (0);
}

int     mySfml::refreshWindow()
{
  sf::Vector2u size = this->_wd.getSize();

  this->_y = size.y;
  this->_x = size.x;
  this->_wd.pollEvent(this->_event);
  this->setCell();
  this->_wd.display();
  return (0);
}

int     mySfml::clearWindow()
{
  this->_wd.clear(sf::Color::Black);
  return (0);
}

int     mySfml::closeWindow()
{
  this->_wd.close();
  return (0);
}

int     mySfml::getKey()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    return (E_LEFT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    return (E_RIGHT);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    return (E_DOWN);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    return (E_UP);
  return (-1);
}

int     mySfml::setCell()
{
  // this->_cellY = this->_cellX;                                                                      
  this->_cellX = this->_x / 40;
  this->_cellY = this->_y / 40;
  // this->_cellX = this->_cellY;                                                                      
  return (0);
}

int     mySfml::buildCell(int x, int y, IGraphic::e_color col)
{
  sf::RectangleShape rectangle(sf::Vector2f(this->_cellX, this->_cellY));
  // rectangle.setSize(sf::Vector2f(this->_cellX, this->_cellX));                                      
  rectangle.setFillColor(colorCell(col));
  rectangle.setPosition(x * this->_cellX, y * this->_cellY);
  this->_wd.draw(rectangle);
  return (0);
}
