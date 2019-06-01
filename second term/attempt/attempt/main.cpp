#pragma once
#include "pch.h"
#include <iostream>
#include "staff.h"
#include "field.h"
#include <string>
#include <vector>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	cout << "инициализируем поле игры:" << endl;
	Field field(1200, 1400);

	class Team {
	public:
		Team(const char* name, Unit* teamLeader): m_name(name), m_teamLeader(teamLeader) {};
		void addMember(Unit* unit) {
			m_teamMembers.push_back(unit);
		}
		~Team() {};
	private:
		const char* m_name;
		Unit* m_teamLeader;
		vector<Unit*> m_teamMembers;
	};
	
	cout << "инициализируем бойца 1.." << endl;
	Unit unitOne("Boromir", 70, 100);
	cout << "инициализируем бойца 2.." << endl;
	Unit unitTwo("ZlobnuyVasya", 100, 70);
	cout << "инициализируем бойца 3.." << endl;
	Unit unitThree("Voromir", 80, 90);
	cout << "инициализируем бойца 4.." << endl;
	Unit unitFour("ZlobnuyPetya", 90, 80);
	Team redTeam("gnomes" , &unitOne);
	Team blueTeam("UglyBoys", &unitTwo);

	Elixir elixirBig(70);
	elixirBig.putOnField(&field, { 100, 500 });
	Elixir elixirSmall(10);
	elixirBig.putOnField(&field, { 500, 100 });
	Toxin toxinBig(25);
	toxinBig.putOnField(&field, { 1000, 500 });
	Toxin toxinSmall(5);
	toxinSmall.putOnField(&field, { 500, 1000 });
	// тест метода apply для токсина
	cout << unitOne.Name() << " health: " << unitOne.Health() << endl;
	cout << "объем яда "<<toxinBig.Value() << endl;
	toxinBig.apply(unitOne);
	cout << unitOne.Name() << " health: " << unitOne.Health() << endl;
	cout << "осталось яда " << toxinBig.Value() << endl;
	// тест метода apply для эликсира
	cout << unitOne.Name() << " health: " << unitOne.Health() << endl;
	cout << "объем лекарства " << elixirBig.Value() << endl;
	elixirBig.apply(unitOne);
	cout << unitOne.Name() << " health: " << unitOne.Health() << endl;
	cout << "осталось лекарства " << elixirBig.Value() << endl;

}

