#include <stdio.h>
#include "CList.h"

int main()
{
    list *testList = listConstructor();

    list *newNextNode = insertAfter(testList, 2);
    insertAfter(newNextNode, 3);

    listDump(testList);

    list *newPrevNode = insertBefore(testList, -2);
    insertBefore(newPrevNode, -3);

    listDump(testList);

    listDestructor(testList); 

    return 0;
}