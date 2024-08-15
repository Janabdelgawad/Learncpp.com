#include <iostream>

int main()
{
	int count{ 1 };
	while (count <= 50)
	{
		//add zero before numbers less than 10, ex: 01, 02, 03,...
		if (count < 10)
		{
			std::cout << '0';
		}

		//print a number and space each time
		std::cout << count << ' ';

		//new line after every 10 numbers
		if (count % 10 == 0)
		{
			std::cout << '\n';
		}

		//increase number
		count++;
	}
	return 0;
}