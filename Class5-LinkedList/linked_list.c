#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* push(Node** phead, Node** ptail, int value){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if(*phead == NULL){
        *phead = new_node;
        *ptail = new_node;
    } else {
        (*ptail)->next = new_node;
        *ptail = new_node;
    }
    return new_node;
}

void insert_at_0(Node** phead, Node** ptail, int value){
    Node* new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *phead;
    if(*phead == NULL){
        *ptail = new_node;
    }
    *phead = new_node;
}

void insert(Node** phead, Node** tail, int index, int value){
    if(index == 0){
        insert_at_0(phead, tail, value);
        return;
    }
    Node* ptr = *phead;

    for(int i = 0; i<(index-1); i++){
        if(ptr == NULL){
            printf("You cannot add at an index larger than the size of the list.\n");
            return;
        }
        ptr=ptr->next;
    }
    if(ptr == NULL){
        printf("You cannot add at an index larger than the size of the list.\n");
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = ptr->next;
    ptr->next = new_node;
    if(new_node->next == NULL){
        *tail = new_node;
    }
}

void remove_first(Node** phead, Node** ptail){
    if(*phead == NULL){
        printf("List is already empty\n");
    }
    else{
        Node* temp = *phead;
        if(temp->next == NULL){
            *ptail = NULL;
        }
        *phead = temp->next;
        free(temp);
    }
}

void pop(Node** phead, Node** ptail){
    if(*phead == NULL){
        printf("List is already empty");
    }
    else if((*phead)->next == NULL){
        free(*phead);
        *phead = NULL;
        *ptail = NULL;
    }
    else{
        Node* temp = *phead;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        *ptail = temp;
    }
}

void remove_at(Node** phead, Node** ptail, int index) {
    if (*phead == NULL) {
        printf("List is already empty\n");
        return;
    }
    if (index == 0) {
        remove_first(phead, ptail);
        return;
    }

    Node* ptr = *phead;
    for (int i = 0; i < index - 1; i++) {
        if (ptr->next == NULL) {
            printf("Index out of bounds.\n");
            return;
        }
        ptr = ptr->next;
    }
    Node* temp = ptr->next;
    if (temp == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    ptr->next = temp->next;
    if(ptr->next == NULL){
        *ptail = ptr;
    }
    free(temp);
}

void print_list(Node** phead){
    Node* head = *phead;
    for(Node* i=head; i != NULL; i = i->next){
        printf("%d\n", i->data);
    }
}

void print_last(Node** ptail){
    Node* ptr = *ptail;
    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Last: %d\n", ptr->data);
}

void print_first(Node** phead){
    Node* ptr = *phead;
    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }
    printf("First: %d\n", ptr->data);
}

void menu(Node** head, Node**tail){
    int option;
    int value;
    int index;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Insert at first\n");
        printf("4. Insert\n");
        printf("5. Remove first\n");
        printf("6. Remove\n");
        printf("7. Print List\n");
        printf("8. Print first element\n");
        printf("9. Print last element\n");
        printf("10. Exit\n");
        printf("Choose: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Input the value:\n");
                scanf("%d", &value);
                push(head, tail, value);
                break;
            case 2:
                pop(head, tail);
                printf("Removed!\n");
                break;
            case 3:
                printf("Input the value:\n");
                scanf("%d", &value);
                insert_at_0(head, tail, value);
                break;
            case 4:
                printf("Input the value:\n");
                scanf("%d", &value);
                printf("Input the index:\n");
                scanf("%d", &index);
                insert(head, tail, index, value);
                break;
            case 5:
                remove_first(head, tail);
                break;
            case 6:
                printf("Input the index:\n");
                scanf("%d", &index);
                remove_at(head, tail, index);
                break;
            case 7:
                print_list(head);
                break;
            case 8:
                print_first(head);
                break;
            case 9:
                print_last(tail);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 10);
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    menu(&head, &tail);
    return 0;
}