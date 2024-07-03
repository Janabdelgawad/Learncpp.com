#include "app.h"
#include <iostream>

int app(int x, int y) {
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another number: ";
	int y{};
	std::cin >> y;

	return x + y;
}

/*
#include
angled brackets <> -> non user-defined (comes with the compiler/ standard)
double quotes "" -> user-defined 

what are header files? files that include all of our declarations then imports them into our files.
making header files are the same as source files but instead of choosing source in settings choose header.
suffix used in source files -> .cpp                 suffix used in header files -> .h

header files should be paired with code/source files &
generally, both have the same name ex: add.cpp & add.h

header file contains: 1) header guard.     2)content (declarations).


content of the #include are included at the same point of inclusion that the directive was written in.

process of compilation
main.cpp that includes #include <iostream>:

1) compile main.cpp      2) compile header file (iostream)    
3) both turn into machine code in an intermediary file (main.o) between compiling and linking phases)    
4)link all files in program(if there are any) including the standard c++ library
5)combine all into the executable file.
A file ending in .o : The compiler creates an object file for each source file, before linking them together, into the final executable.

Do not put function and variable definitions in your header files (for now).
Defining these in a header file will result in a violation of the one-definition rule (ODR) 
if that header is then #included into more than one source (.cpp) file.
safe definitions that can be definied in the header file include: inline-functions, inline variables, types, and templates.

.cpp files shouldn't be included like header files
1) header files rarely changes, unlike .cpp files
so if any included .cpp file had changes done, the program will have to recompile all files again
2) naming collision amongst source files
3) in larger projects. mainataining ODR will be difficult

TROUBLESHOOTING:
1)make sure files are named correctly
2)make sure files are all under the same directory

Why doesn’t iostream have a .h extension?
it used to then another c++ version was made but older files wouldn't compile with to so the newer version omitted .h extension

why the change in versions?
to move all of the names used in the standard library into the std namespace 
to help avoid naming conflicts with user-declared identifiers.

conclusion: use .h extension for user-defined headers(add.h) and 
NOTTT the standard library header files(iostream) 

how to add files from other directories?
 DON'T include them in file  -> reflects directory structure -> wont run
 DO, in vs studio right click project > properties > VC++ directories > add whatever directories you want -> doesnt change structure 
 so the compiler would know where to look at to find mentoned header files 
 if they werent found in current directory

 header files could include other header files
 these files are called transitive includes 
 they are included implicitly not explicitly, 
 so they should be avoided in case the implementation of header files changes in the future 
 EXPLICITLY INCLUDE HEADER FILES

 header file A, header file B, source file C
 A is explicitly included
 i havent included B yet, but the code still compiles why?
 B could be implicitly included inside of A
even though this compiled your program without errors it should be avoided
and  re-include B explicitly, because what could work on your machine may not work on another
-why was this important? 
because, there is no easy way to detect when your code file is accidentally relying on content of a transitive include.

order your #includes as follows, to reduce compiler flags:

1) The paired header file
2) Other headers from your project
3) 3rd party library headers
4) Standard library headers

header files should be INDEPENDENT from each other as much as possible

Document WHAT something does or how to USE it in the header. 
Document HOW something works in the source files.
*/