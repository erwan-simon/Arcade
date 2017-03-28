//
// NetCom.hpp for  in /home/brilla_a//pentacle/bptc++/netabs
// 
// Made by jason brillante
// Login   <brilla_a@epitech.net>
// 
// Started on  Mon Jan 16 18:52:29 2012 jason brillante
// Last update Mon Jan 16 18:54:40 2012 jason brillante
//

#ifndef				__NETABS_HPP__
# define			__NETABS_HPP__
# ifdef				_WIN32
# include			"NetWin.hpp"

namespace			bpt
{
  namespace			NetAbs
  {
    class			NetAbs : public NetWin
    {};
  }
}

# else
# include			"NetUnix.hpp"

namespace			bpt
{
  namespace			NetAbs
  {
    class			NetAbs : public NetUnix
    {};
  }
}

# endif	//			_WIN32
#endif	//			__NETABS_HPP__
