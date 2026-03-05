#ifndef DLLQ_H
#define DLLQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} Node;

// --- Linked List Functions ---
void push(Node **phead, Node **ptail, int value) {
  Node *new_node;
  new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;
  if (*phead == NULL) {
    *phead = new_node;
    *ptail = new_node;
    new_node->prev = NULL;
  } else {
    (*ptail)->next = new_node;
    new_node->prev = *ptail;
    *ptail = new_node;
  }
}

void remove_first(Node **phead, Node **ptail) {
  if (*phead == NULL) {
    printf("List is already empty\n");
  } else {
    Node *temp = *phead;
    if (temp->next == NULL) {
      *ptail = NULL;
      *phead = NULL;
    } else {
      *phead = temp->next;
      (*phead)->prev = NULL;
    }
    free(temp);
  }
}

void print_last(Node **ptail) {
  Node *ptr = *ptail;
  if (ptr == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("Last: %d\n", ptr->data);
}

void print_first(Node **phead) {
  Node *ptr = *phead;
  if (ptr == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("First: %d\n", ptr->data);
}

// --- Menu Function ---
void menu(Node **head, Node **tail) {
  int option;
  int value;

  do {
    printf("\n--- MENU ---\n");
    printf("1. Push\n");
    printf("2. Remove first\n");
    printf("3. Print first element\n");
    printf("4. Print last element\n");
    printf("5. Exit\n");
    printf("Choose: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      printf("Input the value:\n");
      scanf("%d", &value);
      push(head, tail, value);
      break;
    case 2:
      remove_first(head, tail);
      break;
    case 3:
      print_first(head);
      break;
    case 4:
      print_last(tail);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid option!\n");
    }
  } while (option != 5);
}

#endif // DLLQ_H
