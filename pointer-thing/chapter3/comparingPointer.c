#include <stdio.h>

int
add (int num1, int num2)
{
  return num1 + num2;
}

int
subtract (int num1, int num2)
{
  return num1 - num2;
}

typedef int (*funcPtr)(int, int);

int
compute (funcPtr operation, int num1, int num2)
{
  return operation (num1, num2);
}

// returning function pointer
funcPtr
select (char opcode)
{
  switch (opcode) {
    case '+':
      return add;
    case '-':
      return subtract;
  }
}

int
evaluate (char opcode, int num1, int num2)
{
  funcPtr operation = select (opcode);
  return operation (num1, num2);
}

int
main (int argc,
      char **argv)
{
  funcPtr pointFun = add;
  if (pointFun == add)
  {
    printf("pointFun points to add function\n");
  }
  else
  {
    printf("pointFun does not points to add function\n");
  }
  /* When this is executed, the output will verify that the pointer does point to the add */
  /* function. */
  printf("%d\n", compute (add, 4, 6));
  printf("%d\n", evaluate ('-', 6, 4));
  return 0;
}
