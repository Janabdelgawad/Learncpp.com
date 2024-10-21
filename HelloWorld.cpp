#include <iostream>
#include <array>

int main()
{
	std::array<double, 365> a{};
	constexpr std::array<char, 5> hello{ 'h', 'e', 'l', 'l', 'o' };
	std::cout << hello[1] << '\n';
	return 0;
}