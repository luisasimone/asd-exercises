#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "athlete.h"

void initTabCat(tabCat_t *tab) {
    tab->dimVett = 1;
    tab->nCat = 0;
    tab->log = calloc(tab->dimVett, sizeof(category_t));
    //TODO: check if calloc returns error, return error in that case?
}

int findCategory(char* category, tabCat_t *tab) {
    int i;

    for (i=0; i<tab->nCat; i++) {
        if (!strcmp(category, tab->log[i].name))
            return i;
    }

    return -1;
}

int addCategory(char* category, tabCat_t *tab) {
    if (tab->dimVett == tab->nCat) {
        tab->dimVett = tab->dimVett * 2;
        tab->log = realloc(tab->log, sizeof(category_t)*tab->dimVett);
    }

    strcpy(tab->log[tab->nCat].name, category);

    return tab->nCat;
}

tabAthl_t readTab(FILE *fp) {
    tabAthl_t tabAthl;
    tabCat_t tabCat;
    char category[MAX_STR];
    int i, indexCategory;

    if (fp == NULL) {
        printf("Errore nell'apertura del file");
        exit(-1);
    }

    fscanf(fp, "%d", &tabAthl.nAthl);
    tabAthl.log = calloc(tabAthl.nAthl, sizeof(athlete_t));
    tabAthl.sortCode = calloc(tabAthl.nAthl, sizeof(athlete_t));
    tabAthl.sortSurn = calloc(tabAthl.nAthl, sizeof(athlete_t));
    tabAthl.sortDate = calloc(tabAthl.nAthl, sizeof(athlete_t));

    initTabCat(&tabCat);

    for (i=0; i<tabAthl.nAthl; i++) {
        fscanf(fp, "%s %s %s %s %d %d/%d/%d", tabAthl.log[i].code, tabAthl.log[i].name, tabAthl.log[i].surname, 
        category, &tabAthl.log[i].hours, &tabAthl.log[i].birthday.dd, &tabAthl.log[i].birthday.mm, &tabAthl.log[i].birthday.yyyy);

        indexCategory = findCategory(category, &tabCat);
        if (indexCategory == -1) {
            indexCategory = addCategory(category, &tabCat);
            tabCat.nCat++;
        }
        tabAthl.log[i].category = indexCategory;
    }

    tabAthl.tabCat = tabCat;

    for (i=0; i<tabAthl.nAthl; i++) {
        tabAthl.sortCode[i] = tabAthl.log[i];
        tabAthl.sortDate[i] = tabAthl.log[i];
        tabAthl.sortSurn[i] = tabAthl.log[i];
    }

    insertionSort(tabAthl.sortCode, tabAthl.nAthl, s_code);
    insertionSort(tabAthl.sortSurn, tabAthl.nAthl, s_surname);
    insertionSort(tabAthl.sortDate, tabAthl.nAthl, s_birthday);

    return tabAthl;
}

char* getCategory(int index, tabCat_t tab) {
    return tab.log[index].name;
}

void printOnFile(FILE *fp, athlete_t athlete, tabCat_t tab) {
    fprintf(fp, "%s %s %s %d/%d/%d %s con %d ore settimanali\n", athlete.code, athlete.name, athlete.surname, athlete.birthday.dd, athlete.birthday.mm,
    athlete.birthday.yyyy, getCategory(athlete.category, tab), athlete.hours);
}

void printOnScreen (athlete_t athlete, tabCat_t tab) {
    printf("%s %s %s %d/%d/%d %s con %d ore settimanali\n", athlete.code, athlete.name, athlete.surname, athlete.birthday.dd, athlete.birthday.mm,
    athlete.birthday.yyyy, getCategory(athlete.category, tab), athlete.hours);
}

void printByCategory (tabAthl_t tab) {
    int i, k;

    for (i=0; i<tab.tabCat.nCat; i++) {
        printf("Categoria: %s\n", getCategory(i, tab.tabCat));
        for (k=0; k<tab.nAthl; k++) {
            if (i == tab.log[k].category)
                printOnScreen(tab.log[k], tab.tabCat);
        }
    }
}


int dateInt(datet_t d) {
    return d.yyyy*1000+d.mm*100+d.dd;
}

int datecmp(datet_t date1, datet_t date2) {
    int dateInt1 = dateInt(date1), dateInt2 = dateInt(date2);
    if (dateInt1 < dateInt2)
        return -1;
    else if (dateInt1 > dateInt2)
        return 1;
    else
        return 0;
}

int athletecmp(athlete_t ath1, athlete_t ath2, sort_e sort) {
    switch (sort) {
        case s_code:
            return strcmp(ath1.code, ath2.code);
        case s_surname:
            {
                int index = strcmp(ath1.surname, ath2.surname);
                if (index != 0)
                    return index;
                else
                    return strcmp(ath1.name, ath2.name);
            }
        case s_birthday:
            return datecmp(ath1.birthday, ath2.birthday);
    }
}

void insertionSort(athlete_t *v, int N, sort_e sort) {
    int i, j, l=0, r=N-1;
    athlete_t item;

    for (i=l+1; i<=r; i++) {
        item = v[i];
        j = i-1;
        while (j >= l && athletecmp(item, v[j], sort)<0) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = item;
    }
}

void Search() {

}