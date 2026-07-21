#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 50
#define THE_BEGINNING 1

void queryFile(char *buffer, FILE *pDictionary, int readLine){
    int currentLine = 1;
    bool keepReading = true;
    do{
        fgets(buffer, MAX_LINE, pDictionary);
        buffer[strlen(buffer) - 1] = '\0';

        if (feof(pDictionary)){
            rewind(pDictionary);
            currentLine = 1;
        }
        else if (currentLine == readLine){
            rewind(pDictionary);
            keepReading = false;
        }else{
            currentLine++;
        }
    }while(keepReading);
}

void getWordFromFile(char *buffer, FILE *pDictionary, int theEnd){
    int readLine = 0;
    do{
        readLine = (rand() % (theEnd - THE_BEGINNING + 1)) + THE_BEGINNING;
        queryFile(buffer, pDictionary, readLine);
    }while(strlen(buffer) < 5 || strlen(buffer) > 12);
}

int countLines(char *buffer, FILE *pDictionary){
    int currentLine = 1;
    bool keepReading = true;
    do{
        fgets(buffer, MAX_LINE, pDictionary);
        buffer[strlen(buffer) - 1] = '\0';

        if (feof(pDictionary)){
            rewind(pDictionary);
            keepReading = false;
        }else{
            currentLine++;
        }
    }while(keepReading);
    return currentLine - 1;
}

int fileNameCheck(char *textFile){
    for (int i = 0; i < strlen(textFile); i++){
        if ((textFile[i] < 'A' || textFile[i] > 'Z') && 
            (textFile[i] < 'a' || textFile[i] > 'z') && 
            (textFile[i] < '0' || textFile[i] > '9') &&
            textFile[i] != '-' && textFile[i] != '_') {
            return 1;
        }
    }
    return 0;
}

void notFoundError(){
    printf("ERROR: COULD NOT FIND DICTIONARY.\n");
    printf("Possible Scenarios:\n");
    printf(" - Your file is not a text file (.txt).\n");
    printf(" - Your file may have exceeded the 50 character limit.\n");
    printf(" - Your file is not in the dictionary directory/folder.\n");
    printf(" - The dictionary directory/folder may not exist.\n");
}

void lowerCaseWord(char *word){
    for (int i = 0; i < strlen(word); i++){
        word[i] =  tolower(word[i]);
    }
}

void createFilePath(char *filePath, char *textFile){
    strncat(filePath, textFile, 50);
    strncat(filePath, ".txt", 5);
}

int genWordFileOps(char *filePath, char *buffer){
    int theEnd = 9882;
    FILE *pDictionary = fopen(filePath, "r");
        if (pDictionary == NULL) {
            notFoundError();
            return 1;
        }
        theEnd = countLines(buffer, pDictionary);
        getWordFromFile(buffer, pDictionary, theEnd);
    fclose(pDictionary);
    return 0;
}

int generateWord(char *word, char *textFile){
    char buffer[MAX_LINE] = {0};
    int fileCheck = 1;
    int fileOperationsSuccess = 1;
    char filePath[69] = "./dictionary/";

    fileCheck = fileNameCheck(textFile);
    if (fileCheck != 0) {
        printf("ERROR: FILE NAME NOT VALID.\n");
        printf("Valid file names ONLY have letters, numbers, hyphens, and underscores.\n");
        return 1;
    }

    createFilePath(filePath, textFile);
    fileOperationsSuccess = genWordFileOps(filePath, buffer);
    if (fileOperationsSuccess != 0) return 1;

    lowerCaseWord(word);
    strcpy(word, buffer);
    return 0;
}

int generateWordDefault (char *word){
    return generateWord(word, "google-10000-english-usa-no-swears");
}