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

void createFile(){
    char fileName[] = "output.txt"; 
    FILE *f;
    f = fopen(fileName, "w");
    
    if (f == NULL){
        printf ("No es pot crear el fitxer");
        return;
    }
    
    fclose (f);
    
}

void writeFile(){
    char fileName[] = "output.txt"; 
    FILE *f;
    f = fopen(fileName, "a");
    
    if (f == NULL){
        printf ("No es pot crear el fitxer");
        return;
    }
    fprintf (f, "\n=============================================================================================");
    fprintf(f,"\n Command Line entered:  \n");
    fprintf(f,"\n Numero de torres: %d", NUMERO_TORRES);
    fprintf(f,"\n Numero de discs:  ");
    fprintf(f,"\n Output FileName:  ");  
    fprintf(f,"\n File Operation:  \n"); 
    fprintf(f,"\n IINT Time:  ");
    fprintf (f, "\n=============================================================================================");
    fprintf(f,"\n H 2 ");
    fprintf(f,"\n H 1 ");
    fprintf(f,"\n H 0 ");
    fprintf (f,"\n   ------------------------------------------");
    fclose (f);
}
            
