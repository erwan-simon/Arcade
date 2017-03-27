#include <iostream>
#include <dlfcn.h>
#include "IAssistant.hh" //Include only the interface

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << "Usage : ./exemple4 <libXXX.so>" << std::endl;
		return(1);
	}

	IAssistant* (*external_creator)();
	void* dlhandle;

	dlhandle = dlopen(av[1], RTLD_LAZY);
	if (dlhandle == NULL)
		return(1);

	external_creator = reinterpret_cast<IAssistant* (*)()>(dlsym(dlhandle, "create_assistant"));
	if (external_creator == NULL)
		return(1);

	IAssistant* bob = external_creator(); //Object included from the library !

	bob->talk(); //Call the code of an unknown object from the code !

	dlclose(dlhandle);

	return (0);
	
}
