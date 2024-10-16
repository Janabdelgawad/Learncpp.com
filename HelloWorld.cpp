#include <vector>
#include <iostream>
int main()
{
	//Q1
	std::vector<int> v1{1, 4, 9, 16, 25};
	//Q2 difference between v{2} and v(2), first element's value intialized with 2 and a vector with 2 elements zero initialized
	//Q3
	std::vector<double> v2(365);

	//Q4
	std::cout << "Enter 3 integers: ";
	std::vector<int> input(3);
	std::cin >> input[0] >> input[1] >> input[2];

	std::cout << "The sum is: " << input[0] + input[1] + input[2] << '\n';
	std::cout << "The product is: " << input[0] * input[1] * input[2] << '\n';
	return 0;
}