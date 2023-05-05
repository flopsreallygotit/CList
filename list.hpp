#pragma once

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stddef.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "config.hpp"
#include "listUtils.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Node struct

typedef struct node_t
{
    elem_t element;

    node_t *next;
} node_t;

typedef void (*elementDestructor_t) (elem_t element);
typedef int  (*elementComparator_t) (elem_t element1, elem_t element2);

/// @brief List struct

typedef struct list_t
{
    size_t size;

    node_t *head;
    node_t *tail;

    elementDestructor_t elementDestructor;
    elementComparator_t elementComparator;
} list_t;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Constructor for list_t
/// @param elementDestructor Function for element memory deallocating
/// @param elementComparator Function that returns difference sign of elem_t elements

void listConstructor (list_t *list, 
                      elementDestructor_t elementDestructor,
                      elementComparator_t elementComparator);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Destructor for list_t

void listDestructor (list_t *list);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Insert element after tail
/// @return Pointer to node_t struct

node_t *listInsert (list_t *list, elem_t element);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Find element in list_t
/// @param  element Element that you want to find
/// @param  comparator Function that compares elements and returns positive number if first is bigger, -1 if it is lower and 0 if they are equal
/// @return Pointer to node_t with required element or NULL if element is not in list_t

node_t *listFind (list_t *list, elem_t element);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Define for list_t dump

#define listDump(list) listDumpFunction(list, __FILE__, __PRETTY_FUNCTION__, __LINE__);

/// @brief List dump
/// @param filename Name of file from where dump was called
/// @param function Name of function from where dump was called
/// @param line Line of code from where dump was called

void listDumpFunction (list_t *list, 
                       const char *filename, const char *function, 
                       const int line);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
