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
#include <string.h>
#include <time.h>
#include "hanoi_list.h"
#include "hanoi_engine.h"
#include "utils.h"


void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

char getHanoiDate() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof (s), "%c", tm); //La data esta en la s
    return s;
}