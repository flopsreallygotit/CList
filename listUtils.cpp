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

void passDestruction (elem_t element)
{
    return;
}

void stringDestructor (char *string)
{
    free(string);

    return;
}

void listDestructor (list *List, void (*elementDestructor) (elem_t element))
{
    list *currentNode = List;

    while (currentNode != NULL)
    {
        list *currentNodeNext = currentNode->next;

        elementDestructor(currentNode->element);

        currentNode->element = 0;
        currentNode->next = NULL;

        free(currentNode);

        currentNode = currentNodeNext;
    }

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *listInsert (list *Node, elem_t element)
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

int stringComparator (char *string_1, char *string_2)
{
    size_t symbol_idx = 0;
    while (string_1[symbol_idx] != '\0' &&
           string_2[symbol_idx] != '\0' &&
           string_1[symbol_idx] == string_2[symbol_idx])
    {
        symbol_idx++;
    }
    
    if (string_1[symbol_idx] > string_2[symbol_idx])
        return 1;
    
    else if (string_1[symbol_idx] < string_2[symbol_idx])
        return -1;
    
    return 0;
}

int integerComparator (int integer_1, int integer_2)
{
    if (integer_1 > integer_2)
        return 1;
    
    else if (integer_1 < integer_2)
        return -1;
    
    return 0;
}

list *listFind (list *List, elem_t element, 
                int (*comparator) (elem_t element_1, elem_t element_2))
{
    if (List == NULL)
        return NULL;

    list *currentNode = List->next;
    while (currentNode != NULL)
    {
        if (comparator(element, currentNode->element) == 0)
            return currentNode;

        currentNode = currentNode->next;
    }

    return NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

size_t listSize (list *List)
{
    size_t size = 0;

    list *currentNode = List->next; // Head node always contains NULL
    while (currentNode != NULL)
    {
        size++;

        currentNode = currentNode->next;
    }

    return size;
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
