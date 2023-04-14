#ifndef CLIST_H
#define CLIST_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <malloc.h>
#include <assert.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Linked list element type.

typedef char * elem_t;

/// @brief Specificator for printf for elem_t.

#define SPECIFICATOR "%s"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief List struct.

typedef struct list
{
    list *prev = NULL;

    elem_t element = 0;

    list *next = NULL;
} list;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Constructor for list.
/// @return Pointer to list.

list *listConstructor (void);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Destructor for list.
/// @param listPointer Pointer to list.

void listDestructor (list *listPointer);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Inserts element after previous node.
/// @param previousNode Pointer to list.
/// @param element Element.
/// @return Pointer to list that contains new element.

list *insertAfter (list *previousNode, elem_t element);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Inserts element before next node.
/// @param previousNode Pointer to list.
/// @param element Element.
/// @return Pointer to list that contains new element.

list *insertBefore (list *nextNode, elem_t element);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Delete node from list.
/// @param node Pointer to list.

void deleteNode (list *node);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Define for list dump.
#define listDump(list) \
    listDumpFunction(list, __FILE__, __PRETTY_FUNCTION__, __LINE__);

void listDumpFunction (const list *listPointer, const char *filename, 
                       const char *function, int line);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#endif
