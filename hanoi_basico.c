/* 2016-17 Estructures de Dades i Algorismes I
 * 
 * Practice assignment 2: Hanoi Towers Game 
 * File: hanoi-basic.c
 * 
 * This file contains the full program of basic hanoi game. It only prints the
 * tetx for each move indicating that a disk moves from one orig tower to a 
 * dest tower. It is the starting point with the recursive tool, but it is 
 * capable to show the state of the towers and disks after each move.
 * 
 * It can only operate with 3 towers and the number of disk can be changed 
 * manually changing the value of the define NDISCS.
 * 
 * Prepared by: Dolors Sala
 * Modified: February 2017
 */

#if 1 // exemple torres de hanoi: basic

#include <stdio.h>
#include <string.h>
#include "hanoi_list.h"
#include "moviments.c"


// Recursive function to move nd disks from the origin tower towerorg, to 
// destination tower towerdest, using toweraux as auxiliary tower.
// it doesn't return anything and instead it prints information of the move of 
// the disks to display
void towers(int, char, char, char);
void hanoi(int nd, int, int , int);

int main(int argc, char **argv){
    int nd = NUMERO_DISCOS;

    char *fileName;
    fileName = OUTPUT_FILENAME;

    for (int i = 1; i>argc; i++){
        if(strcmp(argv[i], "-d")){
            printf("El numero de discos será  %d", argv[i+1]);
            sscanf(argv[i+1], "%d", &nd);
        }
        if(strcmp(argv[i], "-f")){
            printf("El fitxer de sortirda será %s", argv[i+1]);
            sscanf(argv[i+1], "%d", &fileName);
        }
    }

    printf("Entrar numero de discos: ");
    scanf("%d", &nd);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(nd, 'A', 'C', 'B');

    //hanoi(nd, 0, 1, 2);


    return(0);
} // main

void hanoi(int nd, int towerorg, int towerdest, int toweraux){
    if (nd == 1){
        //move(towerorg, towerdest);
    }

    else{
        hanoi(nd - 1, towerorg, toweraux, towerdest);
        //move(towerorg, towerdest); // aqui es on em de posar x printar tambe
        hanoi(nd - 1, toweraux, towerdest, towerorg);
    }
}// hanoi


void towers(int num, char frompeg, char topeg, char auxpeg) {
    if (num == 1){
        printf("\n Move disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }

    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\n Move disk %d from peg %c to peg %c", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

#endif // exemple torres de hanoi : basic

