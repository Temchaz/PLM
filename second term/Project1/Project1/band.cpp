#pragma once
#include "band.h"




band::band()
{
	m_id = s_id++;
}

int band::addUnit(unit* unt) {
	if (!staff.count(unt->Id))
		staff.insert()
}
int delUnit(unit* unt) {

}
int band::Id() {
	return m_id = s_id;
}


band::~band()
{
	staff.clear();
}
