#ifndef __KOALA_H__
# define __KOALA_H__

typedef struct
{
  char const *	name;
  int	       	age;
  char const *	catchphrase;
}		koala;

koala *		new_koala(char const *, int, char const *);
void		introduce_koala(koala *);
void		delete_koala(koala *);

#endif
