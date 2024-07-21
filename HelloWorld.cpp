#include <iostream>

int getInt()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;
	return input;
}

constexpr bool isEven(int num)
{
	return ((num % 2) == 0) ? true : false;
}

void printNum(bool x, int num)
{
	if (x)
		std::cout << num << " is even";
	else
		std::cout << num << " is odd";
}

int main()
{
	const int num{ getInt() };
	const bool evenOrOdd{ isEven(num) };
	printNum(evenOrOdd, num);
	return 0;
}