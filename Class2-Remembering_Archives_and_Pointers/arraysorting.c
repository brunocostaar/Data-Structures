#include <stdio.h>

void showSorted(int *p) {
    int *pv[5]; // pointers array (as asked by the teacher)
    int *temp;  // auxiliary variable for pointers switching
    int i, j;   // counting variables
    
    for(i=0; i<5; i++){
        pv[i] = &p[i];
    }
    
    // bubblesort adapted for pointers
    for(i=0; i<5; i++){
        for(j=4; j>=1; j--){
            if(*pv[j] < *pv[j-1]){
                temp = pv[j];
                pv[j] = pv[j-1];
                pv[j-1] = temp;
            }        
        }
    }

    for(i=0; i<5; i++){
        printf("%d ", *pv[i]);    
    }

    
}

int main() {
    int v[5] = {10, 2, 35, 4, 1}; 
    int i;

    printf("Original array before: ");
    for(i = 0; i < 5; i++) printf("%d ", v[i]);
    printf("\n\n");

    showSorted(v);

    printf("\n");
    
    printf("Original array after: ");
    for(i = 0; i < 5; i++) printf("%d ", v[i]);
    printf("\n");

    return 0;
}
