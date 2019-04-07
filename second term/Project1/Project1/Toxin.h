#pragma once
#include "unit.h"
class toxin
{
public:
	toxin(int val = 50)
	{
		m_value = val;
	}
	int useToxin(int val) {
		if (val <= m_value)
			m_value -= val;
		else {
			val = m_value;
			m_value = 0;
		}
		return val;
	}
private:
	int m_value;
};