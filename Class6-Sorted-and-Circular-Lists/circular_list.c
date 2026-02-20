#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

int is_empty(Node* head) {
    return head == NULL;
}

void push(Node** phead, Node** ptail, int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;

    if(is_empty(*phead)){
        *phead = new_node;
        *ptail = new_node;
        new_node->next = new_node; // Points to itself (creates circle)
    } 
    // if list has elements
    else {
        (*ptail)->next = new_node; // (Old) last element points to the new one.
        *ptail = new_node;         // New element is now tail
        (*ptail)->next = *phead;   // New element points to head
    }
}

void insert_at_0(Node** phead, Node** ptail, int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    
    if(is_empty(*phead)){
        *phead = new_node;
        *ptail = new_node;
        new_node->next = new_node;
    } else {
        new_node->next = *phead; // New node points to old head
        *phead = new_node;       // Updates head
        (*ptail)->next = *phead; // Updates tail
    }
}

void insert(Node** phead, Node** ptail, int index, int value){
    if(index == 0){
        insert_at_0(phead, ptail, value);
        return;
    }

    if(is_empty(*phead)) {
         printf("List is empty, can't insert at index %d.\n", index);
         return;
    }

    Node* ptr = *phead;

    for(int i = 0; i < (index-1); i++){
        ptr = ptr->next;
        // If gets back to head
        if(ptr == *phead){
            printf("Index larger than list size.\n");
            return;
        }
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = ptr->next;
    ptr->next = new_node;

    // If added at tail, update tail
    if (ptr == *ptail) {
        *ptail = new_node;
    }
}

void remove_first(Node** phead, Node** ptail){
    if(is_empty(*phead)){
        printf("List is already empty\n");
        return;
    }
    
    Node* temp = *phead;
    
    // Only has one element
    if(*phead == *ptail){
        *phead = NULL;
        *ptail = NULL;
        free(temp);
    } 
    else {
        *phead = temp->next;     // Moves head forward
        (*ptail)->next = *phead; // Updates tail
        free(temp);
    }
}

void pop(Node** phead, Node** ptail){
    if(is_empty(*phead)){
        printf("List is already empty\n");
        return;
    }
    
    // If there is only one element
    if(*phead == *ptail){
        free(*phead);
        *phead = NULL;
        *ptail = NULL;
    }
    else{
        Node* temp = *phead;
        // we wanna go to the one before the last
        while(temp->next != *ptail){
            temp = temp->next;
        }
        free(*ptail);            // frees the last
        *ptail = temp;           // New next
        (*ptail)->next = *phead; // Updates head
    }
}

void remove_at(Node** phead, Node** ptail, int index) {
    if (is_empty(*phead)) {
        printf("List is already empty\n");
        return;
    }
    if (index == 0) {
        remove_first(phead, ptail);
        return;
    }
    Node* ptr = *phead;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
        // Protection against index out of bounds
        if (ptr == *ptail && i < index - 2) { 
             printf("Index out of bounds.\n");
             return;
        }
    }
    Node* temp = ptr->next;
    if (temp == *phead) {
         printf("Index out of bounds.\n");
         return;
    }
    ptr->next = temp->next;
    // Instead of checking if next is NULL checks if removed was NULL
    if (temp == *ptail) {
        *ptail = ptr;
    }
    
    free(temp);
}

void print_list(Node** phead){
    if(is_empty(*phead)){
        printf("List is empty\n");
        return;
    }
    Node* ptr = *phead;
    
    // Differs from linked list to print once and then until comes to phead again
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while(ptr != *phead);
    printf("(volta ao inicio)\n");
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

void prove_circular(Node** phead, Node** ptail) {
    if (*phead == NULL) {
        printf("Empty list.\n");
        return;
    }
    printf("Head value: %d\n", (*phead)->data);
    printf("Tail value: %d\n", (*ptail)->data);
    printf("Value after tail (tail->next): %d\n", (*ptail)->next->data);
}

void menu(Node** head, Node** tail){
    int option;
    int value;
    int index;

    do {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Push (Insert End)\n");
        printf("2. Pop (Remove End)\n");
        printf("3. Insert at first\n");
        printf("4. Insert at index\n");
        printf("5. Remove first\n");
        printf("6. Remove at index\n");
        printf("7. Print List\n");
        printf("8. Print first element\n");
        printf("9. Print last element\n");
        printf("10. Prove that this list is circular\n");
        printf("11. Exit\n");
        printf("Choose: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Input the value: ");
                scanf("%d", &value);
                push(head, tail, value);
                break;
            case 2:
                pop(head, tail);
                printf("Removed end!\n");
                break;
            case 3:
                printf("Input the value: ");
                scanf("%d", &value);
                insert_at_0(head, tail, value);
                break;
            case 4:
                printf("Input the value: ");
                scanf("%d", &value);
                printf("Input the index: ");
                scanf("%d", &index);
                insert(head, tail, index, value);
                break;
            case 5:
                remove_first(head, tail);
                printf("Removed first!\n");
                break;
            case 6:
                printf("Input the index: ");
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
                prove_circular(head, tail);
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 11);
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    menu(&head, &tail);
    return 0;
}