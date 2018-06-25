#ifndef FUN_H
#define FUN_H

#include <string.h>
#define green "\033[1;32m"
#define RESET "\033[0m"
#include <stdio.h>

void print_mmr(char *nick);

int level(int lev);

void encryption(char word[], char enc_word[]);

void print_hang (int err, int step);

#endif
