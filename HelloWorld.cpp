#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include "Random.h"
#include <cassert>
class Creature
{
protected:
	std::string m_name;
	char        m_symbol;
	int         m_health;
	int         m_damage;
	int         m_gold;
public:
	Creature(std::string_view name, char symbol, int health, int damage, int gold) :
		m_name{name}, m_symbol{}, m_health{health}, m_damage{damage}, m_gold{gold} {}

	//access functions
	const std::string& getName()   const { return m_name; }
	char         getSymbol() const { return m_symbol; }
	int          getHealth() const { return m_health; }
	int          getDamage() const { return m_damage; }
	int          getGold()   const { return m_gold; }

	void reduceHealth(int health) {m_health -= health;}
	void addGold(int gold)        { m_gold += gold; }
	bool isDead() const           { return m_health <= 0; }
};


class Player : public Creature
{
	int m_level{ 1 };
public:
	Player(const std::string& name) :
		Creature{ name, '@', 10, 1, 0 }{}

	void levelUp()
	{
		++m_level;
		++m_damage;
	}
	int getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
	enum Type{dragon, orc, slime, max_types};
private:
	inline static Creature monsterData[]
	{
	Creature { "dragon", 'D', 20, 4, 100 },
	Creature { "orc", 'o', 4, 2, 25 },
	Creature { "slime", 's', 1, 1, 10 }
	};
	static_assert(std::size(monsterData) == max_types);
public:
	Monster(Type type) : Creature {monsterData[type]} {}
	static Monster getRandomMonster()
	{
		int randomMonster{ Random::get(0, max_types - 1) };
		return Monster{ static_cast<Type>(randomMonster) };
	}
};

void attackMonster(Player& player, Monster& monster)
{
	if (player.isDead()) return;

	std::cout << "You hit the " << monster.getName() << " for " 
		      << player.getDamage() << " damage.\n";

	monster.reduceHealth(player.getDamage());

	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

void attackPlayer(const Monster& monster, Player& player)
{
	if (monster.isDead()) return;
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

void fightMonster(Player& p)
{
	// First randomly generate a monster
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

	while (!monster.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char action{};
		std::cin >> action;

		if (action == 'r' || action == 'R')
		{
			//50% chance to flee
			if (Random::get(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // success ends the encounter
			}
			//failed to flee (1 free monster attack)
			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, p);
				continue;
			}
		}

		if (action == 'f' || action == 'F')
		{
			//player p attacks first
			attackMonster(p, monster);
			attackPlayer(monster, p);
		}
	}
}

int main()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player player{ playerName };
	std::cout << "Welcome, " << player.getName() << '\n';

	while (!player.isDead() && !player.hasWon())
		fightMonster(player);
	
	//player lost
	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() 
				  << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	//player won
	else
	{
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}