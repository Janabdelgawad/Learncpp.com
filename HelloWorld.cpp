#include <cstdint>
#include <iostream>
class Average
{
private:
	std::int32_t m_total{ 0 };
	int			 m_numbers{ 0 };
public:
	Average(){}
	friend std::ostream& operator<<(std::ostream& out, const Average& avg);
	Average& operator+=(std::int32_t num)
	{
		m_total += num;
		++m_numbers;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	if (avg.m_numbers == 0)
	{
		out << 0;
		return out;
	}
	out << static_cast<double>(avg.m_total)/avg.m_numbers;
	return out;
}

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}