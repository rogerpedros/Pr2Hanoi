#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llistes.h"

sinfo get_element(sinfo *v, int i) {
    sinfo info;

    memcpy(&info, &(v[i]), sizeof (sinfo));
}

int addlist(slist *list, sinfo info, snode *after) {
    snode *ptr;
    int ret = FAIL;

    ret = encapsulateinfo(info, &ptr);
    if (ret == SUCCES) {
        if (after == NULL) { // add as first element
            ptr->next = list->first;
            if (list->first == NULL) // list was empty
                list->last = ptr;
            else
                list->first->prev = ptr;

            list->first = ptr;
        } else {// add after the node after
            if (after->next != NULL)
                after->next->prev = ptr;
            ptr->next = after->next;
            ptr->prev = after;
            after->next = ptr;
            if (after == list->last)
                list->last = ptr;
        }
        list->nelems++;
    }

    snode * searchorderlist(slist *list, sinfo info) {
        snode *node = NULL;

        if (list == NULL) {
            printf("ERROR: List not initialized\n");
            exit(0);
        }

        if (list->first != NULL) {
            node = list->first;
            while (node != NULL && infocmp(info, node->info) < 0) {
                node = node->next;
            }
            if (node == list->first)
                node = NULL;
            else if (node == NULL) // it has to be added at the end
                node = list->last;
            else
                node = node->prev;
        } else
            node = NULL;
        return (node);
    } // searchorderlist

    int searchnodelist(slist *list, sinfo info, snode **nod) {
        int ret = FAIL;
        snode *node = *nod;

        if (list == NULL) {
            printf("ERROR: List not initialized\n");
            exit(0);
        }

        node = list->first;
        if (list->first != NULL) {
            while (node != NULL && infocmp(info, node->info) != 0) {
                node = node->next;
            }
            if (node != NULL)
                ret = SUCCES;
        }
        *nod = node;
        return (ret);
    } // searchnodelist

    int encapsulateinfo(sinfo info, snode **nod) {
        int ret = SUCCES;
        snode *node = *nod;

        node = (snode*) malloc(sizeof (snode));
        if (node != NULL) {
            memcpy(&(node->info), &info, sizeof (sinfo));
            node->next = NULL;
            node->prev = NULL;
        } else
            ret = FAIL;
        *nod = node;
        return (ret);
    } // encapsulateinfo

    // It does the decapsulation of the info from a node (reverse of encapsulateinfo)
    // It returns the info inside the node and releases the memory of the 
    // disapperaing node. 
    // It returns the result of the operation SUCCES when it has it done
    // it or FAIL if it was not possible to do it

    int decapsulateinfo(sinfo *info, snode * node) {
        int ret = SUCCES;

        if (node == NULL)
            ret = FAIL;
        else {
            memcpy(info, &(node->info), sizeof (sinfo));
            free(node);
        }
        return (ret);
    } // decapsulateinfo
    