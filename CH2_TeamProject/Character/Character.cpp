#include "Character.h"
#include "Monster.h"
#include <random>
#include <iostream>
#include <string>

int getRandomInt()
{
    // �õ尪 ������ (�� ���� �ʱ�ȭ�ϱ� ���� static ����)
    static std::random_device rd;

    // �޸��� Ʈ������ ���� (��ǰ�� ���� ������)
    static std::mt19937 gen(rd());

    // 0���� 100���� �յ��ϰ� ���� (�� ���� ����)
    std::uniform_int_distribution<int> dis(0, 99);

    return dis(gen);
}

ACharacter::ACharacter()
{

    Name = "Unkown";

    Hp = 10;

    Atk = 10;

    std::cout << "ACharacter ������: " << Name << " (HP: " << Hp << ")" << std::endl;
}

ACharacter::ACharacter(std::string NewName, int NewHp, int NewAtk, int NewDef, int NewCri)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = NewCri;

    std::cout << "[����] " << Name << "�� ���忡 ��Ÿ�����ϴ�! (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    std::cout << "ACharacter �Ҹ���" << std::endl;
}


void ACharacter::Attack(ACharacter* Target)
{
    //�� �� ����


    int random = getRandomInt();

    if (random <= Critical)
    {
        //�̷��� ���ݷ��� �Ź� ȣ���Ҷ����� 1.5�� �þ�ϴٸ�...
        // = �� ����(���� ����) �ϴ°� �ƽ���?
        Target->TakeDamage(Atk *= 1.5f);
        std::cout << Name << "�� ũ��Ƽ�� �����մϴ�! (���ݷ�" << Atk << ")" << std::endl;
    }
    else
    {
        Target->TakeDamage(Atk);
        std::cout << Name << "�� �����մϴ�! (���ݷ�" << Atk << ")" << std::endl;
    }
    
        //������ ������, ũ��Ƽ�ð� �ƴѰ��� TakeDamage ���� ȣ���Ǵ°�, if else �ۿ��� ���ٷ� �ٲ㺾�ô�.
        Target->TakeDamage(Atk);
        std::cout << Name << "�� �����մϴ�! (���ݷ�" << Atk << ")" << std::endl;
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

    cout << Name << "�� " << DamageAmount << "�� ���ظ� �Ծ����ϴ�." << endl;
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
    }// else�� ������ �� �ֽ��ϴ�.
    else return false;
}