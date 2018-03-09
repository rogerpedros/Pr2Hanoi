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
#include "torres.c"

void init_discos(){
    
    int i;
    int j;
    int disco=1;
    int matriu[NUMERO_DISCOS][NUMERO_TORRES];
    init_torres(matriu);
    
    for(i=0; i<NUMERO_DISCOS; i++){
        matriu[i][0]= disco;
        disco++;
    }
}