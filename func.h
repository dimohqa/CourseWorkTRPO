#ifndef FUN_H
#define FUN_H

#include <string.h>
#define green "\033[1;32m"
#define RESET "\033[0m"
#include <stdio.h>

void print_mmr(char *nick);

void randomize(FILE *fp, char *word, char *help);

int level(int lev);

void encryption(char word[], char enc_word[]);

void print_hang(int err, int step);

int compare_s(char symbol, char word[], char enc_word[]);

void print_secret(char enc_word[]);

int check_symbol(char symbol, char check[], int index);

int correct_symbol(char symbol);

char reg(char symbol);

#endif
