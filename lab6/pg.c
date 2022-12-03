#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pg.h"

list_ptr initList() {
    list_ptr list;
    list = malloc(sizeof(*list));

    return list;
}

node_ptr newNode(pg_t pg, node_ptr curr) {
    node_ptr node;
    node = malloc(sizeof(*node));
    node->pg = pg;
    if (curr != NULL)
        curr->next = node;
    return node;
}

void readList(char *filename, list_ptr list) {
    FILE *fp = fopen(filename, "r");
    pg_t curr_pg;
    node_ptr node;

    if (fp == NULL) {
        printf("Errore!");
        exit(-1);
    }

    fscanf(fp, "%s %s %s %d %d %d %d %d %d", &curr_pg.code, curr_pg.name, curr_pg.class, &curr_pg.stats.hp, &curr_pg.stats.mp, &curr_pg.stats.atk, &curr_pg.stats.def, &curr_pg.stats.mag, &curr_pg.stats.spr);
    list->head = newNode(curr_pg, NULL);
    list->tail = list->head;

    while (!feof(fp)) {
        fscanf(fp, "%s %s %s %d %d %d %d %d %d", curr_pg.code, curr_pg.name, curr_pg.class, &curr_pg.stats.hp, &curr_pg.stats.mp, &curr_pg.stats.atk, &curr_pg.stats.def, &curr_pg.stats.mag, &curr_pg.stats.spr);
        list->tail = newNode(curr_pg, list->tail);
    }

    fclose(fp);
}

void addPg(list_ptr list, pg_t pg) {
    list->tail = newNode(pg, list->tail);
}

void removePg(list_ptr list, node_ptr node) {
    node_ptr prev, curr;
    for (curr = list->head; curr != list->tail->next; curr = curr->next) {
        if (curr->next == node) {
            prev->next = node->next;
        }
        else
            prev = curr;
    }
}

void addObj(node_ptr pg, obj_t *obj) {
    if (!obj->equip) {
        pg->pg.obj[pg->pg.nObj] = &obj;
        obj->equip = 1;
    }
}

void removeObj(node_ptr pg, obj_t *obj) {
    int i, k;
    if (obj->equip) {
        for (i = 0; i < pg->pg.nObj; i++) {
            if (pg->pg.obj[i] == &obj) {
                for (k = 0; k < pg->pg.nObj; k++)
                    pg->pg.obj[k] = pg->pg.obj[k + 1];
                pg->pg.obj[k] = NULL;
            }
        }
        obj->equip = 0;
    }
}

void printStats(pg_t pg) {
    int hp=pg.stats.hp, mp=pg.stats.mp, atk=pg.stats.atk, def=pg.stats.def, mag=pg.stats.mag, spr=pg.stats.spr, i;
    for (i=0; i<pg.nObj; i++) {
        hp += pg.obj[i]->stats.hp;
        mp += pg.obj[i]->stats.mp;
        atk += pg.obj[i]->stats.atk;
        def += pg.obj[i]->stats.def;
        mag += pg.obj[i]->stats.mag;
        spr += pg.obj[i]->stats.spr;
    }
    printf("Stats: %d hp, %d mp, %d atk, %d def, %d mag, %d spr\n", hp, mp, atk, def, mag, spr);
}

node_ptr searchPg(list_ptr list, char* code) {
    node_ptr curr;
    for (curr = list->head; curr != list->tail->next; curr = curr->next) {
        if (strcmp(curr->pg.code, code))
            return curr;
    }
}

void printPg(node_ptr pg) {
    int i;
    printf("%s %s %s stats: %d hp, %d mp, %d atk, %d def, %d mag, %d spr\n",
           pg->pg.code, pg->pg.name, pg->pg.class, pg->pg.stats.hp, pg->pg.stats.mp, pg->pg.stats.atk, pg->pg.stats.def, pg->pg.stats.mag, pg->pg.stats.spr);
    printf("Equip: ")
    for (i=0; i<pg->pg.nObj; i++) {
        printf("%s", pg->pg.obj[i]->name);
    }
}

