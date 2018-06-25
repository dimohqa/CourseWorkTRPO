#include <stdio.h>
#include "func.h"

int main() {
    char word[20], enc_word[20];
    char nick[20]= {"SoNy"};
    int err = 0, lev = 0;
    FILE *fp = fopen("words.txt","r");
    if (fp == NULL) {
        printf("Error read file");
        return 0;
    }
    printf("Enter level:");
    while (err == 0) {
        scanf("%d", &lev);
        err = level(lev);
    }
    print_hang(7, 7);
    print_mmr(nick);
    //fclose(fp);
    fclose(fp);
    printf("\n");
    return 0;
}
