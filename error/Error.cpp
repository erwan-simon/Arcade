/*
** AException.cpp for AException in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/error
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Thu Apr  6 18:08:16 2017 Selim Rinaz
** Last update Fri Apr  7 19:40:17 2017 Selim Rinaz
*/

#include "Error.hpp"

Error::Error(const std::string &message, const int status) : message(message),
								     status(status)
{
}

Error::~Error() throw()
{
}

const char*		Error::what() const throw()
{
  std::string		str;
  
  str = "Erreur : ";
  str += this->message;
  str += " de type ";
  str += this->status;
  return (str.c_str());
}
