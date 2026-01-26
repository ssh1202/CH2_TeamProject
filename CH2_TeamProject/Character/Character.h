#pragma once
#include <iostream>
#include <string>

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
};

class ACharacter
{
public:
    ACharacter();
    ACharacter(const std::string& NewName, const FUnitStat& NewStat);
    ~ACharacter();

protected:
    std::string Name;
    FUnitStat Stat;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);

    int GetHp()
    {
        return Stat.Hp;
    }
    bool IsDead()
    {
        return Stat.Hp <= 0;
    }
};