#include <stdlib.h>
class warlock {
	int intellect = 3417;
	int stamina = 20501;
	int armor = 0;

	int crit = 15;
	float haste = 15;
	float mastery = 14;
	float versatility = 4.11;
	float avoidance = 0;


	//dot timers
	//float immolateDotTime = 0;
public:

	float immoDT() {
		return immolateDotTime;
	}

	void decreaseDotsTime() {
		if (immolateDotTime != 0) {
			immolateDotTime - 1;
		}
		
	}

	void returnDot() {
		std::cout << immolateDotTime << " idt \n";
	}

	void incinerate() {
		float baseCastTime = 2.0;
		float castTime = baseCastTime / (1 + (haste / 100));
		//draws fire toward the enemy, dealing 56.4% fire damage.
		float spellPercent = 0.5643294758;
		int baseDamage = intellect * spellPercent;
		int masteryRand = mastery;
		int damage = baseDamage * (1 + (versatility / 100));
		int bonusDamage =  damage * (1 + ((mastery + (rand() % masteryRand))/100));
		
		//crit damage
		if (rand() % 100 <= crit) {
			bonusDamage = bonusDamage * 2;
		}
		std::cout << "Cast time = " << castTime << " damage = " << damage << " bonusDamage = " << bonusDamage << std::endl;
	}


	void immolate() {
		float baseCastTime = 1.5;
		float castTime = baseCastTime / (1 + (haste / 100));
		float spellPercent = 0.352;
		float dotDamagePercent = 1.32;

		float baseTickSpeed = 2.55;
		int nuOfTicks = 18 / baseTickSpeed;

		//initial hit
		int baseDamage = intellect * spellPercent;
		int masteryRand = mastery;
		int damage = baseDamage * (1 + (versatility / 100));
		int bonusDamage = damage * (1 + ((mastery + (rand() % masteryRand)) / 100));

		//crit initial hit
		if (rand() % 100 <= crit) {
			bonusDamage = bonusDamage * 2;
		}

		std::cout << "Cast time = " << castTime << " damage = " << damage << " bonusDamage = " << bonusDamage << std::endl;
		std::cout << immolateDotTime << "timer \n";
		if ((immolateDotTime + 18) >= 23) {
			immolateDotTime = 23;
		}
		else {
			immolateDotTime += 18;
		}

		std::cout << immolateDotTime << "timer \n";
	}

	

	void immolateDot() {
		float baseCastTime = 1.5;
		float castTime = baseCastTime / (1 + (haste / 100));
		float spellPercent = 0.352;
		float dotDamagePercent = 1.32;

		float baseTickSpeed = 2.55;
		int nuOfTicks = 18 / baseTickSpeed;
		int masteryRand = mastery;
		float dotSum = 0;
		int  dotBaseDamage = (intellect * dotDamagePercent) / nuOfTicks;
		int dotDamage = dotBaseDamage * (1 + (versatility / 100));

		
		
		bool a = true;
		while (a) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2550));
		
		std::cout << immolateDotTime << " timer 3\n";
		if (immolateDotTime > 0) {
			int dotBonusDamage = dotDamage * (1 + ((mastery + (rand() % masteryRand)) / 100));

			if (rand() % 100 <= crit) {
				dotBonusDamage = dotBonusDamage * 2;
			}

			dotSum += dotBonusDamage;

			std::cout << " dot damage" << dotBonusDamage << std::endl;
		}
	}
			

	}
};