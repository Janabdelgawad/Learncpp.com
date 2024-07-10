
#include <iostream>
int userInput()
{
	std::cout << "Enter an integer ( 0 - 9 ): ";
	int input{};
	std::cin >> input;

	if (input == 2)
	{
		return true;
	}
	else if (input == 3)
	{
		return true;
	}
	else if (input == 5)
	{
		return true;
	}
	else if (input == 7)
	{
		return true;
	}
	else if (input == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int x{ userInput() };
	if (userInput)
	{
		std::cout << "This digit is prime.\n";
	}
	else
	{
		std::cout << "this digit is not prime.\n";
	}
	return 0;
}