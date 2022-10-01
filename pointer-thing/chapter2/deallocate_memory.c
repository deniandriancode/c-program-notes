#include <stdio.h>

void
freeSample ()
{
  /* The pointer argument should contain the address of memory allocated by a malloc type function. */
  int *pi = (int *) malloc (sizeof (int));
  ..
  free (pi);
  // but this will create dangling pointer
}

void
freeWithNull ()
{
  // to avoid dangling pointer
  int *pi = (int *) malloc (sizeof (int));
  ..
  free (pi);
  pi = NULL;
}

int
main (int argc,
      char **argv)
{
  return 0;
}
