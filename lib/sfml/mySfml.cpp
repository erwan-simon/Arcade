/*
** mySfml.cpp for mySfml in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Sat Apr  8 17:14:23 2017 Selim Rinaz
// Last update Tue Dec 19 18:21:55 2017 Erwan Simon
*/

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

void	mySfml::openWindow(const int &x, const int &y)
{
  this->_cellX = 0;
  this->_cellY = 0;
  this->_wd.create(sf::VideoMode(x * 20, y * 20), "Arcade", sf::Style::Close);
  this->setCell();
  this->_wd.display();
}

void	mySfml::refreshWindow()
{
  this->setCell();
  this->_wd.display();
}

void	mySfml::clearWindow()
{
  this->_wd.clear(sf::Color::Black);
}

void	mySfml::closeWindow()
{
  this->_wd.close();
}

IGraphic::e_key	mySfml::getKey() const
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
  return (E_NONE);
}

void	mySfml::setCell()
{
  sf::Vector2u size = this->_wd.getSize();

  this->_x = size.x;
  this->_y = size.x;
  this->_cellX = this->_x / 40;
  this->_cellY = this->_y / 40;
  this->_wd.pollEvent(this->_event);
}

void	mySfml::buildCell(const int &x, const int &y, const IGraphic::e_color &col)
{
  sf::RectangleShape rectangle(sf::Vector2f(this->_cellX, this->_cellY));
  rectangle.setFillColor(colorCell(col));
  rectangle.setPosition(x * this->_cellX, y * this->_cellY);
  this->_wd.draw(rectangle);
}

void	mySfml::writeStuff(const int &x, const int &y, const std::string& text)
{
  sf::Text      tx;
  sf::Font      font;
  std::string   s;

  if (!font.loadFromFile("./lib/sfml/Roboto.ttf"))
    exit (84);
  tx.setFont(font);
  tx.setCharacterSize(20);
  tx.setFillColor(sf::Color::Red);
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
}

extern "C"
{
  IGraphic* launch_lib()
  {
    return new mySfml();
  }
}
