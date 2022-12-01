#include <stdio.h>
#include "pg.h"
#include "inv.h"

//enum menu

//func enum -> cmd

//menu

int main() {
    list_ptr list = initList();
    char* filename = "pg.txt";

    readList(filename, list);

    return 0;
}
