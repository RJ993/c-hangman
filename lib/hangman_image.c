#include <stdio.h>

void displayImage(char image[5][10]){
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%s", image[i]);
    }
    printf("\n");
}
void modifyImage(char image[5][10], int currentWrong, int newWrong){
    if (currentWrong == newWrong) return;
    switch (newWrong)
    {
    case 1:
        image[2][6] = 'O';
        break;
    case 2:
        image[3][6] = '|';
        break;
    case 3:
        image[3][5] = '/';
        break;
    case 4:
        image[3][7] = '\\';
        break;
    case 5:
        image[4][5] = '/';
        break;
    case 6:
        image[4][7] = '\\';
        break;
    }
}