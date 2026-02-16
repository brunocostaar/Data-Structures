#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vector;
    int length;
    int i;
} List;

void create_list(List* list, int length){
    list->vector = (int*) malloc(length*sizeof(int));
    if(list->vector == NULL){
        printf("Unsuccesful memory allocation.");
        exit(1);
    }
    list->length = length;
    list->i = -1;
};

int push(List* list, int value){
    if(list->i == list->length - 1){
        int new_size = list->length*2;
        int *temp = (int*)realloc(list->vector, new_size*sizeof(int));
        if(temp == NULL){
            printf("No more space in memory");
            return 0;
        }
        list->vector = temp;
        list->length = new_size;
    }
    (list->i)++;
    list->vector[list->i] = value;
    return 1;
}

int pop(List* list){
    if(list->i == -1){
        printf("Empty list, cannot pop.");
        return 0;
    }
    (list->i)--;
    return 1;
}

int print_list(List* list){
    if(list->i < 0){
        printf("Error: Empty list");
        return 0;
    }
    for(int i=0; i<=list->i; i++){
        printf("%d \n", list->vector[i]);
    }
    return 1;
}

int destroy(List* list){
    free(list->vector);
    list->vector = NULL;
    list->length = 0;
    list->i = -1;
}

int insert(List* list, int at_index, int value){
    if(list->i == list->length - 1){
        int new_size = list->length*2;
        int *temp = (int*)realloc(list->vector, new_size*sizeof(int));
        if(temp == NULL){
            printf("No more space in memory");
            return 0;
        }
        list->vector = temp;
        list->length = new_size;
    }
    if(!(at_index>=0 && at_index<=(list->i)+1)){
        printf("You cannot insert at this index. Try again.");
        return 0;
    }
    for(int k=list->i; k>=at_index; k--){
        list->vector[k+1] = list->vector[k];
    }
    list->vector[at_index] = value;
    (list->i)++;
    return 1;
}

int list_remove(List* list, int at_index){
    if(list->i == -1){
        printf("Empty list, cannot pop.");
        return 0;
    }
    if(!(at_index>=0 && at_index<=(list->i))){
        return 0;
    }
    for(int k=at_index; k<list->i; k++){
        list->vector[k] = list->vector[k+1];
    }
    (list->i)--;
    return 1;
}

void menu_list(List* list) {
    int option;
    int value;
    int index;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Insert\n");
        printf("4. Remove\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Input the value:\n");
                scanf("%d", &value);
                push(list, value);
                break;
            case 2:
                pop(list);
                printf("Removed!\n");
                break;
            case 3:
                printf("Input the value:\n");
                scanf("%d", &value);
                printf("Input the index:\n");
                scanf("%d", &index);
                insert(list, index, value);
                break;
            case 4:
                printf("Input the index:\n");
                scanf("%d", &index);
                list_remove(list, index);
                break;
            case 5:
                print_list(list);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 6);
}

int main(){
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