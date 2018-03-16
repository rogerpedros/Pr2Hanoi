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

/*Aquesta funció crea el fitxer*/
void createFile(char *fileName) {
    //char fileName2[] = "../eutput.txt";
    FILE *f;
    f = fopen(fileName, "w");

    if (f == NULL) {
        printf("El fitxer ja existeix o no es pot crear");
        return;
    }

    fclose(f);
}
/*Printa la cabecera inicial del fitxer*/
void writeFileHeadboard(char *lineEntered, int nd, char *fileName) {
    //char fileName2[] = "output.txt";
    FILE *f;
    f = fopen(fileName, "a");

    time_t curtime;
    time(&curtime);

    if (f == NULL) {
        printf("El fitxer ja existeix o no es pot crear");
        return;
    }

    fprintf(f, "\n========================================================================");
    fprintf(f, "\n Command Line entered: %s \n", lineEntered);
    fprintf(f, "\n Numero de torres: %d", NUMERO_TORRES);
    fprintf(f, "\n Numero de discs:  %d", nd);
    fprintf(f, "\n Output FileName:  %s",  fileName);
    fprintf(f, "\n File Operation: ap \n");
    fprintf(f, "\n INIT Time:  %s", ctime(&curtime));
    fprintf(f, "\n========================================================================");

    fclose(f);
}

/*Printa cada moviment al txt*/
void printToFile(int move, int nd, int towerorg, int towerdest, int profunditat, char* fileName) {
    FILE *f;
    f = fopen(fileName, "a");

    fprintf(f, "\nMoviment: %d Profunditat %d. Disc %d des de la torre T%d a la torre T%d", move, profunditat, nd, towerorg, towerdest);
    fclose(f);

    //imprimirGraficament(fileName, ); PROBLEMES
    //preMatriu(nd, 3,); PROBLEMES

}

/*Printa la matriu que va seguida de la cabecera. DONA PROBLEMES EN LA ITERACIÓ DE LA MATRIU*/
void preMatriu(int nd, int torres, matriux matriu) {

    int comptador = nd - 1;
    printf("Hanoi Tower State Matrix ----  \n");
    int i, j;
    for (i = 0; i < nd; i++) {
        printf("High %d |", comptador);
        for (j = 0; j < torres; j++) {
            if (j == 0) {
                //matriu[i][j] = i + 1;PROBLEMES
            } else {
               //matriu[i][j] = 0;PROBLEMES
            }
            //printf("%d ", //matriu[i][j]); PROBLEMES
        }
        printf("\n");
        comptador--;
    }
    printf("          _ _ __\n");
}

/*Funcions per generar dinamicament les torres*/
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
/*Funciono per generar graficament les torres. Aquesta funció utilitza les 3 funcions anterios. PROBLEES D'ITERACIO DE MATRIU */
void imprimirGraficament(char *fileName, matriux *mat){
    FILE *f;
    f = fopen(fileName, "a");

    int comptador = NUMERO_DISCOS - 1;
    int i, j;
    for (i = 0; i < NUMERO_DISCOS; i++) {
        printf("H %d |", comptador);
        for (j = 0; j < NUMERO_TORRES; j++) {
            //imprimirLinea(mat[i][j], f); PROBLEMES
        }
        printf("\n");
        comptador--;
    }
    fprintf(f, "--------------------------------------------------\n\n");
}

