#include <iostream>
int factorial(int N)
{
	if (N <= 0) return 1;

	return factorial(N - 1) * N;
}
int main()
{
	for (int i{ 0 }; i < 7; ++i)
		std::cout << factorial(i) << '\n';
	return 0;
}
