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

ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
    Name = NewName;
    Stat = UnitStat;

    Stat.Hp = Stat.MaxHp;
    Stat.Mp = Stat.MaxMp;


    std::cout << "ACharacter 생성됨 : " << Name << "(HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    std::cout << "ACharacter 소멸됨" << std::endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{

    int Damage = Stat.Atk;
    bool bCritical = GetRandomInt() < Stat.Critical;

    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }
    
    int FinalDamage = Target->TakeDamage(Damage);

    FDamageResult result;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;

    return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount = DamageAmount - Stat.Def;
    DamageAmount = max(DamageAmount, 0);

    Stat.Hp -= DamageAmount;
    Stat.Hp = max(Stat.Hp, 0);

    return DamageAmount;
}

