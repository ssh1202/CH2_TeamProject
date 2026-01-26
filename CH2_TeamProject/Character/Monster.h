#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
	AMonster();
	AMonster(std::string MonsterName, const FUnitStat& MonsterStat);
	~AMonster();

protected:
	std::string Name;
	FUnitStat Stat;

};

