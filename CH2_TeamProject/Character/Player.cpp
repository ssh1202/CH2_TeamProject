#include "Player.h"
#include "Character.h"
Player::Player()
{
}

Player::Player(std::string NewName, int NewHp, int NewAtk, int NewDef, int NewCri) 
	: ACharacter(NewName, NewHp, NewAtk, NewDef, NewCri)
{

}

Player::~Player()
{
}
