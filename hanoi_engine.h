//
// Created by pedro on 12/03/2018.
//

#ifndef PR2HANOI_HANOI_ENGINE_H
#define PR2HANOI_HANOI_ENGINE_H

#define NUMERO_DISCOS    3 // Number of discs to consider
#define NUMERO_TORRES   3 // Number of towers

//extern int nd;

void hanoi(int, int, int, int, int);

void move(int, int, int, int);
void setToList(int, int, int, int, int);

void callHanoi(int);
void repetirHanoi();

int demanarMoviment(int);


#endif //PR2HANOI_HANOI_ENGINE_H
