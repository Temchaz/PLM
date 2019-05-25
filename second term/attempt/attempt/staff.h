#pragma once
#include "pch.h"
#include <string>
#include "field.h"

class unit: public onFieldObject {
public:
	static int s_id;

	unit();	// конструктор по умолчнию
	unit(std::string *pname, int health, int stamina); // конструктор с параметрами по умолчанию
	unit(const unit &other); // конструктор копирования

	int Id();

	int Health();
	void setHealth(int health);
	int Stamina();
	void setStamina(int stamina);
	int Damage();
	void setDamage(int damage);

	friend class potion;
	friend class elixir;
	friend class toxin;

	~unit();

private:
	int m_id;
	std::string* m_pname;
	int m_health;
	int m_stamina;
	int m_damage;
};


void sharePotion(unit &unt, potion &what); // дружественная функция


class potion { // абстрактный класс
public:
	virtual void apply(unit &unt) = 0; //виртуальная функция
};

class elixir : public potion
{
public:
	elixir(int val = 30) {
		if (val > 100) val = 100;
		else if (val < 0) val = 0;
	};

	virtual void apply(unit &unt) {
		int sum_val = unt.m_health + m_value;
		if (sum_val < 100) {
			unt.m_health = sum_val;
			m_value = 0;
		}
		else {
			unt.m_health = 100;
			m_value = sum_val - 100;
		}
	}
private:
	int m_value;
};

class toxin : public potion
{
public:
	toxin(int val = 50) {
		if (val > 100) val = 100;
		else if (val < 0) val = 0;
	};

	virtual void apply(unit &unt) {
		int dif_val = unt.m_health - m_value;
		if (dif_val <= 0) {
			unt.m_health = 0;
			m_value = -(dif_val);
		}
		else {
			unt.m_health = dif_val;
			m_value = 0;
		}
	}
private:
	int m_value;
};
