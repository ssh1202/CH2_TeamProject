#include "Player.h"
#include "Character.h"

//level, exp 초기화가 생략되었습니다.
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
