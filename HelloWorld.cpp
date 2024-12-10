#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	int m_num{};
	int m_den{};
public:
	Fraction(int num = 0, int den = 1) 
		: m_num{num}, m_den{den} 
	{
		if (den == 0) throw std::runtime_error("Invalid denominator");
	}
	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_num << '/' << f1.m_den;
	return out;
}

int main()
{
	std::cout << "Enter the numerator: ";
	int num{};
	std::cin >> num;

	std::cout << "Enter the denominator: ";
	int den{};
	std::cin >> den;

	try
	{
		Fraction fraction{num, den};
		std::cout << "Your fraction is: " << fraction;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}