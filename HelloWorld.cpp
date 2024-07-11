
// The program computes the answer on the two numbers the user entered
// and prints the results.
// If the user enters an invalid symbol,
// the program should print nothing.

//Example of program :
/*
Enter a double value : 6.2
Enter a double value : 5
Enter + , -, *, or / : *
6.2 * 5 is 31
*/
#include <iostream>
double userInput()
{
	std::cout << "Enter a double value: ";
	double input{};
	std::cin >> input;
	return input;
}

char userOperator()
{
	std::cout << "Enter + , -, *, or / : ";
	char input{};
	std::cin >> input;
	return input;
}

double result(double x, double y, char z)
{
	if (z == '+')
		return x + y;

	else if (z == '-')
		return x - y;

	else if (z == '*')
		return x * y;

	else if (z == '/')
		return x / y;

	return 0;
}

int main()
{
	double x{ userInput() };
	double y{ userInput() };
	char z{ userOperator() };
	double print{ result(x, y, z) };
	
	std::cout << x << ' ' << z << ' ' << y << " is " << print;
	return 0;
}