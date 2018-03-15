//
// Created by pedro on 12/03/2018.
//

#ifndef PR2HANOI_HANOI_ENGINE_H
#define PR2HANOI_HANOI_ENGINE_H

#define NUMERO_DISCOS    3 // Number of discs to consider
#define NUMERO_TORRES   3 // Number of towers

#include "hanoi_list.h"
//extern int nd;

#define PRIMER_DISC ".....-|-....."
#define SEGON_DISC "....--|--...."
#define TERCER_DISC "...---|---..."
#define CUART_DISC "..----|----.."
#define CINQUE_DISC ".-----|-----."
#define SISE_DISC "------|------"



void hanoi(int, int, int, int, int, matriu);

void move(int, int, int, int,matriu);
void setToList(int, int, int, int, int);

void callHanoi(int,matriu);
void repetirHanoi(matriu);

int demanarMoviment(int);


#endif //PR2HANOI_HANOI_ENGINE_H
