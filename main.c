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
    matriux mat;

    slist list;
    init_list(&list);

    int nd = NUMERO_DISCOS;
    char fileName[] = OUTPUT_FILENAME;

    for (int i = 0; i < argc; ++i) {
        if ( (strstr(argv[i], "-d")) && (i != 0) ){
            printf("El numero de discos entrat es:  %i \n", atoi(argv[i + 1]));
            sscanf(argv[i+1], "%d", &nd);
        }

        if ( (strstr(argv[i], "-f")) && (i != 0) ) {
            printf("El fitxer de sortirda entrat sera: %s \n", argv[i+1]);
            sscanf(argv[i+1], "%p", &fileName);
        }
    }
    
    init_matriu(nd, 3, &mat);
    
    //createFile(fileName); problemes
    //writeFileHeadboard(argv[0], nd, fileName);
    callHanoi(nd, &list, &mat);
    menu(&list, &mat);

    return (0);
} // main


#endif // exemple torres de hanoi : basic

