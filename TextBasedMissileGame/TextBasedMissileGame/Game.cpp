// @author Quintin Furlong
// Login: C00218453
// Date: 14-9-17
// Time taken: 2 hours
//---------------------------------------------------------------------------
// text based missile game
// ---------------------------------------------------------------------------
// Known Bugs:can't type letters
// ?

#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <string>
#include "Missile.h"

int main()
{
	srand(time(NULL));
	std::cout << "ALOHA WORLD" << std::endl;

	Missile missile;
	bool type = true;
	unsigned int targetDistane = 99;
	std::string codeGuess = "";
	bool keepFighting = true;

	do
	{
		std::cout << "Please select a war head. 0:Explosive 1:Nuclear" << std::endl;
		std::cin >> type;
	} while (type != 0 && type != 1);
	
	missile.selectWarhead(type);
	if (missile.warheadName() == "1")
	{
		std::cout << "Launch Code :00000000" << std::endl;
	}
	else
	{
		std::cout << "Launch Code :37041707" << std::endl;
	}
	system("pause");
	system("CLS");

	missile.target.badSetPos(targetDistane);
	std::cout << "Aquiring Target . . . ." << std::endl;
	Sleep(1000);
	std::cout << "Target is at ";
	missile.target.coordinates.print();
	system("pause");
	system("CLS");

	std::getline(std::cin, codeGuess);//skips it the first time round
	while (!missile.armed)
	{
		std::cout << "Enter Launch" << std::endl;
		std::getline(std::cin, codeGuess);
		if (missile.warheadName() == "1")
		{
			if (codeGuess == "00000000")
			{
				missile.arm();
			}
		}
		else
		{
			if (codeGuess == "37041707")
			{
				missile.arm();
			}
		}
	}
	system("pause");
	system("CLS");

	while (keepFighting)
	{
		std::cout << "You fired your missile" << std::endl;
		if (missile.target.coordinates.x > missile.target.coordinates.y)
		{
			missile.coordinates.setPos(missile.target.coordinates.x);
		}
		else
		{
			missile.coordinates.setPos(missile.target.coordinates.y);
		}
		std::cout << "Your missile hit at ";
		missile.coordinates.print();
		if (missile.target.coordinates.x == missile.coordinates.x && missile.target.coordinates.y == missile.coordinates.y)
		{
			system("CLS");
			std::cout << "You destroyed your target" << std::endl;
			keepFighting = false;
		}
		else
		{
			std::cout << "You missed your target at ";
			missile.target.coordinates.print();
			std::cout << "0: Take another shoot     1:Surrender" << std::endl;
			std::cin >> type;
			if (type == 1)
			{
				system("CLS");
				std::cout << "Your target destroyed you" << std::endl;
				keepFighting = false;
			}
		}
	}
	std::cout << "The rest of the world attack out of fear, destroying the world;" << std::endl;
	std::cout << "ALOHA WORLD" << std::endl;

	system("pause");
}