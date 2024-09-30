#include <iostream>

template<typename T, typename U>
	struct Pair 
	{
		T num1{};
		U num2{};
	};

	struct Point
	{
		int num1{};
		int num2{};
	};

template<typename T>
void max(T num)
{
	std::cout << ((num.num1 < num.num2) ? num.num2 : num.num1);
}

int main()
{
	Pair<double, int> x1{ 1.3,2 };
	max(x1);

	std::cout << '\n';

	Point x2{ 3,4 };
	max(x2);

	std::cout << '\n';
	return 0;
}