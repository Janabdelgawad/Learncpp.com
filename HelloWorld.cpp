#include <iostream>
//return passed char as an int
int charToInt(char x)
{
	return x;
}
//conversion happens when argument is copied to the called function's parameter
int charThroughIntToInt(int x)
{
	return x;
}
int main()
{
	char ch{ 'a' };
	std::cout << "NORMAL" << '\t' << "ASCII" << '\n';
	//didnt want to take input from user, had to check theyre the same value when outputted as expected
	std::cout << ch << '\t' << static_cast<int>(ch) << '\n';

	//implicit1
	int charToIntVariable{ ch };
	std::cout << ch << '\t' << charToIntVariable << '\n';

	//implicit2
	std::cout << ch << '\t' << charToInt(ch) << '\n';

	//implicit3 
	std::cout << ch << '\t' << charThroughIntToInt(ch) << '\n';
	return 0;
}