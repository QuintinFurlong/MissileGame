#pragma once
#include <iostream>

typedef struct Position
{
	int x, y;
	//prints out position of object
	void print()
	{
		std::cout << x << " EAST " << y << " SOUTH" << std::endl;
	}
	//randomly genrates position based on inputted number
	void setPos(int num)
	{
		x = (rand() % num) + 1;
		y = (rand() % num) + 1;
	}

}Coordinates;