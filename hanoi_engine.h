//
// Created by pedro on 12/03/2018.
//

#ifndef PR2HANOI_HANOI_ENGINE_H
#define PR2HANOI_HANOI_ENGINE_H

#define NUMERO_DISCOS    3 // Number of discs to consider
#define NUMERO_TORRES   3 // Number of towers
#define MOVIMENTS  7    //2^n - 1 on n es el nombre de discs

int nd;

void hanoi(int, int, int, int);

void move(int, int, int);
int demanar_moviment(int);

#endif //PR2HANOI_HANOI_ENGINE_H
