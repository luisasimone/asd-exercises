#include <stdio.h>

#define MAX_STR 25

typedef enum {s_code, s_surname, s_birthday} sort_e;

typedef enum {search_code, search_surn} search_e;

typedef struct date_s {
    int dd;
    int mm;
    int yyyy;
} datet_t;

typedef struct athlete_s {
    char code[MAX_STR];
    char name[MAX_STR];
    char surname[MAX_STR];
    datet_t birthday;
    int category;
    int hours;
} athlete_t;

typedef struct category_s {
    char name[MAX_STR];
} category_t;

typedef struct tabCat_s {
    int nCat;
    int dimVett;
    category_t *log;
} tabCat_t;

typedef struct tabAthl_s {
    int nAthl;
    athlete_t *log;
    tabCat_t tabCat;
    athlete_t *sortCode;
    athlete_t *sortSurn;
    athlete_t *sortDate;
} tabAthl_t;

tabAthl_t readTab(FILE *fp);
int findCategory(char* category, tabCat_t *tab);
int addCategory(char* category, tabCat_t *tab);
void printOnFile(FILE *fp, athlete_t athlete, tabCat_t tab);
char* getCategory(int index, tabCat_t tab);
void printOnScreen (athlete_t athlete, tabCat_t tab);
void printByCategory (tabAthl_t tab);
void insertionSort(athlete_t *v, int N, sort_e sort);
int athletecmp(athlete_t ath1, athlete_t ath2, sort_e sort);
int datecmp(datet_t date1, datet_t date2);
int dateInt(datet_t d);
void DichotomicSearch(athlete_t *v, char* item, int l, int r, search_e cmd, tabCat_t tab) ;
void Search(tabAthl_t tab, char* item, int l, int r, search_e cmd);
void freeTab(tabAthl_t tab);