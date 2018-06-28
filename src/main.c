#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "reithed.h"

int main() {
    char word[20], enc_word[20], help[100];
    char nick[9];
    char check[20];
    int err = 0, lev = 0, symbol;
    system("clear");
    FILE *fp = fopen("words.txt","r");
    if (fp == NULL) {
        printf("Ошибка чтения файла");
        return 1;
    }
    printf("Введите ваше имя(1-8 символов): ");
    scanf("%s", nick);
    while (rating(nick, 'F') == -1) {//додел тут
        printf("\nНик должен быть не более 8 символов, попробуйте еще раз:");
        scanf("%s", nick);
    }
    printf("Введите уровень(1 - легкий(8 ошибок), 2 - сложный(5 ошибок): ");
    while (err == 0) {
        scanf("%d", &lev);
        err = level(lev);
    }
    randomize(fp, word, help);
    encryption(word, enc_word);
    fclose(fp);
    int RError = 0, step = 0, flag = 0, point = 1, is = 0;
    while (RError <= err) {
        system("clear");
        printf("\t\t\t\t\t\t\t\t\t\t|| Уровень: %d || Ошибок: %d || Шагов: %d ||\n", lev, RError, step - 1);
        if (point == 1) {
            step++;
        }
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
            step++;
            continue;
        }
        step++;
    }
    if (is == 0) {
        rating(nick, 'L');
    } else {
        rating(nick, 'W');
    }
    return 0;
}
