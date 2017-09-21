#pragma once
#include "Coordinates.h"
#include "Target.h"

enum Warhead { EXPLOSIVE, NUCLEAR };


struct Missile {
	Warhead payload;
	Coordinates coordinates;
	Target target;

	bool armed = false;

	void arm()
	{
		armed = true;
	}

	void selectWarhead(bool type)
	{
		if (type == 0)
		{
			payload = Warhead::EXPLOSIVE;
		}
		else
		{
			payload = Warhead::NUCLEAR;
		}
	}
	std::string warheadName()
	{
		return std::to_string(payload);
	}
};