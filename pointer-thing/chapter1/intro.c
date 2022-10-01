#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
main (int argc,
      char **argv)
{
  int num = 0;
  int *pi = &num;

  printf ("Address of num : %d    Value : %d\n", &num, num);
  printf ("Address of pi : %d     Value : %d\n", &pi, pi);
  printf ("Address of pi : %x     Value : %x\n", &pi, pi);
  printf ("Address of pi : %o     Value : %o\n", &pi, pi);
  printf ("Address of pi : %p     Value : %p\n", &pi, pi);

  system ("clear");

  int num1 = 5;
  int *pi1 = &num1;

  printf ("%p\n", *pi1);
  *pi1 = 200;
  printf ("%d\n", num1);

  /* Always use the sizeof operator when the size of a pointer is needed. */
  printf ("Size of *char pointer is : %d\n", sizeof (char *));

  /* The types intptr_t and uintptr_t are used for storing pointer addresses */
  int num2 = 14;
  intptr_t *pi2 = (intptr_t *)&num2;
  printf ("Address of pi2 is : %p\n", pi2);

  return 0;
}
