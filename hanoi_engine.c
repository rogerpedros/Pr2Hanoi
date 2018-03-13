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

// Recursive function to move nd disks from the origin tower towerorg, to
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of
// the disks to display
void hanoi(int nd, int towerorg, int towerdest, int toweraux, int moveCount) {
    int internalCounter  = moveCount;

    if (nd == 1) {
        move(nd, towerorg, towerdest, internalCounter++ );
        return;
    }

    hanoi(nd - 1, towerorg, toweraux, towerdest, internalCounter++);
    move(nd, towerorg, towerdest, internalCounter++);
    hanoi(nd - 1, toweraux, towerdest, towerorg, internalCounter++);

}// hanoi

//This function indicates a move of one disk
void move(int nd, int towerorg, int towerdest, int moveCount) {
    printf("\nMoviment %d. Disc %d des de la torre T%d a la torre T%d",moveCount, nd, towerorg, towerdest);
}


void callHanoi(int nd){
    printf("\nEls moviments dels discos entre les torres de Hanoi son:\n");
    hanoi(nd, 0, 1, 2, 0);
}

void repetirHanoi() {
    int newNd;
    printf("Entrar numero de discos: ");
    scanf("%d", &newNd);

    callHanoi(newNd);
}


int demanarMoviment(int moveNumer) {
    int userMoveNumber = NULL;

    printf("Introdueix el moviment que vols visualitzar;\n");
    scanf("%d", userMoveNumber);
}

