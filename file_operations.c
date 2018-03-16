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
#include <string.h>
#include <time.h>
#include "file_operations.h"
#include "hanoi_engine.h"
#include "utils.h"

void createFile(char *fileName) {
    //char fileName2[] = "../eutput.txt";
    FILE *f;
    f = fopen(fileName, "w");

    if (f == NULL) {
        printf("No es pot crear el fitxer");
        return;
    }

    fclose(f);
}

void writeFileHeadboard(char *lineEntered, int nd, char *fileName) {
    //char fileName2[] = "output.txt";
    FILE *f;
    f = fopen(fileName, "a");

    time_t curtime;
    time(&curtime);

    if (f == NULL) {
        printf("No es pot crear el fitxer");
        return;
    }

    fprintf(f, "\n========================================================================");
    fprintf(f, "\n Command Line entered: %c \n", (unsigned char) lineEntered);
    fprintf(f, "\n Numero de torres: %d", NUMERO_TORRES);
    fprintf(f, "\n Numero de discs:  %d", nd);
    fprintf(f, "\n Output FileName:  %c",  fileName);
    fprintf(f, "\n File Operation: ap \n");
    fprintf(f, "\n INIT Time:  %s", ctime(&curtime));
    fprintf(f, "\n========================================================================");

    fclose(f);
}


void imprimirPuntos(int i, FILE *f){
    int j = 0;
    for (j = 0; j<i; j++){
        fprintf(f, ".");
    }
}

void imprimirDiscos(int i, FILE *f){
    int j = 0;
    for (j = 0; j<i; j++){
        fprintf(f, "-");
    }
}

void imprimirLinea(int i, FILE *f){
    int nd = NUMERO_DISCOS;

    imprimirPuntos(nd - i, f);
    imprimirDiscos(i, f);
    fprintf(f, "|");
    imprimirDiscos(i, f);
    imprimirPuntos(nd - 1, f);
    fprintf(f, "  ");

}


//imprimirhanoi(FILE *f, int **matriu){
//
//    int comptador = NUMERO_DISCOS - 1;
//    int i, j;
//    for (i = 0; i < NUMERO_DISCOS; i++) {
//        printf("H %d |", comptador);
//        for (j = 0; j < NUMERO_TORRES; j++) {
//            imprimirHanoi(f, matriu[i][j]);
//        }
//        printf("\n");
//        comptador--;
//    }
//    fprintf(f, "   ------------------------------------------------\n\n");
//}

