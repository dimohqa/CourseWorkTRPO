#define CTEST_MAIN

#include "func.h"
#include "reithed.h"
#include "ctest.h"

CTEST(Reterned_prow, Correct_data){
    users arr[10];
    char sym[10] = {"src"};
    arr[1].num = 4;
    strncpy(arr[1].name,sym,  10);
    const int res = prow(sym, arr);
    const int exp = 3; 
    ASSERT_EQUAL(exp,res);
}

CTEST(Reterned_prow, Incorrect_data){
    users arr[20];
    char sym[10] = {"tststs12"};
    char n[10] = {"zzzzz"};
    strncpy(arr[5].name, n, 10);
    arr[5].num = 4;
    const int res = prow(sym, arr);
    const int exp = -1; 
    ASSERT_EQUAL(exp,res);
}

CTEST(No_user_win, Correct_data) {
    users mmr[10];
    int size = 5;
    char nick[10] = {"stop"};
    int ex_win = 1;
    int ex_lose = 0;
    int ex_num = size+1;
    float ex_n = (float)ex_win/(ex_win+ex_lose);
    nousw(size, mmr, nick);
    ASSERT_EQUAL(ex_win, mmr[size].win);
    ASSERT_EQUAL(ex_num, mmr[size].num);
    ASSERT_EQUAL(ex_lose, mmr[size].lose);
    ASSERT_EQUAL(ex_n, mmr[size].n);
    ASSERT_STR(nick, mmr[size].name);
}

CTEST(No_user_lose, Correct_data) {
    users mmr[10];
    int size = 5;
    char nick[10] = {"stop"};
    int ex_win = 0;
    int ex_lose = 1;
    int ex_num = size+1;
    float ex_n = (float)ex_win/(ex_win+ex_lose);
    nousl(size, mmr, nick);
    ASSERT_EQUAL(ex_win, mmr[size].win);
    ASSERT_EQUAL(ex_num, mmr[size].num);
    ASSERT_EQUAL(ex_lose, mmr[size].lose);
    ASSERT_EQUAL(ex_n, mmr[size].n);
    ASSERT_STR(nick, mmr[size].name);
}

CTEST(Encryption, Correct_data){
    char word[10] = {"apple"};
    char enc_word[10];
    char ex_word[10] = {"*****"};
    encryption(word, enc_word);
    ASSERT_STR(ex_word, enc_word);
}


CTEST(Reterned_level, Correct_Retrned1) {
    int lev = 1;
    const int res = level(lev);
    const int exp = 7;
    ASSERT_EQUAL(exp, res);
}

CTEST(Reterned_level, Correct_Retrned2) {
    int lev = 2;
    const int res = level(lev);
    const int exp = 5;
    ASSERT_EQUAL(exp, res);
}

CTEST(Reterned_correct_symbol, Correct_data) {
    char test = 'a';
    const int exp = 0;
    int res = -1;
    for (int i = 0; i<26; i++) {
        res = correct_symbol(test);
        test++;
        ASSERT_EQUAL(exp, res);
    }
    
}

CTEST(Reterned_correct_symbol, Incorrect_data) {
    char sym = '1';
    const int res = correct_symbol(sym);
    const int exp = -1;
    ASSERT_EQUAL(exp, res);
}

CTEST(Reterned_reg, test_retern) {
    char a = 'A';
    char b = 'a';
    int exp = (int)b;
    int res = (int)reg(a);
    ASSERT_EQUAL(exp, res);
}

CTEST(Reterned_proverka, retern_true) {
    char a[10] = {"abv"};
    char b[10] = {"abv"};
    const int exp = 0;
    const int res = proverka(a,b);
    ASSERT_EQUAL(exp,res);
}

CTEST(Reterned_proverka, retern_false) {
    char a[10] = {"abv"};
    char b[10] = {"ab"};
    const int exp = -1;
    const int res = proverka(a,b);
    ASSERT_EQUAL(exp,res);
}

CTEST(Reterned_compare_s, retern_true) {
    char s = 's';
    char word[10] = {"slovo"};
    char enc_word[10] = {"*****"};
    const int exp = 0;
    const int res = compare_s(s, word, enc_word);
    ASSERT_EQUAL(exp, res);
}

CTEST(Reterned_compare_s, retern_false) {
    char s = 'd';
    char word[10] = {"slovo"};
    char enc_word[10] = {"*****"};
    const int exp = -1;
    const int res = compare_s(s, word, enc_word);
    ASSERT_EQUAL(exp, res);
}



//CTEST(Reterned_check_symbol, retern_true) {
    //char check[16] = {"abcde"}
    
    //check_symbol(sym, check, ind);
//}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}


