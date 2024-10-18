#include <iostream>
#include <vector>
#include <cassert>
namespace Item
{
	enum ItemTypes
	{
		healthPotions, torches, arrows, maxCount

	};
}
int totalCount(const std::vector<int>& inventory)
{
	int sum{ 0 };
	for (auto item : inventory)
		sum += item;
	return sum;
}
int main()
{
	std::vector inventory{ 1, 5, 10 };
	assert(std::size(inventory) == Item::maxCount);

	std::cout << "You have " << totalCount(inventory) << " total items.\n";
	return 0;
}