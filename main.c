#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
    char word[20], enc_word[20], help[100];
    char nick[20]= {"SoNy"};
    char check[20];
    int err = 0, lev = 0;
    int symbol;
    FILE *fp = fopen("words.txt","r");
    if (fp == NULL) {
        printf("Error read file");
        return 1;
    }
    printf("Enter level:");
    while (err == 0) {
        scanf("%d", &lev);
        err = level(lev);
    }
    randomize(fp, word, help);
    encryption(word, enc_word);
    fclose(fp);
    int RError = 0;
    int step = 0;
    int flag = 0;
    int point = 1;
    int index = -1;
    int flag2 = 0;
    while (RError <= err) {
        if (point == 1) {
            step++;
        }
        system("clear");
        printf("\t\t\t\t\t\t\t\t\t\t|| Level: %d || Error: %d || Step: %d ||\n", lev, RError, step);
        print_hang(err, RError);
        if (RError == err) {
            printf("\nК сожалению вы проиграли!!!\n");
            printf("Загаданное слово: %s\n", word);
            return 0;
        }
        if (flag = proverka(word, enc_word) == 0) {
            printf("\nПоздравляем!Вы победили!!!\n");
            printf("Загаданное слово: %s\n", word);
            return 0;
        }
        print_secret(enc_word);
        
        printf("Введенные буквы ранее: ");
        for (int i = 0; i < strlen(check); i++) {
            printf("%c ,", check[i]);
        }
        
        printf("\nВведите букву: ");
        getchar();
        symbol = getchar();
        
        if (flag = correct_symbol(symbol) == -1) {
            point = 0;
            //printf("\nВы ввели неккоректную букву!Попробуйте снова!(enter)\n");
            //getchar();
            continue;
        } else {
            if (flag = check_symbol(symbol, check, index) == -1) {
                point = 0;
                //printf("\nЭта буква уже была!Попробуйте снова!(enter)\n");
                //getchar();
                continue;
            }
        }
        symbol = reg(symbol);
        flag = 1;
        if (flag = compare_s(symbol, word, enc_word) == -1) {
            printf("\nТакой буквы нет!");
            RError++;
        }
    }
    return 0;
}
