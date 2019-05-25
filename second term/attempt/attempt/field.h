#pragma once

class Position {
public:
	Position(int px = 0, int py = 0, bool pinGame = false) : x(px), y(py), inGame(pinGame) {};
	bool inGame;
	int x;
	int y;
};

class Field {
public:

	Field(int wdt = 1000, int hdt = 1000) : width(wdt), height(hdt) {};
	bool inField(Position &p) {
		return (0 <= p.x <= width && 0 <= p.y <= height);
	};

	~Field() {};
private:
	int width;
	int height;
};

class onFieldObject {
public:
	onFieldObject(Field* field = NULL, bool onField = false, Position position = { 0,0 } ): m_field(field), m_onField(onField)
	{
		if (field != NULL) {
			if (field->inField(position)) m_position = position;
			else {
				m_onField = false;
				m_position = { 0,0 };
			}
		}
		else onField = false;
	};

	virtual int setOnField(Position position) { 
		if (m_field->inField(position)) {
			m_onField = true;
			return 0;
		}
		else return 1;
	};

	virtual bool onField() {
		return m_onField;
	};
	virtual Position getPosition(Position position) {
		return m_position;
	};
	virtual int setPosition(Position position) {
		if (m_field->inField(position)) {
			m_position = position;
			return 0;
		}
		else return 1;
	}
	~onFieldObject() {};
private:
	bool m_onField; 
	Position m_position;
	Field *m_field;
};