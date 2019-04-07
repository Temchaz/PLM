#pragma once
#include "unit.h"
class elixir
{
public:
	elixir(int val = 30)
	{
		m_value = val;
	}

	int useElixir(int val) {
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

