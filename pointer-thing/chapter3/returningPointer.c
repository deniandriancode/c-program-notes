#include <stdio.h>
#include <stdlib.h>

int *allocateArray (int , int);

int
*allocateArray (int size,
                int value)
{
  int *arr = (int*) malloc (size * sizeof (int));
  for (int i = 0; i < size; i++)
  {
    arr[i] = value;
  }
  return arr;
}

int
main (int argc,
      char **argv)
{
  int *vector = allocateArray (5, 48);
  for(int i=0; i<5; i++) {
    printf("%d\n", vector[i]);
  }
  return 0;
}
