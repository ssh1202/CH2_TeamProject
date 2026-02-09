#include "Character/Player.h"
#include "Character/Monster.h"
#include <Windows.h>

void WaitForPlayerInput()
{
    system("pause");
    std::cout << std::endl;
}

int main()
{
    ACharacter* Player = new APlayer("나의 용사", {120, 15, 20, 10, 10});
    ACharacter* Monster = new AMonster("무서운 오크", {70, 10, 20, 5, 5});

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->PlayTurn(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }
        //여기까지 플레이어 턴
        WaitForPlayerInput();

        Monster->PlayTurn(Player);


        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }
        WaitForPlayerInput();
        //여기까지 몬스터 턴
    }

    delete Player;
    delete Monster;
    return 0;
}