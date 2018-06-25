#include <stdio.h>
#include "func.h"

int main() {
    char word[20], enc_word[20];
    int err = 0, lev = 0;
    //FILE *fp = fopen("words.txt","r");
    printf("Enter level:");
    while (err == 0) {
        scanf("%d", &lev);
        err = level(lev);
    }
    //fclose(fp);
    return 0;
}