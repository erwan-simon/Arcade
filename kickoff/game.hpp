//
// game.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Tue Mar  7 12:18:29 2017 Simon
// Last update Mon Mar 27 11:20:28 2017 Simon
//

class IGame
{
public:
  IGame() { }
  virtual ~IGame() { }

  virtual void start() const = 0;
};

class Game : public IGame
{
public:
  Game() {}
  ~Game() {}
};
