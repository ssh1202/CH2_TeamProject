#include "Player.h"
#include "Character.h"


APlayer::APlayer(const std::string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);

	string AttackMessage = "이(가) 검으로 베었다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 검으로 힘껏 베었다!";
	}
	
	result.PrintMessage(AttackMessage);

	return result;
}

void APlayer::UseSkill(ACharacter* Target)
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

	int Damage = Stat.Atk * 2;

	int SkillDamage = Target->TakeDamage(Damage);

	string SkillMessage = "이(가) 엄청난 힘을 사용했다!";
	result.Damage = SkillDamage;
	
	result.PrintMessage(SkillMessage);
}

/*bool APlayer::UseItem()
{

}

void APlayer::LevelUp()
{

}*/