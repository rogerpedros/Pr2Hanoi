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

slist list;

// Recursive function to move nd disks from the origin tower towerorg, to
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of
// the disks to display
void hanoi(int nd, int towerorg, int towerdest, int toweraux, slist *list) {
    static int depth = 0;
    depth++;

    if (nd == 1) {
        move(nd, towerorg, towerdest, depth, list);
        depth--;
        return;
    }

    hanoi(nd - 1, towerorg, toweraux, towerdest, list);
    move(nd, towerorg, towerdest, depth, list);
    hanoi(nd - 1, toweraux, towerdest, towerorg, list);
    depth--;

}// hanoi

//This function indicates a move of one disk
void move(int nd, int towerorg, int towerdest, int profunditat, slist *list) {
    static int count = 0;
    count++;

    printf("\nMoviment: %d. ", count);
    printf("Profunditat %d. Disc %d des de la torre T%d a la torre T%d", profunditat, nd, towerorg, towerdest);

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

//    for (i = 0; i < dim; i++) {
//        info = get_element(v, 1);
//        after = searchorderlist(&list, info);
//        addlist(&list, info, after);
//    }
//    for (i = dim - 1; i >= 2; i--) {
//        info = get_element(v, i);
//        found = searchnodelist(&list, info, &node);
//        deletelist(&list, &info, node);
//    }
//    info = get_element(v, 2);
//    after = searchorderlist(&list, info);
//    addlist(&list, info, after);
//    for (i = 2; i >= 0; i--) {
//        info = get_element(v, i);
//        found = searchnodelist(&list, info, &node);
//        deletelist(&list, &info, node);
//    }


}


void callHanoi(int nd, slist *list) {
    printf("\nEls moviments dels discos entre les torres de Hanoi son:\n");
    hanoi(nd, 0, 1, 2, list);
}

void repetirHanoi(slist *list) {
    int newNd;
    printf("Entrar numero de discos: ");
    scanf("%d", &newNd);

    callHanoi(newNd, list);
}


int demanarMoviment(int moveNumer) {
    int userMoveNumber = NULL;

    printf("Introdueix el moviment que vols visualitzar;\n");
    scanf("%d", userMoveNumber);
}

