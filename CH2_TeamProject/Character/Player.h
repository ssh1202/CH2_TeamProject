#pragma once
#include "Character.h"
class APlayer : public ACharacter
{
private:
	int Level;
	int Exp;
	//멤버 변수: Level, Exp
	//멤버 함수: UseItem(), LevelUp() - 빈 구현으로...
	
public:
	APlayer(const std::string& NewName, const FUnitStat& NewStat, int NewLevel, int Exp);

	bool UseItem();

	void LevelUp();
};

