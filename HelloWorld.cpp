/*
Numbers divisible by only 3 should print “fizz”.
Numbers divisible by only 5 should print “buzz”.
Numbers divisible by only 7 should print “pop”.
Numbers divisible by only 11 should print “bang”.
Numbers divisible by only 13 should print “jazz”.
Numbers divisible by only 17 should print “pow”.
Numbers divisible by only 19 should print “boom”.
Numbers divisible by more than one of the above should print each of the words associated with its divisors.
Numbers not divisible by any of the above should just print the number.
*/
#include <iostream>
#include <vector>
#include <cassert>

void fizzBuzz(int count)
{
	static const std::vector divisors{ 3, 5, 7, 9, 11, 13, 17, 19 };
	static const std::vector<std::string_view> words{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

	assert(std::size(divisors) == std::size(words) && "fizzbuzz: array sizes don't match");

	for (int i{ 1 }; i <= count; ++i)
	{
		bool printed{ false };

		for (std::size_t j{ 0 }; j < divisors.size(); ++j)
		{
			if (i % divisors[j])
			{
				std::cout << words[j];
				printed = true;
			}
		}
		if (!printed) std::cout << i;

		std::cout << '\n';
	}
}
int main()
{

	fizzBuzz(150);
	return 0;
}
