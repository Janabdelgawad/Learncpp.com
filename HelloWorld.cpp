#include <iostream>
#include <array>
struct Item
{
	std::string_view name{};
	int gold{ 0 };
};

template <std::size_t N>
void printStore(const std::array<Item, N>& arr)
{
	for (const auto& i : arr)
	{
		std::cout << "A " << i.name << " costs " << i.gold << " gold.\n";
	}
}
int main()
{
	constexpr std::array arr 
	{
		Item {"sword", 5},
		Item {"dagger", 3},
		Item {"club", 2},
		Item {"spear", 7}
	};
	printStore(arr);
	return 0;
}
