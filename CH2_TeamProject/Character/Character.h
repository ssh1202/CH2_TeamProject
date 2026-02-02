#pragma once
#include <iostream>
#include <string>

using namespace std;

class ACharacter;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;
	int Atk;
	int Def;
	int Critical;

	int Hp = 0;
	int Mp = 0;
	
	FUnitStat()
	{
	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;

		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
		
	}
};

struct FDamageResult
{
	int Damage;
	bool bCritical;

	ACharacter* Attacker;
	ACharacter* Target;

	void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	virtual FDamageResult Attack(ACharacter* Target);
	virtual void UseSkill(ACharacter* Target) = 0;
	int TakeDamage(int DamageAmount);

	void PrintName();

	int GetMaxHp() const { return Stat.MaxHp; }
	int GetHp() { return Stat.Hp; }
	string GetName() { return Name; }
	bool IsDead() { return Stat.Hp <= 0; }
	
private:
	int GetRandomInt();
};
