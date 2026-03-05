#include "stack.h"

int main() {
  IntStack myStack;
  int length;

  printf("What is the initial size of the stack?\n");
  scanf("%d", &length);

  // creates
  create_int_stack(&myStack, length);

  // uses
  menu_int_stack(&myStack);

  // cleans the mess
  destroy_int(&myStack);
  return 0;
}