/*
Use a pointer and pointer arithmetic
to step through each character of the string
and print that character.
*/
#include <iostream>
void print(const char* words)
{
	const char* begin{ words };
	const char* end{words + std::strlen(words) };

	for (;begin != end;++begin)
	{
		std::cout << *begin << ' ';
	}
}

int main()
{
	const char cString[] {"Hello, world!"};
	print(cString);
	return 0;
}

