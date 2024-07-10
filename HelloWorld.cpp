#include <iostream>

int charAsInt(char ch)
{
	return ch;
}

int getInt(int ch)
{
	return ch;
}

int main()
{
	std::cout << "Enter a single character: ";
	char ch{};
	std::cin >> ch;
	std::cout << "You entered '" << ch << "', which has ASCII code " << static_cast<int>(ch) << ".\n";

	//implicit 1
	int implicit1{ ch };
	std::cout << "which has ASCII code " << implicit1 << ".\n";

	//implicit 2
	std::cout << "which has ASCII code " << charAsInt(ch) << ".\n";

	//implicit 3
	std::cout << "which has ASCII code " << getInt(ch) << ".\n";
	return 0;

}

/*
explicit type conversion (favored) using static_cast<type>(identifier)
implicit type conversion (unfavored) using:
1)new variable type int & store a char in it
2) a function to return the char variable as an int
3) a function that performs the conversion at the point where 
   the argument passes its value to the function parameter 
*/
