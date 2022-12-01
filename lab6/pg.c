#include <stdio.h>
#include <stdlib.h>

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
    for (curr = list->head; curr != list->tail; curr = curr->next) {
        if (curr->next == node) {
            prev->next = node->next;
        }
        else
            prev = curr;
    }
}

void addObj(node_ptr pg, )