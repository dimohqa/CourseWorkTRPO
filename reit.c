#include "reithed.h"

int prow (char *nick, users *arr) {//проверка есть ник или нет если есть то записать в него статистику проиграл или выйграл если нет записать ник в конец списка ..победы и пор = 0 а в конце записать стату
    int res = 1;
    for (int i = 0; i<=20; i++){
        res = strncmp(nick, arr[i].name, 10);
        if (res == 0){
            return (arr[i].num-1);
        }
    }
    return -1; 
}//если ника нет то записать ник в конец..если есть то изменить статистику ...вопрос как найти конец

void in_f(users *arr, FILE *pf, int size, char *nick){//запись в файл
    int len = 0;
    char p1[8] = " ";
    char p2[8] = "  ";
    char p3[8] = "   ";
    char p4[8] = "    ";
    char p5[8] = "     ";
    char p6[8] = "      ";
    char p7[8] = "       ";
    for(int i = 0; i<=size; i++){
        len = strlen(arr[i].name);
        if (len == 8) fprintf(pf, "%d|%s|%d|%d\n", arr[i].num, arr[i].name, arr[i].win, arr[i].lose);
        else
        if (len == 7) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p1, arr[i].win, arr[i].lose);//f
        else
        if (len == 6) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p2, arr[i].win, arr[i].lose);//f
        else
        if (len == 5) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p3, arr[i].win, arr[i].lose);//f
        else
        if (len == 4) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p4, arr[i].win, arr[i].lose);//f
        else
        if (len == 3) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p5, arr[i].win, arr[i].lose);//f
        else
        if (len == 2) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p6, arr[i].win, arr[i].lose);//f
        else
        if (len == 1) fprintf(pf, "%d|%s%s|%d|%d\n", arr[i].num, arr[i].name, p7, arr[i].win, arr[i].lose);//f
        else{
            printf("Incorrect data in in_f func\n");
        }
    }
}

int addstr(FILE *pf,users *var){//запись в структуры //сортировку по отношению побед к играм//запись обратно в файл
    int numi=0,wini=0,losei=0;
    char str[21];
    char *num;
    char *namec;
    char namearr[10];
    char *win;
    char *lose;
    fgets(str, 20, pf);
    for (int i =0; str[i] != '\0';i++) {
        if (str[i] =='\n'){
            str[i] = '\0';
        }
    }
    num = strtok(str,"|");
    namec = strtok(NULL,"|");
    if (namec==NULL) {
        return -1;
    }
    win = strtok(NULL,"|");
    if (win==NULL) {
        return -1;
    }
    lose = strtok(NULL,"|");
    if (lose==NULL) {
        return -1;
    }
    numi = atoi(num);
    wini = atoi(win);
    losei = atoi(lose);
    if ((wini+losei)==0){
        return -1;
    }
    var->num=numi;
    var->win=wini;
    var->lose=losei;
    var->n = (float)wini/(wini+losei);
    strncpy(namearr, namec, 10);
    for (int i = 0; namearr[i] != '\0';i++) {
        if (namearr[i] == ' ') {
            namearr[i] = '\0';
        }
    }
    strncpy(var->name, namearr, 10);
    return 1;
}

