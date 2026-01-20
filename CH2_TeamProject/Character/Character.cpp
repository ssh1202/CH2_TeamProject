#include "Character.h"
#include "Monster.h"
#include <iostream>
#include <string>

ACharacter::ACharacter()
{

    Name = "Unkown";

    Hp = 10;

    Atk = 10;

    std::cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << std::endl;
}

ACharacter::ACharacter(std::string NewName, int NewHp, int NewAtk)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;

    std::cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    std::cout << "ACharacter 소멸됨" << std::endl;
}


void ACharacter::Attack(ACharacter* Target)
{

    std::cout << Name << "가 공격합니다! (공격력" << Atk << ")" << std::endl;

    Target->TakeDamage(Atk);

}

void ACharacter::TakeDamage(int DamageAmount)
{

    Hp -= DamageAmount;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}

int ACharacter::GetHp()
{
    return Hp;
}

bool ACharacter::IsDead()
{
    if (Hp <= 0)
    {
        return true;
    }
    else return false;
}