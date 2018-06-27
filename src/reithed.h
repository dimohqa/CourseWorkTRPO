#ifndef REIT_H
#define REIT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define green "\033[1;32m"
#define RESET "\033[0m"

typedef struct{
    int num;
    char name[10];
    int win;
    int lose;
    float n;
} users;

void in_f(users *arr, FILE *pf, int size, char *nick);
void nousl (int size, users *mmr, char *nick);
void nousw (int size, users *mmr, char *nick);
void out(int size, char *nick);
int prow (char *nick, users *arr);
int addstr(FILE *pf,users *var);
int rating (char *nick, char sim_w_l);

#endif
