/*
Variable's
----------
Scope: where the variable is seen/used in code
Duration: the rules that govern when a variable is created&destroyed
Lifetime: the time between creation&destruction


The program output should match the following:
Enter an integer: 4
Enter a larger integer: 2
Swapping the values
The smaller value is 2
The larger value is 4
*/
#include <iostream>
int main()
{
	//larger and smaller are created
	std::cout << "Enter an integer: ";
	int smaller{};
	std::cin >> smaller;
	std::cout << "Enter a larger integer: ";
	int larger{};
	std::cin >> larger;

	//if wrong order was entered
	if (larger < smaller)
	{
		std::cout << "Swapping the values\n";

		//temp created
		int temp{ smaller };
		smaller = larger;
		larger = temp;
	}	//temp destroyed

	std::cout << "The smaller value is: " << smaller << '\n';
	std::cout << "The larger value is: " << larger << '\n';

	return 0;
}	//larger and smaller are destroyed