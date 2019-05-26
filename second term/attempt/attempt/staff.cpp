#pragma once
#include "pch.h"
#include <string>
#include "staff.h"

int Unit::s_id = 0;
Unit::Unit() : m_pname("noname") {
	nature.m_health = 0;
	nature.m_stamina = 0;
	m_id = ++s_id;
}
Unit::Unit(const char* pname, int health = 0, int stamina = 0) : m_pname("noname") {
	nature.setHealth(health);
	nature.m_stamina = stamina;
	m_id = ++s_id;
}
Unit::Unit(const Unit &other) {
	m_pname = other.m_pname;
	this->nature.m_health = other.nature.m_health;
	this->nature.m_stamina = other.nature.m_stamina;
	m_id = ++s_id;
}

int Unit::Id() {
	return m_id;
}


int Unit::Health() {
	return nature.m_health;
}
int Unit::Stamina() {
	return nature.m_stamina;
}
int Unit::Damage() {
	return nature.m_damage;
}

void Unit::Nature::setHealth(int health) {
	if (health < 0)
		m_health = 0;
	else if (health > 100)
		m_health = 100;
	else
		m_health = health;
	// или через тернарный оператор
	//m_health = (health < 0) ? 0 : (health > 100) ? 100 : health;
}
void Unit::Nature::setStamina(int stamina) {
	if (stamina < 0)
		m_stamina = 0;
	else if (stamina > 0)
		m_stamina = 100;
	else m_stamina = stamina;
	// или через тернарный оператор
	//m_stamina = (stamina < 0) ? 0 : (stamina > 100) ? 100 : stamina;
}
void Unit::Nature::setDamage(int damage) {
	if (damage < 0)
		m_damage = 0;
	else if (damage > 200)
		m_damage = 200;
	else m_damage = damage;
}

int operator +(Unit &unt, Elixir &elx) {
	elx.apply(unt);
	return unt.Health();
}

int operator +(Unit &unt, Toxin &txn) {
	txn.apply(unt);
	return unt.Health();
}

bool operator ==(Unit &first, Unit &second) {
	if (first.Damage() + first.Stamina() == second.Damage() + second.Stamina())
		return true;
	else return false;
}

void sharePotion(Unit &unt, Artifact &what) { // дружественная функция
	what.apply(unt);
}

Unit::~Unit()
{
	delete m_pname;
}
