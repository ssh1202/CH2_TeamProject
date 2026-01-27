#include "Monster.h"

AMonster::AMonster(const string& MonsterName, const FUnitStat& MonsterStat)
	: ACharacter(MonsterName, MonsterStat)
{
	std::cout << "AMonster 생성됨 : " << Name << "(HP: " << Stat.Hp << ")" << std::endl;
}
