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
#include <stdlib.h>
#include "hanoi_list.h"

void agregar_moviment(node* _node) {

    _node->seguent = NULL;
    
    if (primer == NULL) {
        primer = _node;
        ultim = _node;
    } else {
        ultim->seguent = _node;
        ultim = _node;
    }

}

int mostrar_moviment() {

    
    int i;
    for(i=0; i<MOVIMENTS; i++){
        node* Elemento_lista = malloc(sizeof (node));
        Elemento_lista->moviment = "%d Moviment";
        
        agregar_moviment(Elemento_lista);
    }
        node* i;
        
        while(i != NULL){
            printf("%s\n", i->moviment);
            i = i->seguent;
        }
    
}