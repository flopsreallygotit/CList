#include <malloc.h>
#include <assert.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "listUtils.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *listConstructor (void)
{
    list *listPointer = (list *) calloc (1, sizeof(list));

    return listPointer;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void deleteNode (list *node)
{
    if (node == NULL)
        return;

    if (node->prev != NULL)
        node->prev->next = node->next;
    
    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);
    node = NULL;

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDumpFunction (const list *listPointer, const char *filename, const char *function, const int line)
{
    assert(listPointer);

    printf("\nList dump at %s:%d in %s\n{\n", filename, line, function);

    list *currentNextNode = listPointer->next;
    list *currentPrevNode = listPointer->prev;

    #define PRINTFANDSET(currentNode, newCurrentNode)       \
        do                                                  \
        {                                                   \
            printf("\t%-16p " SPECIFICATOR " %-16p\n",    \
                   currentNode->prev,                       \
                   currentNode->element,                    \
                   currentNode->next);                      \
            currentNode = newCurrentNode;                   \
        }                                                   \
        while (0)

    printf("\t%-16p " SPECIFICATOR " %-16p\n", 
           listPointer->prev, 
           listPointer->element, 
           listPointer->next);

    while (currentPrevNode != NULL)
        PRINTFANDSET(currentPrevNode, currentPrevNode->prev);
    
    while (currentNextNode != NULL)
        PRINTFANDSET(currentNextNode, currentNextNode->next);

    #undef PRINTFANDSET

    printf("}\n\n");

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
