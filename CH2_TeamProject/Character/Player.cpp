#include "Player.h"
#include "Character.h"
Player::Player()
{
}

Player::Player(std::string NewName, int NewHp, int NewAtk) 
	: ACharacter(NewName, NewHp, NewAtk)
{

}

Player::~Player()
{
}
