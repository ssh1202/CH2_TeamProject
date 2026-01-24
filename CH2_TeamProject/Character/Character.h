#pragma once
#include <iostream>
#include <string>

using namespace std;

class ACharacter
{
public:
    ACharacter();
    ACharacter(std::string NewName, int NewHp, int NewAtk, int NewDef, int NewCri);
    ~ACharacter();

protected:
    std::string Name;
    int Hp;
    int Atk;
    int Def;
    int Critical;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);

    //간단한 getter는 헤더에서 구현을 권장합니다.
    int GetHp();
    bool IsDead();
};