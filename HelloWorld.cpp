/*
design:
goal 
requirements/problems
tools/target/backup
hierarchy
??

Implementation:
main
other functions
testing
*/

#include <iostream>

//get(and return) a single integer from the user.
int readNumber()
{	
	std::cout << "Enter a number: ";
	int input{};
	std::cin >> input;
	return input;
}

//output the answer.take a single parameter and have no return value.
void writeAnswer(int answer)
{
	std::cout << "The sum is: " << answer << "\n";
}

//A main() function should be used to glue the above functions together.
int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	int sum = x + y;
	writeAnswer(sum);
	
	return 0;
}

