#include <malloc.h>
#include <assert.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "list.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listConstructor (list_t *list, 
                      elementDestructor_t elementDestructor,
                      elementComparator_t elementComparator)
{
    if (list == NULL)
        return;

    assert(elementDestructor != NULL &&
           "Element destructor function pointer can't be NULL.");

    // Element comparator function pointer can be NULL.

    list->size = 0;
    list->head = (node_t *) calloc (1, sizeof(node_t));

    assert(list->head != NULL &&
           "Can't allocate memory for list_t head.");

    list->tail = list->head;

    list->elementDestructor = elementDestructor;
    list->elementComparator = elementComparator;

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDestructor (list_t *list)
{
    if (list == NULL)
        return;

    node_t *currentNode = list->head;

    while (currentNode != NULL)
    {
        node_t *currentNodeNext = currentNode->next;

        (list->elementDestructor)(currentNode->element);

        free(currentNode);

        currentNode = currentNodeNext;
    }

    *list = {
                .size = 0,
                .head = NULL,
                .tail = NULL
            };

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node_t *listInsert (list_t *list, elem_t element)
{
    if (list == NULL)
        return NULL;

    node_t *newNode = (node_t *) calloc (1, sizeof(node_t));

    assert(newNode != NULL &&
           "Can't allocate memory for new node_t.");

    newNode->element = element;

    list->tail->next = newNode;
    list->tail = newNode;
    list->size++;

    return newNode;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node_t *listFind (list_t *list, elem_t element)
{
    if (list == NULL)
        return NULL;

    assert(list->elementComparator != NULL &&
           "You need element comparator for list search.");

    node_t *currentNode = list->head->next;
    while (currentNode != NULL)
    {
        if (list->elementComparator(element, currentNode->element) == 0)
            return currentNode;

        currentNode = currentNode->next;
    }

    return NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDumpFunction (list_t *list, 
                       const char *filename, const char *function, 
                       const int line)
{
    if (list == NULL)
        return;
    
    printf("\nList dump at %s:%d in %s\n{\n"
           "\tList size: %lu\n\n\tList head: %p;\n\tList tail: %p;\n\n", 
           filename, line, function,
           list->size, list->head, list->tail);

    node_t *currentNode = list->head;
    while (currentNode != NULL)
    {
        node_t *currentNodeNext = currentNode->next;

        printf("\tNode:\t\t%p\n\tElement:\t" SPECIFICATOR "\n\tNext:\t\t%p\n\n",
               currentNode, currentNode->element, currentNodeNext);

        currentNode = currentNodeNext;
    }

    printf("}\n\n");

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
