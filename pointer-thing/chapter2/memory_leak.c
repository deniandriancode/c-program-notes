#include <stdio.h>

void sample1 ();
void sample2 ();

void sample1 ()
{
  char *chunk;
  while (1)
  {
    chunk = (char *) malloc (100000);
    printf ("Allocating\n");
  }
}

void sample2 ()
{
  // An example of losing the address of memory is illustrated in the following code sequence
  // where pi is reassigned a new address. The address of the first allocation of memory is
  // lost when pi is allocated memory a second time.
  // free () never called
  int *pi = (int *) malloc (sizeof (int));
  *pi = 5;
  pi = (int *) malloc (sizeof (int));
}

int
main (int argc,
      char **argv)
{
  // A memory leak occurs when allocated memory is never used again but is not freed. This
  // can happen when:
  // • The memory’s address is lost
  // • The free function is never invoked though it should be (sometimes called a hidden
  // leak)
  return 0;
}
