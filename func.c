#include <stdio.h>
#include <string.h>
#include "func.h"
//7 easy 5 hard
void print_hang (int err, int step) //виселица
{
     if (err == 7) {
          switch (step)
          {
               case 7: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ / \\  (A)  "); break;
               case 6: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ /    (A)  "); break;
               case 5: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_      (A)  "); break;
               case 4: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|   (A)\n_||_      (A)  "); break;
               case 3: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||   |   (A)\n_||_      (A)  "); break;
               case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||       (A)\n_||_      (A)  "); break;
               case 1: printf("  ____    (A)\n ||/      (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;
               //case 1: printf("          (A)\n ||       (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;
               //case 1: printf("         (A)\n          (A)\n         (A)\n         (A)\n___      (A)  "); break;
               //case 0: printf("         (A)\n         (A)\n         (A)\n         (A)\n         (A)  "); break;
          }
     }
     if (err == 5) {
          switch (step)
          {
               case 5: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ / \\  (A)  "); break;
               case 4: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ /    (A)  "); break;
               case 3: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_      (A)  "); break;
               case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|   (A)\n_||_      (A)  "); break;
               case 1: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||   |   (A)\n_||_      (A)  "); break;
               //case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||       (A)\n_||_      (A)  "); break;
               //case 1: printf("  ____    (A)\n ||/      (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;      
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
