#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/gen_word.c"

int main(void){
    srand(time(NULL));
    char word[13] = {0};
    int generationReturn = generateWord(word);
    if (generationReturn != 0) return 1;
    printf("%s\n", word);
    return 0;
}