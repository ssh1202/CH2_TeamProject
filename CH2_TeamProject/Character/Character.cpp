#include "Character.h"
#include "Monster.h"
#include <random>
#include <iostream>
#include <string>

int getRandomInt()
{
    static std::random_device rd;

    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, 99);

    return dis(gen);
}

ACharacter::ACharacter()
{
}

ACharacter::ACharacter(const std::string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    std::cout << "ACharacter 생성됨 : " << Name << "(HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    std::cout << "ACharacter 소멸됨" << std::endl;
}


void ACharacter::Attack(ACharacter* Target)
{
    int random = getRandomInt();

    if (random < Stat.Critical)
    {
        Target->TakeDamage(Stat.Atk * 1.5f);
        std::cout << Name << "가 크리티컬로 공격합니다!! (공격" << Stat.Atk << ")" << std::endl;
    }
    else
    {
        Target->TakeDamage(Stat.Atk);
        std::cout << Name << "가 공격합니다! (" << Stat.Atk << ")" << std::endl;
    }
}

void ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount -= Stat.Def;

    if (DamageAmount < 0)
    {
        DamageAmount = 0;
    }
    Stat.Hp -= DamageAmount;

    cout << Name << "가" << DamageAmount << "피해를 입었습니다." << endl;
}

