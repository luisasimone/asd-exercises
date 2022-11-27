#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "athlete.h"

typedef enum {c_print, c_sort, c_hours, c_search, c_end} input_e;

typedef enum {c_video, c_file, c_category} print_e;

typedef enum {i_input, i_print, i_sort, i_search} index_e;

int findCommand(char *input, int i) {
    char* inputList[5]={"print", "sort", "hours", "search", "end"};
    char* printList[3]={"video", "file", "category"};
    char* sortList[3]={"code", "surname", "date"};
    char* searchList[2]={"code", "surname"};
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
                if (!strcmp(input, printList[k]))
                    return k;
            }
        break;
        case i_sort:
            for (k=0; k<3; k++) {
                if (!strcmp(input, sortList[k]))
                    return k;
            }
        break;
        case i_search:
            for (k=0; k<2; k++) {
                if (!strcmp(input, searchList[k]))
                    return k;
            }
    }
}

input_e menu(tabAthl_t tab) {
    char input[MAX_STR];
    char string[MAX_STR];
    input_e command;
    int i;

    printf("Command = ");
    scanf("%s", input);
    command = findCommand(input, 0);
    switch (command) {
        case c_print:
            {
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
            sort_e cmd;
            printf("Ordinare per codice, cognome o data di nascita? ");
            scanf("%s", string);
            cmd = findCommand(string, 2);
            switch (cmd) {
                case s_code:
                    for (i=0; i<tab.nAthl; i++)
                        printOnScreen(tab.sortCode[i], tab.tabCat);
                break;
                case s_surname:
                    for (i=0; i<tab.nAthl; i++)
                        printOnScreen(tab.sortSurn[i], tab.tabCat);
                break;
                case s_birthday:
                    for (i=0; i<tab.nAthl; i++)
                        printOnScreen(tab.sortDate[i], tab.tabCat);
                break;
            }
        }
        break;
        case c_search: {
            search_e cmd;
            printf("Cercare per codice o per cognome? ");
            scanf("%s", string);
            cmd = findCommand(string, 3);
            switch(cmd) {
                case search_code:
                    break;
                case search_surn:
                    break;
            }
            break;
        }
    }
    return command;
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