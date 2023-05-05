#pragma once

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "config.hpp"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief Don't deletes element
/// @param element Element

void passDestruction  (elem_t element);

/// @brief Deletes string
/// @param string Default zero terminated string

void stringDestructor (const char *string);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/// @brief  Comparator for int.
/// @param  integer1 First int.
/// @param  integer2 Second int.
/// @return Returns sign of difference 

int integerComparator (const int integer1, const int integer2);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
