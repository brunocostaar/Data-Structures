#include "arraylist.h"

int main() {
  List myList;
  int length;

  printf("What is the size of the list?\n");
  scanf("%d", &length);

  // creates
  create_list(&myList, length);

  // uses
  menu_list(&myList);

  // cleans the mess
  destroy(&myList);
  return 0;
}