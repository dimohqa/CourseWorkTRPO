#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "reithed.h"

int main() {
    char word[20], enc_word[20], help[100];
    char nick[9];
    char check[20];
    int err = 0, lev = 0;
    int symbol;
    FILE *fp = fopen("words.txt","r");
    if (fp == NULL) {
        printf("Error read file");
        return 1;
    }
    printf("Введите ваше имя(1-8 символов): ");
    scanf("%s", nick);
    while (rating(nick, 'L') == -1) {
        printf("\nНик должен быть не более 8 символов, попробуйте еще раз:");
        scanf("%s", nick);
    }

    printf("Enter level(1 - easy(8 err), 2 - hard(5 err): ");
    while (err == 0) {
        scanf("%d", &lev);
        err = level(lev);
    }
    randomize(fp, word, help);
    encryption(word, enc_word);
    fclose(fp);
    int RError = 0, step = 0, flag = 0, point = 1, is = 0;
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
            is = 0;
            break;
        }
        if ((flag = proverka(word, enc_word)) == 0) {
            printf("\nПоздравляем!Вы победили!!!\n");
            printf("Загаданное слово: %s\n", word);
            is = 1;
            break;
        }
        print_secret(enc_word);

        printf("Введенные буквы ранее: ");
        for (int i = 0; i < strlen(check); i++) {
            printf("%c ,", check[i]);
        }

        printf("\nПодсказка: %s", help);
        printf("\nВведите букву: ");
        symbol = getchar();

        if ((flag = correct_symbol(symbol)) == -1) {
            point = 0;
            continue;
        } else {
            if ((flag = check_symbol(symbol, check)) == -1) {
                point = 0;
                continue;
            }
        }
        symbol = reg(symbol);
        flag = 1;
        if ((flag = compare_s(symbol, word, enc_word)) == -1) {
            printf("\nТакой буквы нет!");
            RError++;
        }
    }
    if (is == 0) {
        rating(nick, 'L');
    } else {
        rating(nick, 'W');
    }
    return 0;
}
