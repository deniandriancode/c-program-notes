#include <stdio.h>

void add_int_pointer ();
void subtract_int_pointer ();
void subtract_two_pointer ();
void compare_pointer ();

void add_int_pointer ()
{
  /* adding integer to pointer */
  int vector[] = {28, 41, 7};
  int *pi = vector;

  printf ("%d\n", *pi);
  pi += 1;
  printf ("%d\n", *pi);
  pi++;
  printf ("%d\n", *pi);
  pi++;
  printf ("%p\n", pi);
}

void subtract_int_pointer ()
{
  /* subtracting integer from pointer */
  int vector[] = {28, 41, 7};
  int *pi = vector + 2;  // plus two here mean, we increment the pointer twice, see add_int_pointer function
  printf ("%d\n", *pi);
  pi--;
  printf ("%d\n", *pi);
  pi--;
  printf ("%d\n", *pi);
  pi--;
}

void subtract_two_pointer ()
{
  int vector[] = {28, 41, 7};
  int *p0 = vector;
  int *p1 = vector+1;
  int *p2 = vector+2;
  printf("p2-p0: %d\n",p2-p0);
  printf("p2-p1: %d\n",p2-p1);
  printf("p0-p1: %d\n",p0-p1);
  // p2-p0: 2
  // p2-p1: 1
  // p0-p1: -1
}

void compare_pointer ()
{
  /* their results are displayed as 1 for true and 0 for false */
  int vector[] = {28, 41, 7};
  int *p0 = vector;
  int *p1 = vector+1;
  int *p2 = vector+2;

  printf ("p2>p0 : %d\n", p2 > p0);
  printf ("p2<p0 : %d\n", p2 < p0);
  printf ("p0>p1 : %d\n", p0 > p1);
}

int
main (int argc,
      char **argv)
{
  compare_pointer ();
  return 0;
}
