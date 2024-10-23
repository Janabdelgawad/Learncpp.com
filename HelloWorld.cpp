#include <iostream>
//pointer to first char of string words
void print(const char words[])
{
	//as long as pointer doesnt point to a null terminator
	while (*words != '\0')
	{
		//dereference and print the value
		std::cout << *words << ' ';
		//increment the pointer to point to the next char in line
		++words;
	}

}

int main()
{
	const char cString[] {"Hello, world!"};
	print(cString);
	return 0;
}

