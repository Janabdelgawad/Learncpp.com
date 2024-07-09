#include <iostream>


/* Question 4 char x supposed to be int x 

int readNumber()
{
	std::cout << "Please enter a number: ";
	int x{};
	std::cin >> x;

	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	writeAnswer(x + y);

	return 0;
}
*/









/* Question 3, the call stack when running the cursor at line 4 is: d b a main
void d()
{ // here
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}
*/








/* Question 2
int readNumber()
{
	std::cout << "Please enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The quotient is: " << x << '\n';
}

int main()
{
	int x{ };
	int y{ };
	x = readNumber();
	y = readNumber();
	writeAnswer(x / y);

	return 0;
}
*/




/*	Question 1
int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x{};
	x = readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}
*/