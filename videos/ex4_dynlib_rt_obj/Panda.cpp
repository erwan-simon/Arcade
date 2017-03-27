#include <iostream>
#include "Panda.hh"

//Implementation of method talk()
void Panda::talk() const
{
	std::cout << "Panda says PONEY PONEY !" << std::endl;
}

//Function to create a Panda
//Will be called from code to get a Panda instance

extern "C"
{
	IAssistant* create_assistant()
	{
		return new Panda();
	}
}
