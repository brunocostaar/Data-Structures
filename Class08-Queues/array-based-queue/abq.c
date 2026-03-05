#include "abq.h"

int main() {
  int capacity;
  printf("Input queue capacity: ");
  scanf("%d", &capacity);
  CircularQueue *q = createQueue(capacity);

  menu(q);

  freeQueue(q);
  return 0;
}