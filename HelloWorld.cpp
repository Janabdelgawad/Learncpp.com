#include <iostream>
#include <vector>
#include <utility>
template <typename T>
std::pair<std::size_t, std::size_t> minMax(const std::vector<T>& arr)
{
	std::size_t min{ 0 };
	std::size_t max{ 0 };
	for (std::size_t i{ 0 }; i < arr.size(); ++i)
	{
		if (arr[i] < arr[min]) min = i;
		if (arr[i] > arr[max]) max = i;
	}
	return { min, max };
}

int main()
{
	std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
	std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

	auto m1{ minMax(v1) };
	std::cout << "The min element has index " << m1.first << " and the value " << v1[m1.first] << '\n';
	std::cout << "The max element has index " << m1.second << " and the value " << v1[m1.second] << "\n\n";

	auto m2{ minMax(v2) };
	std::cout << "The min element has index " << m2.first << " and value " << v2[m2.first] << '\n';
	std::cout << "The max element has index " << m2.second << " and value " << v2[m2.second] << '\n';
	return 0;
}