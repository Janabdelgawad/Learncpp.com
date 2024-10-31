#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::cout << "How many names would you like to enter: ";
	std::size_t num{};
	std::cin >> num;

	auto* names{ new std::string[num]{} };

	for (std::size_t i{0}; i < num; ++i)
	{
		std::cout << "Enter name #" << i + 1 << ": ";
		std::getline(std::cin >> std::ws, names[i]);
	}

	std::sort(names, names + num);

	std::cout << "\nHere is your sorted list: \n";

	for (std::size_t i{ 0 }; i < num; ++i)
		std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';

	delete[] names;
	return 0;
}