#include <malloc.h>
#include <assert.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "listUtils.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

list *listConstructor (void)
{
    list *List = (list *) calloc (1, sizeof(list));

    assert(List != NULL &&
           "Can't allocate memory for list.");

    List->size = 0;

    List->head = (node *) calloc (1, sizeof(node));

    assert(List->head != NULL &&
           "Can't allocate memory for list head.");

    List->tail = List->head;

    return List; 
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

void listDestructor (list *List, 
                     void (*elementDestructor) (elem_t element))
{
    node *currentNode = List->head;

    while (currentNode != NULL)
    {
        node *currentNodeNext = currentNode->next;

        elementDestructor(currentNode->element);

        free(currentNode);

        currentNode = currentNodeNext;
    }

    free(List);

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node *listInsert (list *List, elem_t element)
{
    if (List == NULL)
        return NULL;

    node *newNode = (node *) calloc (1, sizeof(node));

    assert(newNode != NULL &&
           "Can't allocate memory for new node.");

    newNode->element = element;

    List->tail->next = newNode;
    List->tail = newNode;
    List->size++;

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

node *listFind (list *List, elem_t element, 
                int (*comparator) (elem_t element_1, elem_t element_2))
{
    if (List == NULL)
        return NULL;

    node *currentNode = List->head->next;
    while (currentNode != NULL)
    {
        if (comparator(element, currentNode->element) == 0)
            return currentNode;

        currentNode = currentNode->next;
    }

    return NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listDumpFunction (list *List, 
                       const char *filename, const char *function, 
                       const int line)
{
    if (List == NULL)
        return;

    printf("\nList dump at %s:%d in %s\n{\n"
           "\tList head: %p;\n\tList tail: %p;\n\n", 
           filename, line, function,
           List->head, List->tail);

    node *currentNode = List->head;
    while (currentNode != NULL)
    {
        node *currentNodeNext = currentNode->next;

        printf("\tNode:\t\t%p\n\tElement:\t" SPECIFICATOR "\n\tNext:\t\t%p\n\n",
               currentNode, currentNode->element, currentNodeNext);

        currentNode = currentNodeNext;
    }

    printf("}\n\n");

    return;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
