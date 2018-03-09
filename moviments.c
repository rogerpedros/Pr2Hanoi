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
#include "hanoi_list.h"

int demanar_moviment(int move){
    
    printf("Introdueix el moviment que vols visualitzar;\n");
    scanf("%d", &move);
}



void move(int towerorg, int towerdest){
    
    printf("Move one disc from %d to %d\n", towerorg, towerdest);
    
}