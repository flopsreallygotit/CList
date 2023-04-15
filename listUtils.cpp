#include <malloc.h>
#include <assert.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "listUtils.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *listConstructor (void)
{
    return (list *) calloc (1, sizeof(list));
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDestructor (list *List)
{
    list *currentNode = List;

    while (currentNode != NULL)
    {
        list *currentNodeNext = currentNode->next;

        #ifdef FREE_ELEMENT_IN_DESTRUCTOR
        free(currentNode->element);
        #endif

        currentNode->element = 0;
        currentNode->next = NULL;

        free(currentNode);

        currentNode = currentNodeNext;
    }

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *insert (list *Node, elem_t element)
{
    if (Node == NULL)
        return NULL;

    list *newNode = (list *) calloc (1, sizeof(list));
    newNode->element = element;

    list *currentNode = Node;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;

    currentNode->next = newNode;

    return newNode;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDumpFunction (list *List, 
                       const char *filename, const char *function, 
                       const int line)
{
    if (List == NULL)
        return;

    printf("\nList dump at %s:%d in %s\n{\n", filename, line, function);

    list *currentNode = List;
    while (currentNode != NULL)
    {
        list *currentNodeNext = currentNode->next;

        printf("\tNode:\t\t%p\n\tElement:\t" SPECIFICATOR "\n\tNext:\t\t%p\n\n",
               currentNode, currentNode->element, currentNodeNext);

        currentNode = currentNodeNext;
    }

    printf("}\n\n");

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
