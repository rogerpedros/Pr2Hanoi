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

void writeFile(){
    char fileName[] = "output.txt"; 
    FILE *f;
    f = fopen(fileName, "a");
    char date = get_hanoi_date();
    
    if (f == NULL){
        printf ("No es pot crear el fitxer");
        return;
    }
    fprintf (f, "\n=============================================================================================");
    fprintf(f,"\n Command Line entered:  \n");
    fprintf(f,"\n Numero de torres: %d", NUMERO_TORRES);
    fprintf(f,"\n Numero de discs:  %d", NUMERO_DISCOS);
    fprintf(f,"\n Output FileName:  ");  
    fprintf(f,"\n File Operation:  \n"); 
    fprintf(f,"\n IINT Time:  %c", date);
    fprintf (f, "\n=============================================================================================");
    fprintf(f,"\n High 2 ");
    fprintf(f,"\n High 1 ");
    fprintf(f,"\n High 0 ");
    fprintf (f,"\n   ------------------------------------------");
    fclose (f);
}
            
