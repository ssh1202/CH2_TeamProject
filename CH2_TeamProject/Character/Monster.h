#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
	AMonster(const string& MonsterName, const FUnitStat& MonsterStat);

	void Attack(ACharacter* Target) override;
};

