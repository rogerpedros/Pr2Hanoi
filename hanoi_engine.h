//
// Created by pedro on 12/03/2018.
//

#ifndef PR2HANOI_HANOI_ENGINE_H
#define PR2HANOI_HANOI_ENGINE_H

#include "hanoi_list.h"

#define NUMERO_DISCOS    3 // Number of discs to consider
#define NUMERO_TORRES   3 // Number of towers

#define PRIMER_DISC ".....-|-....."
#define SEGON_DISC "....--|--...."
#define TERCER_DISC "...---|---..."
#define CUART_DISC "..----|----.."
#define CINQUE_DISC ".-----|-----."
#define SISE_DISC "------|------"

void hanoi(int, int, int, int, slist*, matriux );
void move(int, int, int, int, slist*, matriux );
void setToList(int, int, int, int, int, slist*);

void callHanoi(int, slist*, matriux );
void repetirHanoi(slist*, matriux );

int demanarMoviment(int, slist*);


#endif //PR2HANOI_HANOI_ENGINE_H
