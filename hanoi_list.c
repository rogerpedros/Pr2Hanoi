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
#include "hanoi_engine.h"


void init_matriu(int nd, int nt, matriux *matriu){
       
    matriu->matriu_mov[nd][nt];
}// init matriu


/*void agregar_moviment(node* _node) {

    node* primer = NULL; //Punter al primer element
    node* ultim = NULL; //Punter al ultim element
    _node->seguent = NULL;


    if (primer == NULL) { //Si la llista esta buida
        primer = _node; //El element que entra es el primer i el ultim
        ultim = _node;
    } else {
        ultim->seguent = _node;
        ultim = _node; //Al contrari, el que acabem de agregar es el ultim
    }

}

int mostrar_moviment() {


    int j;
    // for (j = 0; j < MOVIMENTS; j++) {

    node* Elemento_lista = malloc(sizeof (node)); //Solicitar esapai en memoria
    Elemento_lista->moviment = "Moviment %d:\n";

    // hanoi(nd, 0, 1, 2);
    agregar_moviment(Elemento_lista);
    // }
    node* i = Elemento_lista;

    while (i != NULL) {
        printf("%c\n", i->moviment);
        i = i->seguent;
    }

}
 */

//void moviments() {
//
//    int i;
//    int moviments = 1;
//    for (i = 0; i < NUMERO_DISCOS; i++) {
//        moviments = moviments * 2;
//    }
//    moviments = moviments - 1;
//    moviments = node->num_moviments;
//}
//
//void getValue(myStruct *ptr)
//{
//    printf("\nEnter Data:");
//    scanf("%d",&ptr->data);
//    ptr->next=NULL;
//}
//
//void create_list() {
//
//    node *primer = NULL; //Punter al primer element
//    node *ultim = NULL; //Punter al ultim element
//
//    int size = node->num_moviments;
//    int i;
//
//    for (i = 0; i < size; i++) {
//        // Creating first node
//        if (i == 0) {
//            primer = ultim = malloc(sizeof (node));
//            // getValue(ultim);
//        }// Creating other nodes
//        else {
//            ultim->seguent = malloc(sizeof (node)); // adding new node to the end of non-empty list
//            //  getValue(ultim->seguent); // Insert data into the new node
//            ultim = ultim->seguent; // update tail pointer
//        }
//    }
//    return primer;
//}