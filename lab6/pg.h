#ifndef LAB6_PG_H
#define LAB6_PG_H

#define MAX_STR 50

#include "inv.h"

typedef struct stats_s {
    int hp;
    int mp;
    int atk;
    int def;
    int mag;
    int spr;
} stats_t;

typedef struct pg_s {
    char code[MAX_STR];
    char name[MAX_STR];
    char class[MAX_STR];
    stats_t stats;
    obj_t* obj[8];
    int nObj;
} pg_t;

typedef struct node_s *node_ptr;
typedef struct list_s *list_ptr;

typedef struct node_s {
    pg_t pg;
    node_ptr next;
} node_t;

typedef struct list_s {
    node_ptr head;
    node_ptr tail;
    node_ptr z;
    int nPg;
} list_t;

list_ptr initList();
node_ptr newNode(pg_t pg, node_ptr next);
void readList(char *filename, list_ptr list);
void addPg(list_ptr list, pg_t pg);
void removePg(list_ptr list, node_ptr node);
void removeObj(node_ptr pg, obj_t *obj);
void printStats(pg_t pg);
#endif //LAB6_PG_H
