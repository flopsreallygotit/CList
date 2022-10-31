#include <malloc.h>
#include <assert.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "CList.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct list_
{
    list_ *prev = NULL;

    elem_t element = 0;

    list_ *next = NULL;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *listConstructor (void)
{
    list *listPointer = (list *) calloc (1, sizeof(list));

    return listPointer;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDestructor (list *listPointer)
{
    if (listPointer == NULL)
        return;

    list *currentNextNode = listPointer->next;
    list *currentPrevNode = listPointer->prev;
    free(listPointer);

    #define FREEANDSET(currentNode, newCurrentNode) \
        do                                          \
        {                                           \
            list *trash = currentNode;              \
            currentNode = newCurrentNode;           \
            free(trash);                            \
        }                                           \
        while (0)

    while (currentPrevNode != NULL)
        FREEANDSET(currentPrevNode, currentPrevNode->prev);
    
    while (currentNextNode != NULL)
        FREEANDSET(currentNextNode, currentNextNode->next);

    #undef FREEANDSET

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *insertAfter (list *previousNode, elem_t element)
{ 
    if (previousNode == NULL)
        return NULL;
 
    list *newNode = (list *) calloc (1, sizeof(list));
 
    newNode->element = element;
 
    newNode->next      = previousNode->next;
    previousNode->next = newNode;
    newNode->prev      = previousNode;
 
    if (newNode->next != NULL)
        newNode->next->prev = newNode;

    return newNode;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *insertBefore (list *nextNode, elem_t element)
{
    if (nextNode == NULL)
        return NULL;

    list *newNode = (list *) calloc (1, sizeof(list));
 
    newNode->element = element;
 
    newNode->prev  = nextNode->prev;
    nextNode->prev = newNode;
    newNode->next  = nextNode;
 
    if (newNode->prev != NULL)
        newNode->prev->next = newNode;

    return newNode;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDumpFunction (const list *listPointer, const char *filename, const char *function, const int line)
{
    assert(listPointer);

    printf("\nList dump at %s:%d in %s\n{\n", filename, line, function);

    printf("    Previous         Element          Next\n");

    list *currentNextNode = listPointer->next;
    list *currentPrevNode = listPointer->prev;

    #define PRINTFANDSET(currentNode, newCurrentNode)            \
        do                                                       \
        {                                                        \
            printf("    %-16p %-16d %-16p\n", currentNode->prev, \
                   currentNode->element, currentNode->next);     \
            currentNode = newCurrentNode;                        \
        }                                                        \
        while (0)

    printf("    %-16p %-16d %-16p\n", listPointer->prev, listPointer->element, listPointer->next);

    while (currentPrevNode != NULL)
        PRINTFANDSET(currentPrevNode, currentPrevNode->prev);
    
    while (currentNextNode != NULL)
        PRINTFANDSET(currentNextNode, currentNextNode->next);

    #undef PRINTFANDSET

    printf("}\n");

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
