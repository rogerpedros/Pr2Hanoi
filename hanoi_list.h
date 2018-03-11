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
#ifndef HANOI_LIST__
#define HANOI_LIST__

#include <stdio.h>
#include <stdlib.h>


#define NUMERO_DISCOS    3 // Number of discs to consider
#define NUMERO_TORRES   3 // Number of towers
#define MOVIMENTS  7    //2^n - 1 on n es el nombre de discs

#define OUTPUT_FILENAME "output.txt"


/*typedef struct {
    struct node* seguent; //Apunta al proxim element
    int num_moviment;
    char moviment;
} node; */

typedef struct{
  int num_moviments;
  struct node *seguent;
}node;


#endif HANOI_LIST__

