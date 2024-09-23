#include <iostream>

enum Color
{
	black, blue, pink, yellow,
};

constexpr std::string_view getColor(Color color)
{
	switch (color)
	{
		case black: return "black\n";
		case blue: return "blue\n";
		case pink: return "pink\n";
		case yellow: return "yellow\n";
		default: return "mesh mawgooooddd\n";
	}
}
int main()
{
	Color color{ pink };
	std::cout << getColor(pink);

	std::cout << "Enter a color: 0=black, 1=blue, 2=pink, 3=yellow\n";
	int input{};
	std::cin >> input;
	if (input < 0 || input > 3) std::cout << "Invalid number, pick from 0-3.\n";
	else
	{
		Color color2{ static_cast<Color>(input) };
		std::cout << getColor(color2);
	
	}
	return 0;
}