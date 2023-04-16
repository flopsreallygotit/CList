#ifndef CLIST_H
#define CLIST_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define FREE_ELEMENT_IN_DESTRUCTOR

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Linked list element type.

typedef char * elem_t;

/// @brief Specificator for printf for elem_t.

#define SPECIFICATOR "%s"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief List struct.

typedef struct list
{
    elem_t element = 0;

    list *next = NULL;
} list;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Constructor for list.
/// @return Pointer to list.

list *listConstructor (void);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Destructor for list.
/// @param List Pointer to list.

void listDestructor (list *List);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Inserts element after tail.
/// @param  List Pointer to list.
/// @param  element Element.
/// @return Ponter to list struct.

list *listInsert (list *Node, elem_t element);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Delete node from list.
/// @param node Pointer to list.

void deleteNode (list *Node);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Define for list dump.

#define listDump(List) listDumpFunction(List, __FILE__, __PRETTY_FUNCTION__, __LINE__);

/// @brief List dump.
/// @param List Pointer to list struct.
/// @param filename Name of file from where dump was called.
/// @param function Name of function from where dump was called.
/// @param line Line of code from where dump was called.

void listDumpFunction (list *List, 
                       const char *filename, const char *function, 
                       const int line);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#endif
