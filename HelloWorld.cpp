#include "io.h"
#include <iostream>
//glue the above functions together
/*
int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	int sum = x + y;
	writeAnswer(sum);
	return 0;
}
*/
void a()
{
	std::cout << "a() called\n";
}

void b()
{
	std::cout << "b() called\n";
	a();
}

int main()
{
	a();
	b();

	return 0;
}

/*
debugging techniques:
conditional using preprocessor statements -> #define ENABLE_DEBUG  #ifdef ENABLE_DEBUG  #endif
issue: having to add/remove debug statements, clutters the code

using a logger (is a sequential record of events)
advantage: seperate from the output
issue with both: they require altering and cluttering the code
-----------------------------------------------------------

THE DEBUGGER
is a computer program that lets us examine a program's state while it's running 

CONFIGURATIONS
debug -> when writing the program
release -> when testing the program

***STEPPING***
STEP INTO: excutes the next statement then pauses (so we can examine the program's state)
F11 OR DEBUG menu 

STEP OVER: // // won't pause until the entire function has been executed (
unlike step into that pauses after each line and return control to you)
F10 or DEBUG menu

step over is used when you are sure that a function already works or dont want to debug it right now

step out executes entire functions and prints result 

difference between step over and step out??
step into -> pause on the first line called
step over -> pause on the next line called
step out -> doesn't pause 

***RUN TO CURSOR***
executes/runs the code until your cursor
CTRL-F10 OR right click a statement and choose run to cursor from the dropdown menu

if you run cursor to a location that doesn't execute, it will run until termination

***CONTINUE***
runs the rest of the program normally
F5 or DEBUG menu (in debug mode)

***START***
just like continue, but runs only from the beginning of the program not the middle
F5 or DEBUG menu (out of debug mode)

***BREAKPOINT***
to stop execution of the program at the breakpoint
F9 or debug menu > toggle breakpoint or right click a statement > toggle breakpoint

brakpoint vs run to cursor??????
breakpoint ran the 3 print statements while run to cursor only the 1st??

***SET NEXT***
jump over a piece of code, it changes the point of execution and skips code
CTRL-SHIFT-F10 or right click on a statement and choose set next (in debug mode)
*/