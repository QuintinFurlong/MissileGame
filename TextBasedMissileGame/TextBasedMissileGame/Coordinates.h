#pragma once
#include <iostream>

typedef struct Position
{
	
	int x, y;

	void print()
	{
		std::cout << x << " EAST " << y << " SOUTH" << std::endl;
	}

	void setPos(int num)
	{
		x = (rand() % num) + 1;
		y = (rand() % num) + 1;
	}

}Coordinates;