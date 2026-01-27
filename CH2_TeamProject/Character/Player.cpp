#include "Player.h"
#include "Character.h"


APlayer::APlayer(const std::string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

bool APlayer::UseItem()
{

}

void APlayer::LevelUp()
{

}
