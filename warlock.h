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

};