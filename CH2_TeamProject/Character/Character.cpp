#include "Character.h"
#include "Monster.h"
#include <random>
#include <iostream>
#include <string>

int getRandomInt()
{
    // 시드값 생성기 (한 번만 초기화하기 위해 static 사용)
    static std::random_device rd;

    // 메르센 트위스터 엔진 (고품질 난수 생성기)
    static std::mt19937 gen(rd());

    // 0부터 100까지 균등하게 분포 (양 끝값 포함)
    std::uniform_int_distribution<int> dis(0, 99);

    return dis(gen);
}

ACharacter::ACharacter()
{

    Name = "Unkown";

    Hp = 10;

    Atk = 10;

    std::cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << std::endl;
}

ACharacter::ACharacter(std::string NewName, int NewHp, int NewAtk, int NewDef, int NewCri)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = NewCri;

    std::cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    std::cout << "ACharacter 소멸됨" << std::endl;
}


void ACharacter::Attack(ACharacter* Target)
{
    //빈 줄 제거


    int random = getRandomInt();

    if (random <= Critical)
    {
        //이러면 공격력이 매번 호출할때마다 1.5배 늘어납니다만...
        // = 는 대입(값을 설정) 하는거 아시죠?
        Target->TakeDamage(Atk *= 1.5f);
        std::cout << Name << "가 크리티컬 공격합니다! (공격력" << Atk << ")" << std::endl;
    }
    else
    {
        //변수를 사용해, 크리티컬과 아닌경우 TakeDamage 각각 호출되는걸, if else 밖에서 한줄로 바꿔봅시다.
        Target->TakeDamage(Atk);
        std::cout << Name << "가 공격합니다! (공격력" << Atk << ")" << std::endl;
    }
}

void ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount -= Def;

    if (DamageAmount <= Def)
    {
        DamageAmount = 0;
    }
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
    }// else는 생략될 수 있습니다.
    else return false;
}