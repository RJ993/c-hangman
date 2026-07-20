#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "lib/gen_word.c"
#include "lib/hangman_image.c"
#include "lib/hangman_blanks.c"

int main(void){
    srand(time(NULL));

    char hangmanImage[5][10] = {{"|-----|\n"}, 
                                {"|     |\n"}, 
                                {"|      \n"}, 
                                {"|       \n"}, 
                                {"|       \n"}};

    bool gameRunning = false;
    char guess = '\0';
    int prevWrongValue = 0;
    int wrongGuesses = 0;
    char word[13] = {0};
    int charBuffer = '\0';

    int generationReturn = generateWord(word);
    if (generationReturn != 0) return 1;

    char blanksInterface[13] = {0};
    blanksGen(word, blanksInterface);

    printf("%s\n", word);
    do{
        prevWrongValue = wrongGuesses;
        displayImage(hangmanImage);
        interfacePrinter(blanksInterface);
        do{
            printf("What letter do you think is in the word?: ");
            guess = getchar();
            while ((charBuffer = getchar()) != '\n' && charBuffer != EOF);
            guess = tolower(guess);
        }while(guess < 'a' || guess > 'z');
        // Insert correct check logic here.
        modifyImage(hangmanImage, prevWrongValue, wrongGuesses);
        printf("%c\n", guess);
    }while(gameRunning);
    return 0;
}