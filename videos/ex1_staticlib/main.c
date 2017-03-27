#include "koala.h"

int	main(void)
{
	/*
	 * Functions from the library
	 */
	koala* zaz = new_koala("zaz", 23, "arrr, so boring !");
	introduce_koala(zaz);
	delete_koala(zaz);

	return (0);
}
