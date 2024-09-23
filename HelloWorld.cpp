#include <iostream>
//Define an enumerated type named MonsterType 
// to choose between the following monster races: orc, goblin, troll, ogre, and skeleton.
//Put the MonsterType enumeration inside a namespace. 
// Then, create a main() function and instantiate a troll. The program should compile.
namespace Monster
{
	enum MonsterType
	{
		orc, goblin, troll, ogre, skeleton,
	};
}

int main()
{
	std::cout << "Choose between the following monster races: orc, goblin, troll, ogre, and skeleton\n";
	std::string input{""};
	std::cin >> input;
	std::cout << "You chose the monster: " + input + '\n';
	Monster::MonsterType monster{ Monster::troll };
	return 0;
}