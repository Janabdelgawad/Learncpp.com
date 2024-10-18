#include <iostream>
#include <vector>
#include <string_view>
//Write definitions for the following. Use CTAD where possible
//
int main()
{
	std::vector<int> even6{ 2, 4, 6, 8, 10, 12 };
	const std::vector<double> doubles{ 1.2, 3.4, 5.6, 7.8 };
	using namespace std::literals::string_view_literals;
	const std::vector names{"Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv};
	std::vector value{ 12 };
	std::vector<int> values(12);
	return 0;
}