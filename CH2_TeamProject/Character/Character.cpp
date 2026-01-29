#include "Character.h"
#include "Monster.h"
#include <random>
#include <iostream>
#include <string>

int ACharacter::GetRandomInt()
{
    static random_device rd;
    static mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);
    return dis(gen);
}

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
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
    int Damage = Stat.Atk;
    
    int Random = GetRandomInt();
    if (Random < Stat.Critical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }
    Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount -= Stat.Def;
    DamageAmount = max(DamageAmount, 0);
    
    Stat.Hp -= DamageAmount;
    cout << Name << "가" << DamageAmount << "피해를 입었습니다." << endl;
}

