#pragma once
#include <string>

class unit {
public:
	// ����������� �� ��������
	unit();
	// ����������� � ����������� �� ���������
	unit(std::string *pname, int health, int stamina);
	// ����������� �����������
	unit(const unit &other);

	int Id();

	int Health();
	void setHealth(int health);
	int Stamina();
	void setStamina(int stamina);
	int Damage();
	void setDamage(int damage);

	friend elixir;
	~unit();
private:
	static int s_id;
	int m_id;
	std::string* m_pname;
	int m_health;
	int m_stamina;
	int m_damage;
};
int unit::s_id = 0;

