#include <malloc.h>
#include <string.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "listUtils.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#pragma GCC diagnostic ignored "-Wunused-parameter"

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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int stringComparator (char *string1, char *string2)
{
    return strcmp(string1, string2);
    
    // Maybe it looks kinda cringe
    // But if you have elem_t = char * and
    // You'll try to put strcmp in listFind directly, it won't compile
    // Because it needs comparator(char *, char *)
    // So i just added one more comparator for char *

    // P.S. if you have elem_t = const char * just use strcmp
}

int integerComparator (int integer1, int integer2)
{
    return integer1 - integer2;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
