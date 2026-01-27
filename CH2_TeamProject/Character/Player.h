#pragma once
#include "Character.h"
class APlayer : public ACharacter
{
public:
	APlayer(const std::string& NewName, const FUnitStat& NewStat);
	
private:
	int Level;
	int Exp;

public:
	bool UseItem();
	void LevelUp();
};

