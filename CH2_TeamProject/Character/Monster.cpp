#include "Monster.h"

AMonster::AMonster(const string& MonsterName, const FUnitStat& MonsterStat)
	: ACharacter(MonsterName, MonsterStat)
{
	std::cout << "AMonster 생성됨 : " << Name << "(HP: " << Stat.Hp << ")" << std::endl;
}

void AMonster::Attack(ACharacter* Target)
{
	std::cout << " '크아앙!' " << Name << "이(가) 이빨로 물어뜯습니다!" << std:: endl;

	Target->TakeDamage(Stat.Atk);
}
