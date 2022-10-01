#include <stdio.h>
#include <stdlib.h>
#define saferFree(p) safeFree((void*)&(p))

void
safeFree (void **pptr)
{
  if (pptr != NULL && *pptr != NULL)
  {
    free (*pptr);
    *pptr = NULL;
  }
}

int
main (int argc,
      char **argv)
{
  int i = 4;
  int *j = &i;
  saferFree (j);
  return 0;
}
