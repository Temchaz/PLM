#pragma once
#include "pch.h"
#include <string>
#include "field.h"

class Unit: public onFieldObject {
public:
	static int s_id;

	Unit();	// конструктор по умолчнию
	Unit(const char* pname, int health, int stamina); // конструктор с параметрами по умолчанию
	Unit(const Unit &other); // конструктор копирования

	int Id();

	int Health();
	int Stamina();
	int Damage();
	
	friend class Artifact;
	friend class Elixir;
	friend class Toxin;

	~Unit();

private:
	struct Nature { // вложенный класс
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


void sharePotion(Unit &unt, Artifact &what); // дружественная функция


class Artifact { // абстрактный класс
public:
	virtual void apply(Unit &unt) = 0; //виртуальная функция
};

class Elixir : public Artifact, public onFieldObject
{
public:
	Elixir(int val = 30) {
		if (val > 100) val = 100;
		else if (val < 0) val = 0;
	};

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
	Toxin(int val = 50) {
		if (val > 100) val = 100;
		else if (val < 0) val = 0;
	};

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
