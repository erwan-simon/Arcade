/*
** AException.hpp for AException in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Wed Apr  5 15:55:26 2017 Selim Rinaz
** Last update Wed Apr  5 16:13:18 2017 Selim Rinaz
*/

#ifndef AEXCEPTION_HPP_
# define AEXCEPTION_HPP_

# include <exception>
# include <ostream>

class			AException : public std::exception
{
  const std::string	message;
  const int		status;

  public:
  AException(const std::string &message, const int status) throw();
  virtual ~AException() throw();
 
  virtual const std::string what() const throw(); // Return error infos
}

#endif /* !AEXCEPTION_HPP_ */
