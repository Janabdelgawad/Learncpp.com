#include <iostream>
#include <iterator>
#include <utility>

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	
	for (int iteration{ 0 }; iteration < length-1; ++iteration)
	{
		int endOfArrayIndex{ length - iteration };
		bool swapped = false;

		for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex -1; ++currentIndex)
		{
			if (array[currentIndex] > array[currentIndex+1])
				std::swap(array[currentIndex], array[currentIndex+1]);
				swapped = true;
		}

		if (!swapped)
		{
			std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
			break;
		}
	}

	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

	return 0;
}