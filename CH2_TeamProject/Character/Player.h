#pragma once
#include "Character.h"
class APlayer : public ACharacter
{
public:
	APlayer();
	APlayer(const std::string& NewName, const FUnitStat& NewStat);
	~APlayer();

};

