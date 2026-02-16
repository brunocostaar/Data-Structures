#include <stdio.h>

int main(){
    
    unsigned char ascii;

    for(ascii = 0; ascii<255; ascii++){
        printf("%d - %c\n", ascii, ascii);
    }

    return 0;
}
