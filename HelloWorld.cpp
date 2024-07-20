/*
function vs member functions
length(name) vs   name.length()
member function means that it is part of a library(std::string)

when using std::string when receiving input 
use std::getline(std::cin >> std::ws, "your string here");
ws-> ignores white spaces 
getline -> read a full line of input (not just the first thing like what std::cin does alone)
constexpr cant use std::string in versions < ++20/23
don't pass strings by value use std::stringview

*/

#include <iostream>
#include <string>

int main()
{
	//get input(user's name)
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name); //read a full line of text into name

	//count user's name length
	int castedNameLength{static_cast<int>(name.length())}; //name.length() is unsigned, convert it to a signed value

	//get input(user's age)
	std::cout << "Enter your age: ";
	int age{}; // is signed
	std::cin >> age;

	//output(user's name length & age)
	std::cout << "Your age + length of name is: " << castedNameLength + age << '\n';

	return 0;
}