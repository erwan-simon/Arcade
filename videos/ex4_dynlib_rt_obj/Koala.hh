#ifndef __KOALA_HH__
# define __KOALA_HH__

# include "IAssistant.hh" //Must include the interface from core

class Koala : public IAssistant
{
	public:
		virtual void talk() const;
};
#endif
