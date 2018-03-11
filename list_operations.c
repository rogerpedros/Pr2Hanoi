/* Estructures de Dades i Algorismes I 
 * Examples on Dynamic linked lists
 * 
 * Files ExamplesLists.h ExamplesLists.c ExamplesLists-lib.c
 * File: ExamplesLists-lib.c* 
 * 
 * This file contains the library of functions of the dynamic linked lists 
 * 
 * Prepared by: Dolors Sala
 * Date: February 2017
 */

#include <mem.h>
#include "hanoi_list.h"

// to print the information into a file
void print_info(sinfo info, FILE *fdbg){
    //fprintf(fdbg, "(%d, %.2lf)", info.code, info.grade);
}// print_info


// To print all elements in a list
void print_list(slist list, FILE *fdbg){
//    snode *ptr = list.first;
//    fprintf(fdbg, "List (%2d): ", list.num_moviments);
//    while(ptr != NULL){
//        print_info(ptr->info, fdbg);
//        ptr = ptr->next;
//    }
//    fprintf(fdbg, "\n");

    printf("PRINT_LIST NO ESTA FUNCIONANT");

    //print_reverse_list(list, fdbg); // NO FUNCIONA
} // print_list


// Function to initialize the list to empty
void init_list(slist *list){
    list->num_moviments = 0;
    list->first = NULL;
    list->last = list->first;
    list->actual = NULL;
}// init_list

// It creates a linked list node with the information of the element list 
// provided, and initializes the additional node fields as needed. 
// It returns the result of the operation SUCCES when it has it done
// it or FAIL if it was not possible to do it
int encapsulateinfo(sinfo info, snode **nod){
    int ret = SUCCES;
    snode *node = *nod;

    node = (snode*)malloc(sizeof(snode));
    if(node != NULL){
        memcpy(&(node->info), &info, sizeof(sinfo));
        node->next = NULL;
        node->prev = NULL;
    }
    else
        ret = FAIL;
    *nod = node;
    return(ret);
} // encapsulateinfo

// It does the decapsulation of the info from a node (reverse of encapsulateinfo)
// It returns the info inside the node and releases the memory of the 
// disapperaing node. 
// It returns the result of the operation SUCCES when it has it done
// it or FAIL if it was not possible to do it
int decapsulateinfo(sinfo *info, snode *node){
    int ret = SUCCES;

    if(node == NULL)
        ret = FAIL;
    else{
        memcpy(info, &(node->info), sizeof(sinfo));
        free(node);
    }
    return(ret);
} // decapsulateinfo


sinfo get_element(sinfo *v, int i){
    sinfo info;
    memcpy(&info, &(v[i]), sizeof(sinfo));

#if(DEBUG == 1)
    fprintf(fdbg, "Get element %d:", i);
    print_info(info, fdbg);
    //fprintf(fdbg, "\n");
#endif
    return(info);
} // get_element

// To add the information after the node pointed by after, 
// If after is NULL indicates to add as first element.
// it returns the result of the add operation (SUCCES/FAIL)
int addlist(slist *list, sinfo info, snode *after){
    snode *ptr;
    int ret = FAIL;

    ret = encapsulateinfo(info, &ptr);
    if(ret == SUCCES){
        if(after == NULL){ // add as first element
            ptr->next = list->first;
            if(list->first == NULL) // list was empty
                list->last  = ptr;
            else
                list->first->prev = ptr;

            list->first = ptr;
        }else{// add after the node after
            if(after->next != NULL)
                after->next->prev = ptr;
            ptr->next = after->next;
            ptr->prev = after;
            after->next = ptr;
            if(after = list->last)
                list->last = after;
        }
        list->num_moviments++;
    }
#if DEBUG
    fprintf(fdbg," ");
    fprintf(fdbg,"List Element Added:   ");
    print_info(info, fdbg);
    fprintf(fdbg," ");
    print_list(*list, fdbg);
#endif

    return(ret);

}// addlist

// To eliminate the element pointer by node in the list and the return the
// information element
// returns also the result of the delete operation (SUCCES/FAIL)
int deletelist(slist *list, sinfo *info, snode *node){
    int ret = FAIL;

    if(list->first == NULL || list->last == NULL || list->num_moviments <= 0 // empty list
       || node == NULL){ // asks to delete a NULL node
        info = NULL;
    }
    else{ // non-empty list
        if(node->next != NULL)
            node->next->prev = node->prev;
        if(node->prev != NULL)
            node->prev->next = node->next;
        if(node == list->first)
            list->first = node->next;
        else if(node == list->last)
            list->last = node->prev;
        node->next == NULL;
        node->prev == NULL;
        ret = decapsulateinfo(info, node);
        list->num_moviments--;
    }

#if DEBUG
    fprintf(fdbg," ");
    fprintf(fdbg,"List Element Deleted: ");
    print_info(*info, fdbg);
    fprintf(fdbg," ");
    print_list(*list, fdbg);
#endif

} // deletelist

// it compares i1 and i2 and returns the result with the same encoding
// as the strcmp function but according to the info comparison criteria
// It returns 0 if i1 is in order compared to i2, and FALSE othwerwise
// THe current order criteria is i1 > i2 if 
// the code of i2 is greater than the code of i2
// or when the codes are equal and the grade of i1 is
int infocmp(sinfo i1, sinfo i2){
    int ret = 0; // they are equal unless an order is identified

    if(i1.code > i2.code)
        ret = 1;
    else
    if(i1.code < i2.code)
        ret = -1;
    else
    if(i1.grade > i2.grade)
        ret = 1;
    else
    if(i1.grade < i2.grade)
        ret = -1;

    return(ret);
} // infocmp

// it returns the pointer to the node where to add (after) a new element in 
// order according to a order criteria 
snode *searchorderlist(slist *list, sinfo info){
    snode *node = NULL;

    if(list == NULL){
        printf("ERROR: List not initialized\n");
        exit(0);
    }

    if(list->first != NULL){
        node = list->first;
        while(node != NULL && infocmp(info, node->info) < 0){
            node = node->next;
        }
        if(node == list->first)
            node = NULL;
        else if(node == NULL) // it has to be added at the end
            node = list->last;
        else
            node = node->prev;
    }
    else
        node = NULL;
    return(node);
} // searchorderlist

// It searches the node with the information provided. It returns the pointer
// to the node. It returns the result of the operation: 
// SUCCESS = to found 
// FAIL  = when not found and the node returned is NULL
int searchnodelist(slist *list, sinfo info, snode **nod){
    int ret  = FAIL;
    snode *node = *nod;

    if(list == NULL){
        printf("ERROR: List not initialized\n");
        exit(0);
    }

    node = list->first;
    if(list->first != NULL){
        while(node != NULL && infocmp(info, node->info) != 0){
            node = node->next;
        }
        if(node != NULL)
            ret = SUCCES;
    }
    *nod = node;
    return(ret);
} // searchnodelist