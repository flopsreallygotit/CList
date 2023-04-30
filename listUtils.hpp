#pragma once

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "config.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Don't deletes element
/// @param element Element

void passDestruction  (elem_t element);

/// @brief Deletes string
/// @param string Default zero terminated string

void stringDestructor (char *string);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Comparator for strings
/// @param  string1 First string
/// @param  string2 Second string
/// @return Returns sign of difference first different symbols or zero if all corresponding symbols are equal

int stringComparator (char *string1, char *string2);

/// @brief  Comparator for int.
/// @param  integer1 First int.
/// @param  integer2 Second int.
/// @return Returns sign of difference 

int integerComparator (int integer1, int integer2);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
