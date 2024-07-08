#include <iostream>

//get (and return) a single integer from the user.
int readNumber()
{
	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;
	return input;
}
//output the answer. 
//take a single parameter 
// and have no return value.
void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << "\n";
}

//glue the above functions together
int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	int sum = x + y;
	writeAnswer(sum);
	return 0;
}