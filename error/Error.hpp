/*
** AException.hpp for AException in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Wed Apr  5 15:55:26 2017 Selim Rinaz
** Last update Fri Apr  7 19:35:33 2017 Selim Rinaz
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <exception>
# include <ostream>

class Error: public std::exception
{
public:
  Error(std::string const &message = "", int type = 0);
  virtual               ~Error() throw();

  virtual const char*   what() const throw();
  
private:
  std::string	message;
  int           status;
};

#endif /* !Error_HPP_ */
