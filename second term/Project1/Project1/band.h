#pragma once
#include <string>
#include <map>
#include "unit.h"
class band
{
public:
	band();
	int Id();
	int addUnit(unit* unt);
	int delUnit(unit* unt);
	~band();
private:
	static int s_id;
	int m_id;
	std::map<int, unit> staff;
	unit leader;
};
int band::s_id = 0;
