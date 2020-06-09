// Warlock Sim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
float immolateDotTime = 0;
#include <iostream>
#include <thread>
#include <time.h> 
#include <stdlib.h> 
#include "warlock.h";

void dot(warlock warl) {
	bool a = true;

	while (a) {
		std::cout << "hey \n";
		warl.immolateDot();
	}
	
}

void dotManager(warlock warl) {
	std::cout << "warlock manager dot \n";
	warl.returnDot();
}




int main()
{
	srand(time(0));
	 warlock Warlock;
	 immolateDotTime = 0;
	 bool playing = true;
	 
	 
	 //std::thread th1(dot, Warlock);
	 
	 std::thread th2(&warlock::immolateDot, Warlock);
	 Warlock.returnDot();

	 while (playing) {

		 int input;

		 std::cout << "1. incinerate 2. Exit\n";
		 std::cin >> input;

		 switch (input) {
		 case 1:
			 Warlock.incinerate();
			 break;
		 case 2:
			 Warlock.immolate();
			 Warlock.returnDot();

			 dotManager(Warlock);
			 break;
		 case 3:
			 playing = false;
		 }
	 }	 

	 
}