void out(int size, char *nick){//вывод на экран
    system("clear");
    users mmr[20];
    int len = 0;
    char p1[8] = " ";
    char p2[8] = "  ";
    char p3[8] = "   ";
    char p4[8] = "    ";
    char p5[8] = "     ";
    char p6[8] = "      ";
    char p7[8] = "       ";
    FILE *pf;
    pf = fopen("rating.txt", "r");
    for (int i = 0; addstr(pf, &mmr[i])!= -1; i++) {
        size = i+1;//скопирована база данных и ее размер;
    }
    printf("#|NICKNAME|W|L\n");
    for (int i = 0; i<size; i++) {
        if (strncmp(nick, mmr[i].name, 10)==0){
            len = strlen(mmr[i].name);
            if (len == 8) printf("%s%d|%s|%d|%d%s\n", green, mmr[i].num, mmr[i].name, mmr[i].win, mmr[i].lose, RESET);
            else
            if (len == 7) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p1, mmr[i].win, mmr[i].lose, RESET);//f
            else
            if (len == 6) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p2, mmr[i].win, mmr[i].lose, RESET);//f
            else
            if (len == 5) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p3, mmr[i].win, mmr[i].lose, RESET);//f
            else
            if (len == 4) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p4, mmr[i].win, mmr[i].lose, RESET);//f
            else
            if (len == 3) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p5, mmr[i].win, mmr[i].lose, RESET);//f
            else
            if (len == 2) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p6, mmr[i].win, mmr[i].lose, RESET);//f
            else
            if (len == 1) printf("%s%d|%s%s|%d|%d%s\n",green, mmr[i].num, mmr[i].name, p7, mmr[i].win, mmr[i].lose, RESET);//f
            else{
            printf("Incorrect data in out func\n");
            }
            
        }else {
            len = strlen(mmr[i].name);
            if (len == 8) printf("%d|%s|%d|%d\n", mmr[i].num, mmr[i].name, mmr[i].win, mmr[i].lose);
            else
            if (len == 7) printf("%d|%s%s|%d|%d\n", mmr[i].num, mmr[i].name, p1, mmr[i].win, mmr[i].lose);//f
            else
            if (len == 6) printf("%d|%s%s|%d|%d\n", mmr[i].num, mmr[i].name, p2, mmr[i].win, mmr[i].lose);//f
            else
            if (len == 5) printf("%d|%s%s|%d|%d\n", mmr[i].num, mmr[i].name, p3, mmr[i].win, mmr[i].lose);//f
            else
            if (len == 4) printf("%d|%s%s|%d|%d\n", mmr[i].num, mmr[i].name, p4, mmr[i].win, mmr[i].lose);//f
            else
            if (len == 3) printf("%d|%s%s|%d|%d\n", mmr[i].num, mmr[i].name, p5, mmr[i].win, mmr[i].lose);//f
            else
            if (len == 2) printf("%d|%s%s|%d|%d\n", mmr[i].num, mmr[i].name, p6, mmr[i].win, mmr[i].lose);//f
            else
            if (len == 1) printf("%d|%s%s|%d|%d\n",mmr[i].num, mmr[i].name, p7, mmr[i].win, mmr[i].lose);//f
            else{
            printf("Incorrect data in out func\n");
            }
        }
    }
    fclose(pf);
}

void nousw (int size, users *mmr, char *nick) {//добавляет имя в конец и w+1
    mmr[size].num = size+1;
    mmr[size].win = 1;
    mmr[size].lose = 0;
    strncpy(mmr[size].name, nick, 10);
    mmr[size].n = (float)mmr[size].win/(mmr[size].win+mmr[size].lose);
}

void nousl (int size, users *mmr, char *nick) {//добавляет имя в конец и l+1
    mmr[size].num = size+1;
    mmr[size].win = 0;
    mmr[size].lose = 1;
    strncpy(mmr[size].name, nick, 10);
    mmr[size].n = (float)mmr[size].win/(mmr[size].win+mmr[size].lose);
}



int rating (char *nick, char sim_w_l) {
    users mmr[20];
    users tmp;
    int ind = 0;
    int size = 0;
    int sw = 0;
    FILE *pf = fopen("rating.txt", "r");
    for (int i = 0; addstr(pf, &mmr[i])!= -1; i++) {
        size = i+1;//скопирована база данных и ее размер;
    }
    fclose(pf);
    ind = prow(nick, mmr);
    if (ind != -1){
        if (sim_w_l=='L'){
            mmr[ind].lose++;
        }
        if (sim_w_l=='W'){
            mmr[ind].win++;
        }
    }else {
        if (sim_w_l=='L'){
            nousl(size, mmr, nick);
            size++;
        }
        if (sim_w_l=='W'){
            nousw(size, mmr, nick);
            size++;
        }
    }
    
    for (int i = 0; i<size; i++) {//sort в конце затем вывод в файл
        for (int j = 0; j<(size-i - 1); j++) {
            if(mmr[j].n<mmr[j+1].n) {
                sw = mmr[j].num;
                mmr[j].num = mmr[j+1].num;
                mmr[j+1].num = sw;
                tmp = mmr[j];
                mmr[j] = mmr[j+1];
                mmr[j+1] = tmp;
            }
        }
    }
    FILE *pfin = fopen("rating.txt", "w");
    in_f(mmr, pfin, size, nick);
    fclose(pfin);
    char menu;
    system("clear");
    printf("Желаете вывести статистику?\n"
           "y/n\n");
    scanf("%c",&menu);
    if (menu == 'y') {
        out(size, nick);
    }else{
        system("clear");
        printf("Ничего страшного, посмотрите в следующий раз ;-)\n");
    }
}
