#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "lib/gen_word.c"
#include "lib/hangman_image.c"
#include "lib/hangman_blanks.c"

int main(void){
    srand(time(NULL));

    bool gameRunning = false;
    char hangmanImage[5][10] = {{"|-----|\n"}, 
                                {"|     |\n"}, 
                                {"|      \n"}, 
                                {"|       \n"}, 
                                {"|       \n"}};
    int prevWrongValue = 0;
    int wrongGuesses = 0;
    char word[13] = {0};
    int generationReturn = generateWord(word);
    if (generationReturn != 0) return 1;
    char blanksInterface[13] = {0};
    blanksGen(word, blanksInterface);

    printf("%s\n", word);
    do {
        modifyImage(hangmanImage, prevWrongValue, wrongGuesses);
        prevWrongValue = wrongGuesses;
        displayImage(hangmanImage);
        interfacePrinter(blanksInterface);
    }while(gameRunning);
    return 0;
}