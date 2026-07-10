#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LINE 50

int generateWord(char *word);

int main(void){
    srand(time(NULL));
    char word[13] = {0};
    int generationReturn = generateWord(word);
    if (generationReturn != 0) return 1;
    printf("%s\n", word);
    return 0;
}

int generateWord(char *word){
    int theBeginning = 1;
    int theEnd = 9882;
    char buffer[MAX_LINE] = {0};
    int readLine = 0;
    int currentLine = 1;
    bool keepReading = true;
    FILE *pDictionary = fopen("./dictionary/google-10000-english-usa-no-swears.txt", "r");
        if (pDictionary == NULL) {
            printf("ERROR: COULD NOT FIND DICTIONARY\n");
            return 1;
        }
        do{
            readLine = (rand() % (theEnd - theBeginning + 1)) + theBeginning;
            do{
                fgets(buffer, MAX_LINE, pDictionary);

                if (feof(pDictionary)){
                    rewind(pDictionary);
                    currentLine = 1;
                }
                else if (currentLine == readLine){
                    keepReading = false;
                }

                currentLine++;
            }while(keepReading);
        }while(strlen(buffer) < 5 || strlen(buffer) > 12);
        buffer[strlen(buffer) - 1] = '\0';
        
    fclose(pDictionary);
    strcpy(word, buffer);
    return 0;
}