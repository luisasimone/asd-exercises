#include <stdio.h>
#include <stdlib.h>

#include "inv.h"

void readInv(char *filename, tabInv_t *tab) {
    int i, n;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Errore!");
        exit(-1);
    }

    fscanf(fp, "%d", &n);
    tab->log = calloc(n, sizeof(obj_t));
    for (i=0; i<n; i++) {
        fscanf(fp, "%s %s %d %d %d %d %d %d", tab->log[i].name, tab->log[i].type, &tab->log[i].stats.hp, &tab->log[i].stats.mp, &tab->log[i].stats.atk, &tab->log[i].stats.def, &tab->log[i].stats.mag, &tab->log[i].stats.spr);
    }

    fclose(fp);
}

