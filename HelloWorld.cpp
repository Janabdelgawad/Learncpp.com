#include <iostream>

int main() {
	//instintiate 2 variables to put the user input in
	int num1{};
	int num2{};

	//ask user to enter 1st integer
	std::cout << "Enter an integer: ";
	std::cin >> num1;

	//take input from user and store it in previously made variables
	std::cout << "Enter another integer: ";
	std::cin >> num2;

	//preform mathematical operations and store each in a seperate variable
	int addition = num1 + num2;
	int subtraction = num1 - num2;

	//print the result of performing the mathematical operations on the user's input
	std::cout << num1 << " + " << num2 << " is " << addition << ".\n";
	std::cout << num1 << " - " << num2 << " is " << subtraction << ".\n";

	return 0;
}



/*
\n -> is a single character in ASCII 
iostream -> input/output library (std::cout/cin)
best naming convention is -> type identifier{}  int x{};
avoid making useless variables(reduce complexity), if something is used once dont make a variable for it.
return 0; purpose -> send to the OS that the program has ran successfully
why? -> programs are dependent on each other they need to render sequentially.
statement -> instruction used to make a program perform some action
function -> a collection of statements sequentially executed (main function)
the name of a function is called? -> an identifier
expression -> used to calculate a value 
statement expression example -> int x{2+3};
cin >>
cout <<
removed all extensions from the compiler to understand c++ standards better without aid, that is why errors more prevelant.
data is? -> any information that can be moved, processed, or stored in a computer
variable -> a "named" piece of memory
variable instantiated -> a variable assigned an address in memory
copy assignment(operator=) -> assign a variable a value
*/
