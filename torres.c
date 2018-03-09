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

int init_torres(int matriu[NUMERO_DISCOS][NUMERO_TORRES]) { //Initcialitza un matriu de les torres totes en 0

    int i;
    int j;

    for (i = 0; i < NUMERO_DISCOS; i++) {
        for (j = 0; j < NUMERO_TORRES; j++) {
            matriu[i][j] = 0;
        }
    }
}

