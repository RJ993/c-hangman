#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "lib/gen_word.c"

void blanksGen(char *word, char *interface);
void interfacePrinter(char *interface);

int main(void){
    srand(time(NULL));

    bool gameRunning = false;
    char word[13] = {0};
    int generationReturn = generateWord(word);
    if (generationReturn != 0) return 1;
    char blanksInterface[13] = {0};
    blanksGen(word, blanksInterface);

    printf("%s\n", word);
    do {
        interfacePrinter(blanksInterface);
    }while(gameRunning);
    return 0;
}

void blanksGen(char *word, char *interface){
    for (int i = 0; i < strlen(word); i++){
        interface[i] = '_';
    }
}
void interfacePrinter(char *interface){
    for (int i = 0; i < strlen(interface); i++){
        printf("%c ", interface[i]);
    }
    printf("\n");
}