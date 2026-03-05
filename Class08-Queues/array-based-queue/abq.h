#ifndef ABQ_H
#define ABQ_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  int head;
  int tail;
  int count;
  int capacity;
} CircularQueue;

CircularQueue *createQueue(int capacity) {
  CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
  if (!q)
    return NULL;

  q->array = (int *)malloc(sizeof(int) * capacity);
  if (!q->array) {
    free(q);
    return NULL;
  }

  q->head = 0;
  q->tail = -1; // starts at -1 because first enqueue will set it to 0
  q->count = 0;
  q->capacity = capacity;

  return q;
}

bool isFull(CircularQueue *q) { return q->count == q->capacity; }

bool isEmpty(CircularQueue *q) { return q->count == 0; }

bool enqueue(CircularQueue *q, int value) {
  if (isFull(q)) {
    printf("Erro: A fila esta cheia!\n");
    return false;
  }

  // when it gets to the end, comes back to the start
  q->tail = (q->tail + 1) % q->capacity;

  q->array[q->tail] = value;
  q->count++;
  return true;
}

// removes by increasing the head
int dequeue(CircularQueue *q, bool *success) {
  if (isEmpty(q)) {
    printf("Erro: A fila esta vazia!\n");
    if (success)
      *success = false;
    return -1;
  }

  int value = q->array[q->head];

  // head should also be circular
  q->head = (q->head + 1) % q->capacity;

  q->count--;
  if (success)
    *success = true;

  return value;
}

void freeQueue(CircularQueue *q) {
  if (q) {
    free(q->array);
    free(q);
  }
}

void menu(CircularQueue *q) {
  int option;
  int value;

  do {
    printf("\n--- MENU ---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Is Full\n");
    printf("4. Is Empty\n");
    printf("5. Exit\n");
    printf("Choose: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      printf("Input the value:\n");
      scanf("%d", &value);
      enqueue(q, value);
      break;
    case 2: {
      bool operacao_ok;
      int removed = dequeue(q, &operacao_ok);
      
      if (operacao_ok) {
        printf("Removed: %d\n", removed);
      }
      break;
    }
    case 3:
      printf("Is Full: %d\n", isFull(q));
      break;
    case 4:
      printf("Is Empty: %d\n", isEmpty(q));
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid option!\n");
    }
  } while (option != 5);
}

#endif