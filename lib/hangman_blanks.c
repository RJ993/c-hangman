#include <stdio.h>
#include <string.h>

void blanksGen(char *word, char *interface){
    for (int i = 0; i < strlen(word); i++){
        if (word[i] >= 'a' && word[i] <= 'z') interface[i] = '_';
    }
}
void interfacePrinter(char *interface){
    for (int i = 0; i < strlen(interface); i++){
        printf("%c ", interface[i]);
    }
    printf("\n\n");
}