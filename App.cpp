#include <iostream>

void doSomething() {

	#ifdef PRINT_MEOW "meow printed"
		std::cout << PRINT_MEOW;
	#endif

	#ifndef PRINT_MEOW
		std::cout << "meow not printed";
	#endif
}