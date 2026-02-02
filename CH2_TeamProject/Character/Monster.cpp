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

	result.PrintMessage(AttackMessage);

	return result;
}


void AMonster::UseSkill(ACharacter* Target)
{

	if (Stat.Mp < 10)
	{
		std::cout << "MP가 부족합니다!" << std::endl;
		return;
	}
	Stat.Mp -= 10;

	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.bCritical = false;

	int Damage = Stat.Atk;
	Stat.Hp = min(Stat.Hp + Damage , Stat.MaxHp);

	int SkillDamage = Target->TakeDamage(Damage);
	result.Damage = SkillDamage;

	string SkillMessage = "이(가) 흡혈을 사용했다! ";
	result.PrintMessage(SkillMessage);
}
