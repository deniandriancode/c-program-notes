#include <stdio.h>

int (*fptr)(int);
typedef int (*funcptr)(int);

int
square (int num)
{
  return num*num;
}

int
main (int argc,
      char **argv)
{
  /* As with array names, when */
  /* we use the name of a function by itself, it returns the function’s address */
  int square (int);
  int n = 5;
  fptr = square;
  funcptr fptr2 = square;
  int result = fptr2 (n);
  printf ("%d squared is %d\n", n, result);

  return 0;
}
