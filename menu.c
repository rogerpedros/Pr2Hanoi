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
#include "menu.h"
#include "hanoi_list.h"
#include "hanoi_engine.h"
#include "utils.h"

int read_option(const char* msg) {
    int option = OPTION_INVALID;
    printf("%s", msg);
    scanf("%d", &option);

    flush_input();

    return option;
}

int query_option() {
    printf("\n\n");
    printf( MSG_REPEAT_HANOI, OPTION_REPEAT_HANOI);
    printf(MSG_SHOW_MOVEMENT, OPTION_SHOW_MOVEMENT);
    printf(MSG_CHANGE_OUTPUT, OPTION_CHANGE_OUTPUT);
    printf(MSG_QUIT, OPTION_QUIT);

    return read_option("Tria una opcio: ");
}

void menu(slist *list, matriux mat) {
    int option = query_option();
    while (option != OPTION_QUIT) {

        switch (option) {
            case OPTION_REPEAT_HANOI:
                repetirHanoi(list, mat);
                break;

            case OPTION_SHOW_MOVEMENT:
                demanarMoviment(list);
                break;

            case  OPTION_CHANGE_OUTPUT:
                
                break;

            default:
                printf("\nInvalid option. Try again...\n\n");
                break;
        }

        printf("\nPress enter to continue...");
        flush_input();

        option = query_option();
    }
}