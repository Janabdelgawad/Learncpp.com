#include <iostream>
#include <string>
#include <algorithm>
/*

void mySol(int& x, int& y)
{
	(x <= y) ? x : y;
	if(x) std::swap(x, y);
}
void sort2(int& x, int& y)
{
	if (x <= y) return;
	std::swap(x, y);
}

int main()
{
	int x{ 7 };
	int y{ 5 };

	std::cout << x << ' ' << y << '\n'; // should print 7 5

	sort2(x, y); // make sure sort works when values need to be swapped
	std::cout << x << ' ' << y << '\n'; // should print 5 7

	sort2(x, y); // make sure sort works when values don't need to be swapped
	std::cout << x << ' ' << y << '\n'; // should print 5 7

	return 0;
}





/*
void printByAddress(const std::string* ptr)
{
	std::cout << *ptr << '\n';
}
int main()
{
	std::string str{ "Hello World!" };
	printByAddress(&str);

	std::string* ptr { &str };
	printByAddress(ptr);
	std::string* ptr{ &str };
	return 0;
}


/*
int main()
{
	int x{ 5 };
	int* ptr{ &x };

	if (ptr == nullptr) std::cout << "ptr is null\n";
	else std::cout << "ptr is non-null\n";

	int* nullPtr{};
	std::cout << "nullPtr is: " << (nullPtr == nullptr ? "nullPtr is null" : "nullPtr is non-null");

	return 0;
}

int main()
{
	int x{ 5 };
	std::cout << x << '\n';

	int* ptr{ &x };
	std::cout << *ptr << '\n';
	return 0;
}

template<typename T>
T add(T x, T y)
{
	return x + y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
	return 0;
}
--------------------------
template <typename T>
T mult(T x, int y)
{
	return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}

template<typename T, typename U>
auto sub(T x, U y)
{
	return x - y;
}
int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
*/