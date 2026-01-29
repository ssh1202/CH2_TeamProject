#include "Monster.h"

AMonster::AMonster(const string& MonsterName, const FUnitStat& MonsterStat)
	: ACharacter(MonsterName, MonsterStat)
{
}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);

	string AttackMessage = "이(가) 주먹을 휘둘렀다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 힘껏 주먹을 휘둘렀다!";
	}

	std::cout << " '크아앙!' " << Name << AttackMessage << std::endl;
	std::cout << Target->GetName() << " HP : " << Target->GetHp() << std::endl;

	return result;
}
