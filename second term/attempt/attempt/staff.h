#pragma once
#include "pch.h"
#include <string>
#include "field.h"

class Unit: public onFieldObject {
public:
	static int s_id;

	Unit();	// ����������� �� ��������
	Unit(const char* pname, int health, int stamina); // ����������� � ����������� �� ���������
	Unit(const Unit &other); // ����������� �����������
	
	const char* Name() { return m_pname; };
	int Id() { return m_id;};
	int Health() { return nature.m_health;};
	int Stamina() { return nature.m_stamina;};
	int Damage() { return nature.m_damage; };
	
	friend class Artifact;
	friend class Elixir;
	friend class Toxin;

	~Unit();

private:
	struct Nature { // ��������� �����
		int m_health;
		int m_stamina;
		int m_damage;
		void setHealth(int health);
		void setStamina(int stamina);
		void setDamage(int damage);
	} nature;

	int m_id;
	const char* m_pname;
	
};


void sharePotion(Unit &unt, Artifact &what); // ������������� �������


class Artifact { // ����������� �����
public:
	virtual void apply(Unit &unt) = 0; //����������� �������
};

class Elixir : public Artifact, public onFieldObject
{
public:
	Elixir(int val = 30): m_value(val) {
		if (val > 100) m_value = 100;
		else if (val < 0) m_value = 0;
	};
	int Value() { return m_value; };
	virtual void apply(Unit &unt) {
		int sum_val = unt.nature.m_health + m_value;
		if (sum_val < 100) {
			unt.nature.m_health = sum_val;
			m_value = 0;
		}
		else {
			unt.nature.m_health = 100;
			m_value = sum_val - 100;
		}
	}
private:
	int m_value;
};

class Toxin : public Artifact, public onFieldObject
{
public: 
	Toxin(int val = 50) : m_value(val) {
		if (val > 100) m_value = 100;
		else if (val < 0) m_value = 0;
	};

	int Value() { return m_value; };
	virtual void apply(Unit &unt) {
		int dif_val = unt.nature.m_health - m_value;
		if (dif_val <= 0) {
			unt.nature.m_health = 0;
			m_value = -(dif_val);
		}
		else {
			unt.nature.m_health = dif_val;
			m_value = 0;
		}
	}
private:
	int m_value;
};
