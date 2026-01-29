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

	std::cout << Name << AttackMessage << " ( 데미지 : "<< result.Damage << " ) "<< std::endl;
	std::cout << Target->GetName() << " HP : " << Target->GetHp() << std::endl;

	return result;
}

/*bool APlayer::UseItem()
{

}

void APlayer::LevelUp()
{

}*/