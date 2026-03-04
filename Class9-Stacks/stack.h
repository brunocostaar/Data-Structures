#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *vector;
  int length;
  int i;
} IntStack;

typedef struct {
    char *vector;
    int length;
    int i;
} CharStack;

void create_int_stack(IntStack *stack, int length) {
  stack->vector = (int *)malloc(length * sizeof(int));
  if (stack->vector == NULL) {
    printf("Unsuccesful memory allocation.");
    exit(1);
  }
  stack->length = length;
  stack->i = -1;
};

int isEmpty_int(IntStack *stack){
    if(stack->i < 0) return 1;
    return 0;
}

int push_int(IntStack *stack, int value) {
  if (stack->i == stack->length - 1) {
    int new_size = stack->length * 2;
    int *temp = (int *)realloc(stack->vector, new_size * sizeof(int));
    if (temp == NULL) {
      printf("No more space in memory");
      return 0;
    }
    stack->vector = temp;
    stack->length = new_size;
  }
  (stack->i)++;
  stack->vector[stack->i] = value;
  return 1;
}

int pop_int(IntStack *stack) {
  if (stack->i == -1) {
    printf("Empty stack, cannot pop.");
    return -1;
  }
  (stack->i)--;
  return 1;
}

int destroy_int(IntStack *stack) {
  free(stack->vector);
  stack->vector = NULL;
  stack->length = 0;
  stack->i = -1;
  return 1;
}

int print_top_int(IntStack* stack) {
  if (stack->i < 0) {
    printf("Error: Empty stack");
    return -1;
  }
  printf("Top element: %d\n", stack->vector[stack->i]);
  return stack->vector[stack->i];
}

void menu_int_stack(IntStack* stack){
    int option;
    int value;

    do {
    printf("\n--- MENU ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print Top\n");
    printf("0. Exit\n");
    printf("Choose: ");
    scanf("%d", &option);

    switch (option)
        {
        case 1:
            printf("Input the value:\n");
            scanf("%d", &value);
            push_int(stack, value);
            break;
        case 2:
            pop_int(stack);
            printf("Removed!\n");
            break;
        case 3:
            print_top_int(stack);
            break;
        case 0:
            printf("Exiting");
            break;
        default:
            printf("Invalid option!");
            break;
        }
    } while(option != 0);
}

void create_char_stack(CharStack *stack, int length) {
  stack->vector = (char *)malloc(length * sizeof(char));
  if (stack->vector == NULL) {
    printf("Unsuccesful memory allocation.");
    exit(1);
  }
  stack->length = length;
  stack->i = -1;
}

int isEmpty_char(CharStack *stack){
    if(stack->i < 0) return 1;
    return 0;
}

int push_char(CharStack *stack, char value) {
  if (stack->i == stack->length - 1) {
    int new_size = stack->length * 2;
    char *temp = (char *)realloc(stack->vector, new_size * sizeof(char));
    if (temp == NULL) {
      printf("No more space in memory");
      return 0;
    }
    stack->vector = temp;
    stack->length = new_size;
  }
  (stack->i)++;
  stack->vector[stack->i] = value;
  return 1;
}

int pop_char(CharStack *stack) {
  if (stack->i == -1) {
    printf("Empty stack, cannot pop.");
    return 0;
  }
  (stack->i)--;
  return 1;
}

int destroy_char(CharStack *stack) {
  free(stack->vector);
  stack->vector = NULL;
  stack->length = 0;
  stack->i = -1;
  return 1;
}

int print_top_char(CharStack* stack) {
  if (stack->i < 0) {
    printf("Error: Empty stack");
    return -1;
  }
  printf("Top element: %c\n", stack->vector[stack->i]);
  return stack->vector[stack->i];
}

void menu_char_stack(CharStack* stack){
    int option;
    char value;

    do {
    printf("\n--- MENU ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print Top\n");
    printf("0. Exit\n");
    printf("Choose: ");
    scanf("%d", &option);

    switch (option)
        {
        case 1:
            printf("Input the value:\n");
            scanf(" %c", &value);
            push_char(stack, value);
            break;
        case 2:
            pop_char(stack);
            printf("Removed!\n");
            break;
        case 3:
            print_top_char(stack);
            break;
        case 0:
            printf("Exiting");
            break;
        default:
            printf("Invalid option!");
            break;
        }
    } while(option != 0);
}

#endif