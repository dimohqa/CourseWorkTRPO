#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
//7 easy 5 hard
void print_hang (int err, int step) //виселица
{
     if (err == 7) {
          switch (step)
          {
            case 6: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ / \\  (A)  "); break;
            case 5: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ /    (A)  "); break;
            case 4: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_      (A)  "); break;
            case 3: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|   (A)\n_||_      (A)  "); break;
            case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||   |   (A)\n_||_      (A)  "); break;
            case 1: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||       (A)\n_||_      (A)  "); break;
            case 0: printf("  ____    (A)\n ||/      (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;
               //case 1: printf("          (A)\n ||       (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;
               //case 1: printf("         (A)\n          (A)\n         (A)\n         (A)\n___      (A)  "); break;
               //case 0: printf("         (A)\n         (A)\n         (A)\n         (A)\n         (A)  "); break;
          }
     }
     if (err == 5) {
          switch (step)
          {
            case 4: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ / \\  (A)  "); break;
            case 3: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ /    (A)  "); break;
            case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_      (A)  "); break;
            //case 1: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|   (A)\n_||_      (A)  "); break;
            case 1: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||   |   (A)\n_||_      (A)  "); break;
            //case 0: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||       (A)\n_||_      (A)  "); break;
            case 0: printf("  ____    (A)\n ||/      (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;      
          }
     }
}

int level(int lev) {
    int err;
    if (lev == 1) {
        err = 7;
        return err;
    }
    if (lev == 2) {
        err = 5;
        return err;
    }
    if (lev != 1 && lev != 2) {
        printf("Incorrect level!\nEnter level:");
    }
    return 0;
}

void encryption(char word[], char enc_word[]) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        enc_word[i] = '*';
        enc_word[length] = '\0';
    }
}

void randomize(FILE *fp, char *word, char *help) {
    srand(time(NULL));
    int rnd, f = 0;
    while (fscanf(fp, "%s" "%s", word , help) != EOF ) {
        f++;
    }
    rnd = rand() % f;
    fseek(fp, 0, SEEK_SET);
    for (int i = 0;i < rnd; i++) {
        fscanf(fp, "%s" "%s", word, help);
    }
}

int compare_s(char symbol, char word[], char enc_word[]) {
    int len = strlen(word);
    int flag = -1;
    for (int i = 0; i < len; i++) {
        if (word[i] == symbol) {
            enc_word[i] = word[i];
            flag = 0;
        }
    }
    return flag;
}

void print_secret(char enc_word[]) {
    int len = strlen(enc_word);
    printf("\nСекретное слово: ");
    for (int i = 0; i < len; i++) {
        printf("%c  ", enc_word[i]);
    }
    printf("\n");
}

int check_symbol(char symbol, char check[]) {
    int flag = 0;
    int k = strlen(check);
    for (int i = 0; i < strlen(check); i++) {
        if (symbol == check[i]) {
            flag = -1;
        }
    }
    if (flag == 0) {
        check[k] = symbol;
    }
    return flag;
}

int correct_symbol(char symbol) {
    int flag = 0;
    if ( (int)symbol < 65 || ( (int)symbol > 90 && (int)symbol < 97 ) || (int)symbol > 122 ) {
        flag = -1;
    }
    return flag;
}

char reg(char symbol) {
    if ( (int)symbol >= 65 && (int)symbol <= 90 ) {
        symbol = (char)((int)symbol + 32);
    }
    return symbol;
}

int proverka(char word[], char enc_word[]) {
    int flag = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == enc_word[i]) {
            flag++;
        }
    }
    if (flag == strlen(word)) {
        return 0;
    }
    return -1;
}

