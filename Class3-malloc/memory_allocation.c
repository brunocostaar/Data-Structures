#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(char ** names){
    for(int i=0; i<10; i++){
        char temp[100];
        scanf("%s", temp);
        int length = strlen(temp);
        names[i] = (char*) malloc(length*sizeof(char)+1);
        strcpy(names[i], temp);
    }
}

void print(char ** names){
    for(int i=0; i<10; i++){
        printf("%s\n", names[i]);
    }
}

int main(){
    
    char ** names = (char**) malloc(10*sizeof(char*));
    if(names==NULL){
        printf("Unsuccesful memory allocation.");
        exit(1);
    }

    read(names);

    print(names);
    
    for(int i=0; i<10; i++){
        free(names[i]);
        names[i] = NULL;
    }
    free(names);
    names = NULL;

    return 0;
}
