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

typedef int (*funcPtr) (int, int);
typedef int (*operation) (int, int);
operation operations[128] = {NULL};

int
compute (funcPtr operation, int num1, int num2)
{
  return operation (num1, num2);
}

void
initializeArray ()
{
  operations['+'] = add;
  operations['-'] = subtract;
}

int
evaluateArray (char opcode,
               int num1,
               int num2)
{
  funcPtr oper;
  oper = operations[opcode];
  return oper (num1, num2);
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
  printf("%d\n", compute (add, 4, 6));
  printf("%d\n", evaluate ('-', 6, 4));
  initializeArray ();
  printf("%d\n", evaluateArray ('+', 4, 9));
  return 0;
}
