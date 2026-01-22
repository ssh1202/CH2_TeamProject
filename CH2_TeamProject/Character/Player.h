#pragma once
#include "Character.h"
class Player : public ACharacter
{
private:
	int Level;
	int Exp;
public:
	Player();
	Player(std::string NewName, int NewHp, int NewAtk,int NewDef, int NewCri);
	~Player();

};

