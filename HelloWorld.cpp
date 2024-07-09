// that can only be divided evenly by 1 and itself.

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
	if (x)
	{
		std::cout << "The digit is prime.\n";
	}
	else
	{
		std::cout << "The digit is not prime.\n";
	}
	return 0;
}


