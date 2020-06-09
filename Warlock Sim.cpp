
#include <iostream>
#include <thread>
#include <time.h> 
#include <stdlib.h> 
#include "warlock.h";

int main()
{
	srand(time(0));
	 warlock Warlock;

	 bool playing = true;
	 
	 while (playing) {

		 int input;

		 std::cout << "1. incinerate 2. Exit\n";
		 std::cin >> input;

		 switch (input) {
		 case 1:
			 Warlock.incinerate();
			 break;
		 case 2:
			 playing = false;
		 }
	 }	 

	 
}

