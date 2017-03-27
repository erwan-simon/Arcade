#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "koala.h"

static koala*	alloc_koala()
{
	koala* 		ret = (koala*)malloc(1 * sizeof(*ret));

	return ret;
}

static void		init_koala(koala* k, char const * name, int age, char const * catchphrase)
{
	k->name = strdup(name);
	k->age = age;
	k->catchphrase = strdup(catchphrase);
}

koala*			new_koala(char const * name, int age, char const * catchphrase)
{
	koala*		ret = alloc_koala();

	if (ret != NULL)
		init_koala(ret, name, age, catchphrase);

	return ret;
}

void			delete_koala(koala* k)
{
	free((void*)(k->name));
	free((void*)(k->catchphrase));
	free(k);
}

void			introduce_koala(koala* k)
{
	printf("%s is %d years old and says : \"%s\"\n", k->name, k->age, k->catchphrase);
}
