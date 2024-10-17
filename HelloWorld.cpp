#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string_view> arr{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

	std::cout << "Enter a name: ";
	std::string input{};
	std::cin >> input;

	bool static exists{ false };
	for (std::string_view element : arr)
	{
		if (element == input)
		{
			exists = true;
			break;
		}
	}

	if (exists) std::cout << input << " was found.\n";
	else std::cout << input << " was not found.\n";

	return 0;
}
