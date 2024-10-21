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
//not explicitly specify the element type for each initializer.
int main()
{
	constexpr std::array<Item, 4> arr 
	{ {
		{"sword", 5},
		{"dagger", 3},
		{"club", 2},
		{"spear", 7}
	} };
	printStore(arr);
	return 0;
}
