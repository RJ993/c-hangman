#include <stdio.h>
#include <string.h>

void blanksGen(char *word, char *interface){
    for (int i = 0; i < strlen(word); i++){
        interface[i] = '_';
    }
}
void interfacePrinter(char *interface){
    for (int i = 0; i < strlen(interface); i++){
        printf("%c ", interface[i]);
    }
    printf("\n\n");
}