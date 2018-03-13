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
#include "file_operations.h"
#include "hanoi_engine.h"
#include "utils.h"

void init_file(char fileName){

}

void createFile(char fileName){
    char fileName2[] = "output.txt";
    FILE *f;
    f = fopen(fileName, "w");
    
    if (f == NULL){
        printf ("No es pot crear el fitxer");
        return;
    }
    
    fclose (f);
}

void writeFileHeadboard(char lineEntered, int nd, char fileName ){
    char fileName2[] = "output.txt";
    FILE *f;
    f = fopen(fileName, "a");

    char date = getHanoiDate();
    
    if (f == NULL){
        printf ("No es pot crear el fitxer");
        return;
    }


    fprintf(f,"\n========================================================================");
    fprintf(f,"\n Command Line entered: %c \n", lineEntered);
    fprintf(f,"\n Numero de torres: %d", NUMERO_TORRES);
    fprintf(f,"\n Numero de discs:  %d", nd);
    fprintf(f,"\n Output FileName:  %c", fileName);
    fprintf(f,"\n File Operation: ap \n");
    fprintf(f,"\n IINT Time:  %c", date);
    fprintf(f,"\n========================================================================");

    fclose (f);
}
            
