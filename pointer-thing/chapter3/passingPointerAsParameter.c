#include <stdio.h>

void
swapItem (int *num1, int *num2)
{
  int tmp;
  tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}

int
main (int argc,
      char **argv)
{
  // One of the primary reasons for passing data using a pointer is to allow the function to
  // modify the data.
  void swapItem (int *, int *);
  int num1 = 5;
  int num2 = 10;
  printf ("num1 : %d num2 : %d\n", num1, num2);
  swapItem (&num1, &num2);
  printf ("num1 : %d num2 : %d\n", num1, num2);

  return 0;
}
