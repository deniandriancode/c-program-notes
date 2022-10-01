#include <stdio.h>

void allocateArray (int **, int, int);

void
allocateArray (int **arr,
               int size,
               int value)
{
  *arr = (int*) malloc (size * sizeof (int));
  if (*arr != NULL)
  {
    for (int i = 0; i < size; i++)
    {
      *(*arr+i) = value;
    }
  }
}

int
main (int argc,
      char **argv)
{
  /* When a pointer is passed to a function, it is passed by value. If we want to modify the */
  /* original pointer and not the copy of the pointer, we need to pass it as a pointer to a */
  /* pointer */
  int *vector = NULL;
  allocateArray (&vector, 5, 45);

  return 0;
}
