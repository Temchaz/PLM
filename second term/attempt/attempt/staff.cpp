#pragma once
#include "pch.h"
#include <string>
#include "staff.h"

int unit::s_id = 0;
unit::unit() {
	m_pname = new std::string("noname");
	m_health = 0;
	m_stamina = 0;
	m_id = ++s_id;
}
unit::unit(std::string *pname, int health = 0, int stamina = 0) {
	m_pname = new std::string(*pname);
	setHealth(health);
	m_stamina = stamina;
	m_id = ++s_id;
}
unit::unit(const unit &other) {
	this->m_pname = new std::string(*other.m_pname);
	this->m_health = other.m_health;
	this->m_stamina = other.m_stamina;
	m_id = ++s_id;
}

int unit::Id() {
	return m_id;
}

int unit::Health() {
	return m_health;
}
void unit::setHealth(int health) {
	if (health < 0)
		m_health = 0;
	else if (health > 100)
		m_health = 100;
	else
		m_health = health;
	// или через тернарный оператор
	//m_health = (health < 0) ? 0 : (health > 100) ? 100 : health;
}
int unit::Stamina() {
	return m_stamina;
}
void unit::setStamina(int stamina) {
	if (stamina < 0)
		m_stamina = 0;
	else if (stamina > 0)
		m_stamina = 100;
	else m_stamina = stamina;
	// или через тернарный оператор
	//m_stamina = (stamina < 0) ? 0 : (stamina > 100) ? 100 : stamina;
}
int unit::Damage() {
	return m_damage;
}
void unit::setDamage(int damage) {
	if (damage < 0)
		m_damage = 0;
	else if (damage > 200)
		m_damage = 200;
	else m_damage = damage;
}

int operator +(unit &unt, elixir &elx) {
	elx.apply(unt);
	return unt.Health();
}

int operator +(unit &unt, toxin &txn) {
	txn.apply(unt);
	return unt.Health();
}

bool operator ==(unit &first, unit &second) {
	if (first.Damage() + first.Stamina() == second.Damage() + second.Stamina())
		return true;
	else return false;
}

void sharePotion(unit &unt, potion &what) { // дружественная функция
	what.apply(unt);
}

unit::~unit()
{
	delete m_pname;
}
