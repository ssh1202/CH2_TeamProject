#include "BattleManager.h"

ABattleManager::ABattleManager()
{
}

ABattleManager::~ABattleManager()
{
}

void ABattleManager::WaitForPlayerInput()
{
	system("pause");
	std::cout << std::endl;
}

bool ABattleManager::BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
	Attacker->PlayTurn(Defender);

	Attacker->ShowStat();
	Defender->ShowStat();

	WaitForPlayerInput();

	if (Defender->IsDead())
	{
		cout << Defender->GetName() << " 가 쓰러졌습니다!" << endl;
	}
	return Defender->IsDead();
}

void ABattleManager::RunBattle(ACharacter* Player, ACharacter* Monster)
{
	cout << "===  데스매치 시작!  ===" << endl;
	WaitForPlayerInput();

	while (true)
	{
		if (BattleTurn(Player, Monster) == true)
		{
			break;
		}

		if (BattleTurn(Monster, Player) == true)
		{
			break;
		}
	}
	cout << "===  데스매치 종료!  ===" << endl;
}