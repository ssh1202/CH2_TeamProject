#include "Player.h"
#include "Character.h"


APlayer::APlayer()
{
}

APlayer::APlayer(const std::string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName,NewStat)
{

}

APlayer::~APlayer()
{
}
