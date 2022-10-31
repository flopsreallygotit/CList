# CList
For average pointers enjoyers.
My simple version of double linked list.

# Main commands
## Constructor and destructor for list
Necessarily for use. Constructs and destructs your list:
```
list *myCoolList = listConstructor();
listDestructor(myCoolList);
```

## Insert after and before
Inserts new element in list after/before pointer you give:
```
list *pointerToNodeWithMyElement = insertAfter(myCoolList, 12); // Inserts 12 to myCoolList->next
insertAfter(pointerToNodeWithMyElement, 3); // Inserts 3 to pointerToNodeWithMyElement->next
```

## Delete node
Removes node from list.
```
deleteNode(pointerToNodeWithMyElement);
```

## Dump
Dumps information about list in terminal.
```
listDump(myCoolList);
```

# Quick start guide

Clone this repo:
```
git clone https://github.com/flopsreallygotit/CList.git
```

Add directory to your project, include CList.h and compile CList.cpp
Change elem_t to type you need. Default: int.

Little example:

```
#include "CList.h"

int main ()
{
  list *myCoolList = listConstructor();

  list *pointerToNodeWithMyElement = insertAfter(myCoolList, 12);
  listDump(myCoolList);

  listDestructor(myCoolList);
  
  return 0;
}
```

Good job! Use it!