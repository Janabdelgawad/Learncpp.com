#include <iostream>
struct IntPair
{
	int num1{};
	int num2{};
	void print()
	{
		std::cout << "Pair(" << num1 << ", " << num2 << ")\n";
	}
	bool isEqual(IntPair khara)
	{
		return (num1 == khara.num1) && (num2 == khara.num2);
	}
};

// indicating whether one IntPair is equal to another.
int main()
{
	IntPair p1{ 1, 2 };
	IntPair p2{ 3, 4 };

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
