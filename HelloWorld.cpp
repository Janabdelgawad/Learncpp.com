#include <iostream>
#include <vector>
#include <cassert>
namespace Animals
{
	enum Animals
	{
		chicken, dog, cat, elephant, duck, snake, maxAnimals,
	};
	const std::vector legs{ 2, 4, 4, 4, 2, 0 };
}

int main()
{
	assert(std::size(Animals::legs) == Animals::maxAnimals);

	std::cout << " An elephant has " << Animals::legs[Animals::elephant] << " legs.\n";
	std::cout << "khara";
	return 0;
}