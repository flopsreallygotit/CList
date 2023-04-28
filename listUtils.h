#ifndef LIST_UTILS_H
#define LIST_UTILS_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Linked list element type.

typedef char * elem_t;

/// @brief Specificator for printf for elem_t.

#define SPECIFICATOR "%s"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Node struct.

typedef struct node
{
    elem_t element;

    node *next;
} node;

/// @brief List struct.

typedef struct list
{
    size_t size = 0;

    node *head = NULL;
    node *tail = NULL;
} list;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Constructor for list.
/// @return Pointer to list.

list *listConstructor (void);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Don't deletes element.
/// @param element Element.

void passDestruction  (elem_t element);

/// @brief Deletes string.
/// @param string Default zero terminated string.

void stringDestructor (char *string);

/// @brief Destructor for list.
/// @param List Pointer to list.
/// @param elementDestructor Function for element memory deallocating.

void listDestructor (list *List, void (*elementDestructor) (elem_t element));

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Inserts element after tail.
/// @param  List Pointer to list.
/// @param  element Element.
/// @return Ponter to list struct.

node *listInsert (list *List, elem_t element);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Comparator for strings.
/// @param  string_1 First string.
/// @param  string_2 Second string.
/// @return Returns sign of difference first different symbols or zero if all corresponding symbols are equal.

int stringComparator (char *string_1, char *string_2);

/// @brief  Comparator for int.
/// @param  integer_1 First int.
/// @param  integer_2 Second int.
/// @return Returns sign of difference 

int integerComparator (int integer_1, int integer_2);

/// @brief  Finds element in list.
/// @param  List Pointer to list struct.
/// @param  element Element that you want to find.
/// @param  comparator Function that compares elements and returns positive number if first is bigger, -1 if it is lower and 0 if they are equal.
/// @return Pointer to node with required element or NULL if element is not in list.

node *listFind (list *List, elem_t element, 
                int (*comparator) (elem_t element_1, elem_t element_2));

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
