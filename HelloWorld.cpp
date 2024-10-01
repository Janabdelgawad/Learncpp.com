#include <iostream>
struct Monster
{
	enum Type
	{
		ogre, dragon, orc, giantSpider, slime,
	};
	Type type{};
	std::string name{};
	int health;
};

std::string readMonster(const Monster::Type m)
{
	switch (m)
	{
	case Monster::ogre:        return "Ogre";
	case Monster::dragon:      return "Dragon";
	case Monster::orc:         return "Orc";
	case Monster::giantSpider: return "Giant Spider";
	case Monster::slime:       return "Slime";
	default:                   return "???";
	}
}

void printMonster(const Monster m)
{

	std::cout << "This " << readMonster(m.type) << " is named " << m.name << " and has " << m.health << " health.\n";
}

int main()
{
	Monster m1{ Monster::ogre, "Torg", 145};
	Monster m2{ Monster::slime, "Blurp", 23};

	printMonster(m1);
	printMonster(m2);

	return 0;
}