/*

For the division operator,
do an integer division, 
and don’t worry about divide by zero.
*/
#include <iostream>

int getInteger()
{
	std::cout << "Enter a number: ";
	int input{};
	std::cin >> input;
	return input;
}
char getChar()
{
	std::cout << "Enter a mathematical operator (+, _, *, /, %): ";
	char input{};
	std::cin >> input;
	return input;
}

int calculate(int x, int y, char z)
{
	switch (z)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		std::cout << "Error message: wrong operator.\n";
		return 0;
	}
}

int main()
{
	int num1{ getInteger() };
	int num2{ getInteger() };
	int character{ getChar() };

	int result{ calculate(num1, num2, character) };
	std::cout << num1 << ' ' << character << ' ' << num2 << " is " << result << '\n';
	return 0;
}