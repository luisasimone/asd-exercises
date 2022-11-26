#include <stdlib.h>
#include <stdio.h>
#include "athlete.h"

typedef enum {c_print, c_sort, c_hours, c_search, c_end} input_e;

typedef enum {c_video, c_file, c_category} print_e;

typedef enum {i_input, i_print, i_ord} index_e; 

int findCommand(char *input, int i) {
    char inputList[5]={"print", "ord", "hours", "search", "end"};
    char printList[3]={"video", "file", "category"};
    char sortList[3]={"code", "surname", "date"};
    int k;

    switch ((index_e) i) {
        case i_input:
            for (k=0; k<5; k++) {
                if (!strcmp(input, inputList[k]))
                    return k;
            }
        break;
        case i_print:
            for (k=0; k<3; k++) {
                if (!strcmp(input, printList[k]));
                    return k;
            }
        break;
        case i_ord:
            for (k=0; k<3; k++) {
                if (!strcmp(input, sortList[k]));
                    return k;
            }
        break;
    }
}

input_e menu(tabAthl_t tab) {
    char input[MAX_STR];
    input_e command;

    printf("Command = ");
    scanf("%s", input);
    command = findCommand(input, 0);
    switch (command) {
        case c_print:
            {   int i;
                char string;
                print_e cmd;
                printf("Stampare a video, su file o per categoria? ");
                scanf("%s", string);
                cmd = findCommand(string, 1);
                switch (cmd) {
                    case c_video: {
                        for (i=0; i<tab.nAthl;i++) {
                            printOnScreen(tab.log[i], tab.tabCat);
                        }
                    }
                    break;
                    case c_file: {
                        FILE *fout;
                        fout = fopen("output.txt", "w");
                        
                        for (i=0; i<tab.nAthl;i++) {
                            printOnFile(fout, tab.log[i], tab.tabCat);
                        }
                        fclose(fout);
                    }
                    break;
                    case c_category:
                        printByCategory(tab);
                    break;
                }
            }
        break;
        case c_sort: 
        {
            char string;
            sort_e cmd;
            printf("Ordinare per codice, cognome o data di nascita? ");
            scanf("%s", string);
            cmd = findCommand(string, 2);
            switch (cmd) {
                case s_code:
                
                break;
                case s_surname:
                break;
                case s_birthday:
                break;
            }
        }
        break;
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
        break;
        case s_surname:
            {
                int index = strcmp(ath1.surname, ath2.surname);
                if (index != 0)
                    return index;
                else
                    return strcmp(ath1.name, ath2.name);
            }
        break;
        case s_birthday:
            return datecmp(ath1.birthday, ath2.birthday);
        break;
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

int main() {
    input_e input;
    FILE *fp = fopen("atleti.txt", "r");
    tabAthl_t tab = readTab(fp);

    do {
        input = menu(tab);
    } while (input != c_end);
    //free
}