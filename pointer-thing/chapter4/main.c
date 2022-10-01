#include <stdio.h>

void demoCode ();
void multidimensionalArray ();
void threeDimensions ();
void arrayOfPointers ();

/* pointer of array */
void
demoCode ()
{
  // array declaration and initialization
  int a[5] = {5, 6, 7, 8, 9}, i;
	
  // Valid in case of arrays but not valid in case of single integer values.
  int *ptr = a;
	
  // All representations prints the base address of the array
  printf("ptr : %u, &a[0] : %u, a : %u, &a : %u\n", ptr, &a[0], a, &a);

  for(i = 0; i < 5; i++)
  {
	// printing address values
	printf("[index %d] Address : %u\n", i, (ptr + i));
  }

  printf("\n");

  for (i = 0; i < 5; i++)
  {
	// Accessing array values through pointer 
	// a[i] = *(a + i) = *(ptr + i) = *(i + a) = i[a]
	printf("[index %d] Value : %d %d %d %d\n", i, *(a + i), *(ptr + i), *(i + a), i[a]);
  }

  printf("\n");

  // Gives address of next byte after array's last element
  printf("&a : %u, &a + 1 : %u\n", &a, &a + 1);  

  // Gives the address of the next element
  printf("a : %u, a + 1 : %u\n", a, a + 1);

  // Gives value at index 1
  printf("*(a + 1) : %d\n", *(a + 1)); 
	
  // Gives (value at index 0) + 1
  printf("*a + 1 : %d\n", *a + 1);   
	
  // Gives (value at index 0) / 2, we can't perform *(p / 2) or *(p * 2)
  printf("(*ptr / 2) : %d\n", (*ptr / 2)); 
}

void
multidimensionalArray ()
{
  int arr[3][3] = {
    {2, 4, 6},
    {1, 3, 5},
    {4, 6, 8}
  };

  int i, j;

  // the below statement is wrong because
  // arr will return the address of a first 1-D array.
  // int *ptr = arr;
  // int *ptr = &arr[0]; is correct or we can write &arr[1], &arr[2].

  printf ("Addresses : \n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf ("%u[%d%d] ", (*(arr + i) + j), i, j);
    }
    printf ("\n");
  }

  printf ("Values : \n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf ("%d[%d%d] ", *(*(arr + i) + j), i, j);
    }
    printf ("\n");
  }
}

void
threeDimensions ()
{
  int arr[3][3][3] = {
    {1, 2, 3,   4, 5, 6,   7, 8, 9},
    {2, 4, 6,  8, 10, 12,  14, 16, 18},
    {3, 5, 7,  9, 11, 13,  15, 17, 19}
  };

  int i, j, k;

  // the below statement is wrong because
  // arr will return the address of a first 1-D array.
  // int *ptr = arr;
  // int *ptr = &arr[0][0]; is correct or we can write &arr[1][0], &arr[2][0].
  printf ("Addresses : \n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      for (k = 0; k < 3; k++)
      {
	printf ("%u[%d%d%d] ", (*(*(arr + i) + j) + k), i, j, k);
      }
      printf ("\n");
    }
  }

  printf ("Values : \n");
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      for (k = 0; k < 3; k++)
      {
	printf ("%d[%d%d%d] ", *(*(*(arr + i) + j) + k), i, j, k);
      }
      printf ("\n");
    }
  }
}

void
arrayOfPointers ()
{
  char *fruits[5] = {"apple", "banana", "mango", "grapes", "orange"}, i;

  for (i = 0; i < 5; i++)
  {
    printf ("%s ", fruits[i]);
  }
  printf ("\n");
}

int
main (int argc,
      char **argv)
{
  arrayOfPointers ();
}
