#include <iostream>
//Write a for-loop that prints every even number from 0 to 20.
void printEven()
{
	for (int i{ 0 }; i <= 20; i += 2)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}
//write a function that returns the sum of all the numbers from 1 to value.
void sumTo(int value)
{
	int f{ 0 };
	for (int i{ 1 }; i <= value;++i)
	{
		f+= i;
	}
	std::cout << f << '\n';
}
/*
replace number divisible only by three with “fizz”, 
number divisible only by five with“buzz”, 
number divisible by both 3 and 5 with “fizzbuzz”.
*/
void fizzbuzz(int countUpTo)
{
	for (int i{ 1 }; i <= countUpTo; ++i)
	{
		bool used{ false };
		if (i % 3 == 0)
		{
			std::cout << "fizz";
			used = true;
		}
		if (i % 5 == 0)
		{
			std::cout << "buzz";
			used = true;
		}
		if (i % 7 == 0)
		{
			std::cout << "pop";
			used = true;
		}
		if (!used) std::cout << i;

		std::cout << '\n';
	}
}

int main()
{
	printEven();
	sumTo(5);
	fizzbuzz(150);
	return 0;
}


