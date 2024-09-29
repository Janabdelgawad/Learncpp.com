#include <iostream>
struct Fraction
{
	int numerator{0};
	int denominator{1};
};
Fraction readFraction()
{
	Fraction f{};

	std::cout << "Enter a value for the numerator: ";
	std::cin >> f.numerator;

	std::cout << "Enter a value for the denominator: ";
	std::cin >> f.denominator;
	std::cout << '\n';

	return f;
}

constexpr Fraction multiplyFractions(const Fraction& frac1, const Fraction& frac2)
{
	return {frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator};
}

void printFractions(const Fraction& f)
{
	std::cout << f.numerator << '/' << f.denominator << '\n';
}

int main()
{
	Fraction fraction1{ readFraction() };
	Fraction fraction2{ readFraction() };

	std::cout << "Your fractions multiplied together: ";

	printFractions(multiplyFractions(fraction1, fraction2));

	return 0;
}