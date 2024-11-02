#include <iostream>
/* 
(e.g. 357 = 3 + 5 + 7 = 15).
*/
int Sum(int input)
{
	if (input < 10)
		return input;
	return Sum(input/10) + input%10;
}
int main()
{
	std::cout << Sum(93427) << '\n';
	return 0;
}
