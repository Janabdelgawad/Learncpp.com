#include "io.h"
#include <iostream>

//get (and return) a single integer from the user.
int readNumber()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;
	return input;
}
//output the answer. 
//take a single parameter 
// and have no return value.
void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << "\n";
}