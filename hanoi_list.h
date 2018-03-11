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
#ifndef HANOI_LIST__
#define HANOI_LIST__

#include <stdio.h>
#include <stdlib.h>

#define NUMERO_DISCOS    3 // Number of discs to consider
#define NUMERO_TORRES   3 // Number of towers
#define MOVIMENTS  7    //2^n - 1 on n es el nombre de discs

#define OUTPUT_FILENAME "output.txt"

#define TRUE  1
#define FALSE 0

#define SUCCES TRUE
#define FAIL   FALSE

typedef struct {
    int  move;   // any fields we need to have
    int  recProf;
    int  disc;
    int  from;
    int  to;
} sinfo;

struct tnode{
    sinfo  info; // the information to store in the list
    struct tnode *next; // link to the next element of the list (single & double linked)
    struct tnode *prev; // link to the previous element of the list (double linked only)
};
typedef struct tnode snode;


#if 0
typedef struct{
    sinfo  info; // the information to store in the list
    snode *next; // link to the next element of the list (single & double linked)
    snode *prev; // link to the previous element of the list (double linked only)
}snode;

#endif

typedef struct{
    snode *first;  // access to the first element of the list
    snode *last;   // access to the last element of the list
    snode *actual; // access to the current/last list element consulte
    int    num_moviments; // optional: the number of elements in the list
}slist;

sinfo get_element(sinfo *v, int i);
void init_list(slist *list);
int addlist(slist *list, sinfo info, snode *after);
int deletelist(slist *list, sinfo *info, snode *after);
snode *searchorderlist(slist *list, sinfo info);
int searchnodelist(slist *list, sinfo info, snode **nod);

void print_info(sinfo info, FILE *fdbg);
void print_list(slist list, FILE *fdbg);


#endif HANOI_LIST__
