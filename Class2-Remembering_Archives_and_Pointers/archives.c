#include <stdio.h>

int main(){
    
    FILE* archive;
    archive = fopen("file.txt", "r");
    char buffer[255];

    /*fprintf(archive, "Bruno Costa Lucena de Araújo");*/

    if(archive == NULL){
        printf("File does not exist\n");    
    }
    else{
        while(fgets(buffer, 255, archive) != NULL){
            printf("%s\n", buffer);    
        }
        fclose(archive);
    }


    return 0;
}
