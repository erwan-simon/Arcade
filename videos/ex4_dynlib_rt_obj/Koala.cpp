#include <iostream>
#include "Koala.hh"

//Implementation of method talk()
void Koala::talk() const
{
	std::cout << "Koala says KREOOOOOOOOOOG !" << std::endl;
}

//Function to create a Koala
//Will be called from code to get a Koala instance

extern "C"
{
	IAssistant* create_assistant()
	{
		return new Koala();
	}
}
