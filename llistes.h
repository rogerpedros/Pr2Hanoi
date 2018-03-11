/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Llistes.h
 * Author: usuario
 *
 * Created on 11 de marzo de 2018, 17:27
 */

#ifndef LLISTES_H
#define LLISTES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  move;   // any fields we need to have
    int  recProf;
    int  disc;
    char from;
    char to;
} sinfo;

struct tnode{
    sinfo  info; // the information to store in the list
    struct tnode *next; // link to the next element of the list (single & double linked)
    struct tnode *prev; // link to the previous element of the list (double linked only)
};
//typedef struct tnode snode;

typedef struct{
    sinfo  info; // the information to store in the list
    snode *next; // link to the next element of the list (single & double linked)
    snode *prev; // link to the previous element of the list (double linked only)
}snode;

typedef struct{
    snode *first;  // access to the first element of the list
    snode *last;   // access to the last element of the list
    snode *actual; // access to the current/last list element consulte
    int    num_moviments; // optional: the number of elements in the list
}slist;

#endif /* LLISTES_H */

