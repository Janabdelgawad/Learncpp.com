#include <iostream>
#include <vector>
#include <type_traits> 
#include <cassert>
namespace Item
{
	enum ItemTypes: int
	{
		healthPotions, torches, arrows, maxCount

	};
}

std::string_view getItemNamePlural(Item::ItemTypes type)
{
	switch (type)
	{
	case Item::healthPotions: return "health potions";
	case Item::torches: return "torches";
	case Item::arrows: return "arrows";
	default: return "???";
	}
}

std::string_view getItemNameSingular(Item::ItemTypes type)
{
	switch (type)
	{
	case Item::healthPotions: return "health potion";
	case Item::torches: return "torch";
	case Item::arrows: return "arrow";
	default: return "???";
	}
}

template <typename T>
constexpr std::size_t toUZ(T value)
{
	// make sure T is an integral type
	static_assert(std::is_integral<T>() || std::is_enum<T>());

	return static_cast<std::size_t>(value);
}

void print(const std::vector<int>& inventory, Item::ItemTypes type)
{
		bool plural{ inventory[toUZ(type)] != 1 };
		std::cout << "You have " << inventory[toUZ(type)] << ' ';
		std::cout << (plural ? getItemNamePlural(type) : getItemNameSingular(type)) << '\n';
}

int totalCount(const std::vector<int>& inventory)
{
	int sum{ 0 };
	for (auto e : inventory)
		sum += e;
	return sum;
}

int main()
{
	std::vector inventory{ 1, 5, 10 };
	assert(std::size(inventory) == Item::maxCount);

	for (int i{ 0 }; i < Item::maxCount; ++i)
	{
		auto item{ static_cast<Item::ItemTypes>(i) };
		print(inventory, item);
	}
	std::cout << "You have " << totalCount(inventory) << " total items\n";
	return 0;
}