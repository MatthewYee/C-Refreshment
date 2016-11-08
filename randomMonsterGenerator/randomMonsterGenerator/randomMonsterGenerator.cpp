// randomMonsterGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Monster 
{
public:									// 3c Don't Forget you can change the order of the class
	enum MonsterType					// 3a enumeration of monster type
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};	
private:										// Remember that order plays a role in the program. When you have private members after public function the program got confuse and utilize other variables.
	MonsterType m_monsterType;
	string m_name;
	string m_roar;
	int m_hitPoints;

public:
	Monster(MonsterType monster, string name, string roar, int hitpoints)					// 3d constructor 
		: m_monsterType(monster), m_name(name), m_roar(roar), m_hitPoints(hitpoints)
	{
			// initialize so no need 
	}

	string getTypeString()
	{
		switch (m_monsterType)
		{
		case Dragon: return "dragon";
		case Goblin: return "goblin";
		case Ogre: return "ogre";
		case Orc: return "orc";
		case Skeleton: return "skeleton";
		case Troll: return "troll";
		case Vampire: return "vampire";
		case Zombie: return "zombie";
		}

		return "???";
	}

	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}
	friend class MonsterGenerator;
};

class MonsterGenerator
{
public:

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)									 // 3g make use of a static function 
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		int hitPoints = getRandomNumber(1, 100);

		static string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

		return Monster(type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hitPoints);
	}
};


int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();
    return 0;
}

