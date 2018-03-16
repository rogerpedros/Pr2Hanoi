/* 
 *  Grup de Practiques: P401
 * Professor practiques: Angel David Blanco Casales
 * Incidencies:
 *
 * Autor (Nom i NIA): Carlos Hortensius Fernandez 205437
 * Roger Pedros Villalba 206798
 * Marc Gaja Pescador 204885
 * Data/hora:
 * Collaboradors (si cal):
 *
 * Us del programa:
 * Estat de l'entrega: 
 * Altres comentaris o incidencies:
 */

#include <stdio.h>
#include <string.h>
#include "hanoi_engine.h"
#include "hanoi_list.h"
#include "menu.h"

// Recursive function to move nd disks from the origin tower towerorg, to
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of
// the disks to display

void hanoi(int nd, int towerorg, int towerdest, int toweraux, slist *list, matriux mat) {
    static int depth = 0;
    depth++;

    if (nd == 1) {
        move(nd, towerorg, towerdest, depth, list, mat);
        depth--;
        return;
    }

    hanoi(nd - 1, towerorg, toweraux, towerdest, list, mat);
    move(nd, towerorg, towerdest, depth, list, mat);
    hanoi(nd - 1, toweraux, towerdest, towerorg, list, mat);
    depth--;

}// hanoi

//This function indicates a move of one disk

void move(int nd, int towerorg, int towerdest, int profunditat, slist *list, matriux mat) {
    static int count = 0;
    count++;

    printf("\nMoviment: %d. ", count);
    printf("Profunditat %d. Disc %d des de la torre T%d a la torre T%d", profunditat, nd, towerorg, towerdest);

    int i = 0; //Matriu de moviments
    int aux = 0;

//    while (mat.matriu_mov[i][towerorg] == 0) {
//        i++;
//    }
//
//    aux = mat.matriu_mov[i][towerorg];
//    mat.matriu_mov[i][towerorg] = 0;
//
//    i = 0;
//
//    while (mat.matriu_mov[i][towerdest] == 0) {
//        i++;
//    }
//
//    mat.matriu_mov[i - 1][towerdest] = aux;


    setToList(count, profunditat, nd, towerorg, towerdest, list);
    //printToFile();
}

//This function indicates a move of one disk

void setToList(int movementNum, int profunditat, int nd, int towerorg, int towerdest, slist *list) {
    sinfo info;
    sinfo v[] = {{movementNum, profunditat, nd, towerorg, towerdest}};

    int dim = sizeof(v) / sizeof(sinfo);

    // list operations
    int i, j;
    snode *after, *node = NULL;
    int found;


    info = get_element(v, 0);
    after = searchorderlist(list, info);
    addlist(list, info, after);
}

void callHanoi(int nd, slist *list, matriux mat) {
    printf("\nEls moviments dels discos entre les torres de Hanoi son:\n");
    hanoi(nd, 0, 1, 2, list, mat);
}

void repetirHanoi(slist *list, matriux mat) {
    int newNd;
    printf("Entrar numero de discos: ");
    scanf("%d", &newNd);

    callHanoi(newNd, list, mat);
}

int demanarMoviment(slist *list, matriux mat) {
    int userMoveNumber = NULL;
    snode *after, *node = NULL;

    printf("Introdueix el moviment que vols visualitzar;\n");
    scanf("%d", &userMoveNumber);

    sinfo info;
    sinfo v[] = {{userMoveNumber, 0, 0, 0, 0}};
    info = get_element(v, 0);

    after = searchorderlist(list, info);

    node = searchnodelist(list, info, after);

    menu(list, mat);

}
