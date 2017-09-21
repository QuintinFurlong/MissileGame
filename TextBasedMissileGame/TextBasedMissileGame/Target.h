#pragma once
#include <iostream>
#include "Coordinates.h"

typedef struct Enemy {
	Coordinates coordinates;
	
	void badSetPos(int num)
	{
		coordinates.setPos(num);
	}

}Target;