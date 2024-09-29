#include <iostream>
struct Revenue
{
	int ads{};
	double clicksPercentage{}; 
	double earnings{};
};

void printRevenue(const Revenue rev)
{
	std::cout << "Ads:   " << rev.ads << '\n';
	std::cout << "Clicks percentage:  " << rev.clicksPercentage << '\n';
	std::cout << "Earnings: " << rev.earnings << '\n';
	double totalEarnings{rev.ads * (rev.clicksPercentage / 100) * rev.earnings };
	std::cout << "Total earnings: " << totalEarnings << '\n';
}

int main()
{
	printRevenue(Revenue{ 10, 20.3, 10000 });
	return 0;
}