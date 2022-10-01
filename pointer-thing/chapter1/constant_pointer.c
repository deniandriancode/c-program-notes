#include <stdio.h>

void constant_to_non ();
void constant_to_constant ();
void pointer_to_constant_pointer ();

void constant_to_non ()
{
  // We can also declare a constant pointer to a nonconstant. When we do this, it means that
  // while the pointer cannot be changed, the data pointed to can be modified. An example
  // of such a pointer follows:
  int num = 8;
  const int limit = 500;
  int *const cpi = &num;
  // The following are two valid assignments:
  *cpi = limit;
  *cpi = 200;
}

void constant_to_constant ()
{
  // A constant pointer to a constant is an infrequently used pointer type. The pointer cannot
  // be changed, and the data it points to cannot be changed through the pointer
  int num = 6;
  const int limit = 500;
  const int *const cpc = &limit;
}

void pointer_to_constant_pointer ()
{
  // Pointer to (constant pointer to constant)
  const int limit = 500;
  const int *const cpci = &limit;
  const int *const *pcpi = &cpci;  // kind of double pointer
}

int
main (int argc,
      char **argv)
{
  /* We cannot dereference a constant pointer to change what the pointer references, but
   * we can change the pointer. The pointer value is not constant. The pointer can be changed
   * to reference another constant integer or a simple integer. */
  int num = 5;
  const int limit = 500;
  int *pi;
  const int *pci;
  
  pi = &num;
  pci = &limit;
  /* this statement is legal */
  pci = &num;


  return 0;
}
