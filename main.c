/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: hanoi-basic.c
 * 
 * This file contains the full program of basic hanoi game. It only prints the
 * tetx for each move indicating that a disk moves from one orig tower to a 
 * dest tower. It is the starting point with the recursive tool, but it is 
 * capable to show the state of the towers and disks after each move.
 * 
 * It can only operate with 3 towers and the number of disk can be changed 
 * manually changing the value of the define NDISCS.
 * 
 * Prepared by: Dolors Sala
 * Modified: February 2017
 */

#if 1 // exemple torres de hanoi: basic

#include <stdio.h>
#include <string.h>
#include "hanoi_list.h"
#include "hanoi_engine.h"
#include "file_operations.h"
#include "menu.h"

int main(int argc, char **argv) {
    int nd = NUMERO_DISCOS;

    char *fileName;
    fileName = OUTPUT_FILENAME;

    for (int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    for (int i = 0; i < argc; ++i) {
        if (strstr(argv[i], "-d")) {
            printf("He entrat a -d per: argv[%d]: %s\n", i, argv[i]);
            //printf("El numero de discos será  %d", (int)argv[i + 1]);
            //printf("argv[%d]: %s\n", i, argv[i]);
            //sscanf(argv[i++], "%d", &nd);
        }

        if (strstr(argv[i], "-f")) {
            printf("He entrat a -f per: argv[%d]: %s\n", i, argv[i]);
            //printf("El fitxer de sortirda será %s", argv[i + 1]);
            //sscanf(argv[i++], "%c", &fileName);
        }
    }

    repetir_hanoi();
    menu();
    //TODO LA CRIDA AL  MENU HA D'ANAR COL·LOCADA AQUI.
    //Exemples menu: Buscar x moviment. Reptir hanoi. Canviar fitxer output.

    return (0);
} // main


#endif // exemple torres de hanoi : basic

