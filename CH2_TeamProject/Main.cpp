#include "Character/Player.h"
#include "Character/Monster.h"
#include "Character/BattleManager.h"\
#include <memory>
#include <Windows.h>

int main()
{
	unique_ptr<ACharacter> Player = make_unique<APlayer>("나의 용사", FUnitStat { 120, 20, 20, 10, 10 });
	unique_ptr<ACharacter> Monster = make_unique<AMonster>("무서운 오크", FUnitStat { 150, 20, 23, 5, 5 });
	
	auto Manager = make_unique<ABattleManager>();

	Manager->RunBattle(Player.get(), Monster.get());
	Manager->WaitForPlayerInput();

	return 0;
}