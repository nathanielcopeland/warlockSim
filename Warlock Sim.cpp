// Warlock Sim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
float immolateDotTime = 0;
#include <iostream>
#include <functional>
#include <time.h> 
#include <stdlib.h> 
#include <algorithm>
#include "warlock.h";

void incinerate() {
	float baseCastTime = 2.0;
	
	std::cout << "Cast time = " <<  " damage = "  << " bonusDamage = "  << std::endl;
}

void print_num(int i)
{
	std::cout << i << '\n';
}

int main()
{
	srand(time(0));
	 warlock Warlock;
	 immolateDotTime = 0;
	 bool playing = true;
	 bool validSpell = true;
	 double fightLength = 0;
	 std::function<void(warlock *)> spell = NULL;
	 while (playing) {

		 int input;
		 if (!Warlock.isCasting()) {
			 do  {
				 validSpell = true;
				 std::cout << std::endl;
				 std::cout << "1. incinerate 2. Immolate 3. Conflagrate 4. Chaos Bolt 6. Exit\n";
				 std::cin >> input;
				 std::cout << std::endl;
				 switch (input) {
				 case 1:
					 spell = &warlock::incinerate;
					 //Warlock.incinerate();

					 break;
				 case 2:
					 spell = &warlock::immolate;
					 break;
				 case 3:
					 if (Warlock.canCastConflig()) {
						 spell = &warlock::conflagrate;
					 }
					 else {
						 validSpell = false;
					 }
					 
					 break;
				 case 4:
					 if (Warlock.canCastChaosBolt()) {
						 spell = &warlock::chaosBolt;
					 }
					 else {
						 validSpell = false;
					 }

					 break;
				 case 6:
					 playing = false;
				 }
			 } while (!validSpell);
		 }
		 
		 spell(&Warlock);
		 if (Warlock.immoDT() > 0) {
			 Warlock.immolateDot();
		 }
		 //spell = &warlock::decreaseTime;
		 Warlock.decreaseTime();
		 fightLength += 0.1;
		 Warlock.dpsChart(fightLength);
	 }	 

	 
}

