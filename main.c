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
bool endConditions(char *word, char *blanks, int wrongGuesses);

int main(int argc, char *argv[]){
    srand(time(NULL));

    char hangmanImage[5][10] = {{"|-----|\n"}, 
                                {"|     |\n"}, 
                                {"|      \n"}, 
                                {"|       \n"}, 
                                {"|       \n"}};

    bool gameRunning = true;
    char guess = '\0';
    int prevWrongValue = 0;
    int wrongGuesses = 0;
    char word[13] = {0};

    int generationReturn = 1;
    generationReturn = argc == 1 ? generateWordDefault(word) : generateWord(word, argv[1]);
    if (generationReturn != 0) return 1;

    char blanksInterface[13] = {0};
    blanksGen(word, blanksInterface);

    displayImage(hangmanImage);
    interfacePrinter(blanksInterface);
    do{
        prevWrongValue = wrongGuesses;
        guess = getGuess();
        guessCorrectnessCheck(guess, word, blanksInterface, &wrongGuesses);
        modifyImage(hangmanImage, prevWrongValue, wrongGuesses);
        gameRunning = endConditions(word, blanksInterface, wrongGuesses);
        displayImage(hangmanImage);
        interfacePrinter(blanksInterface);
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
        if (guess != '\n') {
            while ((charBuffer = getchar()) != '\n' && charBuffer != EOF);
        }
        guess = tolower(guess);
    }while(guess < 'a' || guess > 'z');
    return guess;
}

bool endConditions(char *word, char *blanks, int wrongGuesses){
    if(strcmp(word, blanks) == 0){
        printf("You have won!\n");
        return false;
    }else if (wrongGuesses > 5) {
        printf("You have lost! The word is %s.\n", word);
        return false;
    }
    return true;
}