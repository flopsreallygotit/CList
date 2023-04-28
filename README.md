# List
For average pointers enjoyers.
My simple version of double linked list.

# Main commands
## Constructor and destructor for list
Necessarily for use. Creates and deletes your list:
```
list *myCoolList = listConstructor();
listDestructor(myCoolList, elementDestructor);
```
P.S. Destructor for list needs destructor for element. There are two default destructors: destructor for string **stringDestructor** (simply frees it) and **passDestruction**, that passes element destruction if it doesn't need it. 

## Insert
Inserts new element in list tail and returns pointer to new node:
```
list *pointerToNodeWithMyElement = listInsert(myCoolList, 3);
```

## Find
Finds element in list and returns pointer to node with it (or NULL if element is not in list). You need function for comparing elements of your type. There are two default comparators for char * and int: stringComparator, integerComparator:
```
list *pointerToMyElement = listFind(List, element, myCoolComparator)
```

## Size
Gets size of list:
```
size_t sizeOfMyCoolList = sizeList(myCoolList);
``` 

## Dump
Dumps information about list in terminal.
```
listDump(myCoolList);
```

# Quick start guide

Clone this repo:
```
git clone https://github.com/flopsreallygotit/List.git
```

Add directory to your project, include listUtils.h and compile listUtils.cpp
Change elem_t to type you need. Default: char *. And change specificator for it. For example you need "%s" for char * and "%d" for int.

Little example:

```
#include "listUtils.h"

int main ()
{
    // Use #define FREE_ELEMENT_IN_DESTRUCTOR for freeing memory allocated for elements in destructor
    // typedef char * elem_t
    // #define SPECIFICATOR "%s"

    list *List = listConstructor();

    char *element = NULL;
    scanf("%ms", &element);

    list *newNode = listInsert(List, element);

    listDump(List);

    listDestructor(List, stringDestructor);

    return 0;
}
```

Good job! Use it!
