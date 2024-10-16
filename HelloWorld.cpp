#include <iostream>
#include <string>
#include <string_view>
#include "Random.h"
class Monster
{
public:
	enum Type
	{
		Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, Zombie,
		maxMonsterTypes,
	};

private:
	Type        m_monsterType{};
	std::string m_monsterName{ "???" };
	std::string m_monsterRoar{ "???" };
	int         m_hitPoints{};

public:
	Monster(Type monsterType, std::string_view monsterName, std::string_view monsterRoar, int hitPoints)
		: m_monsterType{ monsterType }, m_monsterName{ monsterName }, m_monsterRoar{ monsterRoar }, m_hitPoints{ hitPoints } {}

	constexpr std::string_view getTypeString() const
	{
		switch (m_monsterType)
		{
		case Dragon:   return "Dragon";
		case Goblin:   return "Goblin";
		case Ogre:	   return "Ogre";
		case Orc:      return "Orc";
		case Skeleton: return "Skeleton";
		case Troll:    return "Troll";
		case Vampire:  return "Vampire";
		case Zombie:   return "Zombie";
		default:       return "???";
		}
	}

	void print() const
	{
		std::cout << m_monsterName << " the " << getTypeString();

		if (m_hitPoints <= 0) std::cout << " is dead.\n";
		else
			std::cout << " has " << m_hitPoints << " hit points and says " << m_monsterRoar << '\n';
	}
};

namespace MonsterGenerator
{
	std::string_view getName(int n)
	{
		switch (n)
		{
		case 0:  return "Blarg";
		case 1:  return "Moog";
		case 2:  return "Pksh";
		case 3:  return "Tyrn";
		case 4:  return "Mort";
		case 5:  return "Hans";
		default: return "???";
		}
	}
	std::string_view getRoar(int n)
	{
		switch (n)
		{
		case 0:  return "*ROAR*";
		case 1:  return "*peep*";
		case 2:  return "*squeal*";
		case 3:  return "*whine*";
		case 4:  return "*growl*";
		case 5:  return "*burp*";
		default: return "???";
		}
	}

	Monster generate()
	{
		return
		{
			static_cast<Monster::Type>(Random::get(0,Monster::maxMonsterTypes - 1)),
			getName(Random::get(0,5)),
			getRoar(Random::get(0,5)),
			Random::get(1,100) };
	}
}
int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
