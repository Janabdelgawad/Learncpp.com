/*
Write a program that asks for the name and age of two people, then prints which person is older.

Here is the sample output from one run of the program :

Enter the name of person #1: John Bacon
Enter the age of John Bacon : 37
Enter the name of person #2: David Jenkins
Enter the age of David Jenkins : 44
David Jenkins(age 44) is older than John Bacon(age 37).
*/

#include <iostream>
#include <string>
#include <string_view>

//string not string_view because we are receiving input and need to store it
std::string userName(int userNumber)
{
	std::cout << "Enter the name of person #" << userNumber << ": ";
	std::string name{};
	//getline accepts multiple texts, std::ws ignores white spaces 
	std::getline(std::cin >> std::ws, name);
	return name;
}

//string_view was used to output the name only (for read-only purposes)
int userAge(std::string_view name)
{
	std::cout << "Enter the age of " << name << " : ";
	int age{};
	std::cin >> age;
	return age;
}

void printOlderUser(std::string_view name1, int age1, std::string_view name2, int age2)
{
	//conditional operator "?:" used because they're only 2 statements
	int older{0};
	(age1 > age2) ? older = age1: older = age2;

	//used if-else instead to print because ?: didn't work with std::cout (don't know why)
	if (older == age1)
		std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ").\n";
	else
		std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ").\n";
}

int main()
{
	//const to prevent them from changing later

	//store first user's name and age 
	const std::string user1{ userName(1) };
	const int user1Age{ userAge(user1) };

	//store second user's name and age
	const std::string user2{ userName(2) };
	const int user2Age{ userAge(user2) };

	//print which user is older
	printOlderUser(user1, user1Age, user2, user2Age);
	return 0;
}