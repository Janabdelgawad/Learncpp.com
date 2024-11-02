#include <iostream>
void binaryRepresentation(int i)
{
	if (i == 0) return;
	//recurse to next bit
	binaryRepresentation(i / 2);
	//print in reverse
	std::cout << i % 2;
}

int main()
{
	std::cout << "Enter a positive integer: ";
	int input{};
	std::cin >> input;

	binaryRepresentation(input);
	return 0;
}
