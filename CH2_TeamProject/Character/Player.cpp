#include "Player.h"
#include "Character.h"


APlayer::APlayer(const std::string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

/*bool APlayer::UseItem()
{

}

void APlayer::LevelUp()
{

}*/


void APlayer::Attack(ACharacter* Target)
{
	ACharacter::Attack(Target);
	std::cout << Name << "가 공격합니다!" << std::endl;
}