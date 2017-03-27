#include <stdlib.h>
#include <dlfcn.h>

int	main(void)
{
	void (*external_function)(int);
	void* dlhandle;

	dlhandle = dlopen("./libkoala.so", RTLD_LAZY);
	if (dlhandle == NULL)
		exit(1);

	external_function = dlsym(dlhandle, "kreog_dance");
	if (external_function == NULL)
		exit(1);

	external_function(4);

	dlclose(dlhandle);

	return (0);
}
