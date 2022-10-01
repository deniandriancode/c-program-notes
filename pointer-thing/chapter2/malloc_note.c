#include <stdio.h>

int
main (int argc,
      char **argv)
{
  /* In the following example, an attempt is made to allocate memory for 10 doubles, we need to allocate 80 bytes. */
  const int NUMBER_OF_DOUBLES = 10;
  double *pi = (double *) malloc (NUMBER_OF_DOUBLES * sizeof (double));
  return 0;
}
