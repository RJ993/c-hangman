#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "lib/gen_word.c"
#include "lib/hangman_image.c"
#include "lib/hangman_blanks.c"

void guessCorrectnessCheck(char guess, char* word, char *blanks, int *pWrongGuesses);
char getGuess(void);

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

    int generationReturn = generateWord(word);
    if (generationReturn != 0) return 1;

    char blanksInterface[13] = {0};
    blanksGen(word, blanksInterface);

    printf("%s\n", word);
    do{
        prevWrongValue = wrongGuesses;
        displayImage(hangmanImage);
        interfacePrinter(blanksInterface);
        guess = getGuess();
        guessCorrectnessCheck(guess, word, blanksInterface, &wrongGuesses);
        modifyImage(hangmanImage, prevWrongValue, wrongGuesses);
    }while(gameRunning);
    return 0;
}

void guessCorrectnessCheck(char guess, char* word, char *blanks, int *pWrongGuesses){
    bool correct = false;
    for (int i = 0; i < strlen(word); i++){
        if (guess == word[i]){
            correct = true;
            blanks[i] = word[i];
        }
    }
    if (correct == false) (*pWrongGuesses) += 1;
}

char getGuess(void){
    char guess = '\0';
    int charBuffer = '\0';
    do{
        printf("What letter do you think is in the word?: ");
        guess = getchar();
        while ((charBuffer = getchar()) != '\n' && charBuffer != EOF);
        guess = tolower(guess);
    }while(guess < 'a' || guess > 'z');
    return guess;
}