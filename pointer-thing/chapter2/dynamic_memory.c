#include <stdio.h>
#include <stdlib.h>

int
main (int argc,
      char **argv)
{
  int *pi = (int *) malloc (sizeof (int));
  *pi = 5;
  printf ("*p : %p\n", *pi);
  free (pi);

  return 0;
}
