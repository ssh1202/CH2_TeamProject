#pragma once
#include <iostream>
#include "Character.h"

class ABattleManager
{
public:
	ABattleManager();
	~ABattleManager();
	
	void WaitForPlayerInput();
	bool BattleTurn(ACharacter* Attacker, ACharacter* Defender);
	void RunBattle(ACharacter* Player, ACharacter* Monster);
};

