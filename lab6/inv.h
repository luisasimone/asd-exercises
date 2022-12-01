#ifndef LAB6_INV_H
#define LAB6_INV_H

#define MAX_STR 25

typedef struct statsEdit_s {
    signed int hp;
    signed int mp;
    signed int atk;
    signed int def;
    signed int mag;
    signed int spr;
} statsEdit_t;

typedef struct obj_s {
    char name[MAX_STR];
    char type[MAX_STR];
    int equip;
    statsEdit_t stats;
} obj_t;

typedef struct tabInv_s {
    int n;
    obj_t *log;
} tabInv_t;

void readInv(char *filename, tabInv_t *tab);

#endif //LAB6_INV_H
