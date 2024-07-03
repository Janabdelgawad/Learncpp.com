#ifndef ADD_H
#define ADD_H
int add(int x, int y);
#endif ADD_H

/*
header guards are conditional compilation directives that prevent duplicate inclusions
header guards don't prevent a header file from being included (once) into "separate" code files
if a header file was to be included into seperate files under the same program,
the program will compile normally but the linker will fail,
because the program now has multiple definitions for an identifier
SOLUTION: define the function in one of the ".cpp files" and forward declare it in the header files.
-------------------------------------------------------------------------------
Solution.cpp             <- includes header file + defines the function
#include "square.h"
int definedFunction()
{
	return 4;
}

Square.h                 <- has header guard + forward declaration of the defined function
#ifndef SQUARE_H
#define SQUARE_H

int definedFunction();
#endif SQUARE_H
------------------------------------------------------------------------------
simpler form -> #pragma once
#pragma was left to the compiler implementer's vices, to do with it whatever he wants,
but #pragma once was made specifically to avoid header files from being included multiple times.

traditional header guards(ifndef, define, and endif)  vs   pragma once
we guard the header, but with pragma once we request from the compiler to guard it for us.

why did we opt for the traditional guards instead of the less error-prone pragma directive?
because we can't expect all compilers to support pragma, so we define the guards ourselves instead of requesting the compiler to do it.

Why not avoid definitons in header files in the first place?
we don't generally define them in it but it is good practice for it's 1 use case and that is 
non-function definitions, ex: c++ let you create your own types, 
these custom types are typically defined in the header files.

There is 1 case where #pragma once will fail:
If a header file is copied so that it exists in multiple places on the file system,
if somehow both copies of the header get included,
header guards will successfully de-dupe the identical headers,
but #pragma once won’t 
(because the compiler won’t realize they are actually identical content).

in header files:
duplicate functions are UNACCEPTED
		  BUT
duplicate declarations are ACCEPTED
still header guards are preferred even if the header file consists of only declarations.

header guards don't prevent 
the contents of a header file 
from being copied (once) 
into separate project files.
*/