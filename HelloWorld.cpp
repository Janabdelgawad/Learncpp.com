//Repeat quiz #1, but this time the function should print the string backwards.

/*
2 copies of pointers to strings 
1st pointer(main) stays the same at index 0
2nd pointer(ptr) moves until it reaches the end of the string "null terminator"
now 2nd pointer reached the end make it wake backward until it reaches main pointer
*/

#include <iostream>
//pointer to first char of string words
void print(const char words[])
{
	const char* ptr{ words };

	while (*ptr != '\0') ++ptr;

	while (ptr-- != words)
	{
		//dereference and print the value
		std::cout << *ptr << ' ';
	}
}

int main()
{
	const char cString[] {"Hello, world!"};
	print(cString);
	std::cout << '\n';
	return 0;
}

