/*
A “perfect square” is a natural number whose square root is an integer.
We can make perfect squares by multiplying a natural number (including zero) by itself.
The first 4 perfect squares are: .

Repeatedly ask the user to enter a single digit integer, or -1 to quit.
Print whether the digit the user entered is a perfect square.

The output should match the following:

Enter a single digit integer, or -1 to quit: 4
4 is a perfect square

Enter a single digit integer, or -1 to quit: 5
5 is not a perfect square

Enter a single digit integer, or -1 to quit: -1
Bye
Hints: Use a range-based for loop to traverse the C-style array to look for a match.
*/
#include <iostream>

int main()
{
	constexpr int perfectSquaresArray[] {0, 1, 4, 9};

	while(true)
	{
		std::cout << "Enter a single digit integer, or -1 to quit: ";
		int input{};
		std::cin >> input;

		if (input == -1) break;

		bool in{ false };
		for (const auto& i : perfectSquaresArray)
			if (input == i) in = true;

		if (in) std::cout << input << " is a perfect square.\n";

		else std::cout << input << " is not a perfect square.\n";
	}

	std::cout << "Bye.\n";

	return 0;
}

