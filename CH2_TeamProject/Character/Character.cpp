#include "Character.h"
#include <iostream>
#include <string>

ACharacter::ACharacter()
{

    Name = "Unkown";

    Hp = 10;

    Atk = 10;

    std::cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << std::endl;
}

ACharacter::~ACharacter()
{
    std::cout << "ACharacter 소멸됨" << std::endl;
}


void ACharacter::Attack()
{

    std::cout << Name << "가 공격합니다! (공격력" << Atk << ")" << std::endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{

    Hp -= DamageAmount;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
}