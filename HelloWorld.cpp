#include <iostream>
int userInput()
{
	std::cout << "Enter an integer between 0 & 9: ";
	int input{};
	std::cin >> input;
	return input;
}

int isPrime(int x)
{
    if (x == 2) 
        return true;
    else if (x == 3) 
        return true;
    else if (x == 5) 
        return true;
    else if (x == 7) 
        return true;

    return false; 
}

int main()
{
	int x{ userInput() };
    int y{ isPrime(x) };
    if (y)
    {
        std::cout << "prime.\n";
    }
    else
    {
        std::cout << "not prime.";
    }
	return 0;
}