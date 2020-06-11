#include <stdlib.h>
class warlock 
{
	int intellect = 11285;
	int stamina = 20501;
	int armor = 0;

	int crit = 14;
	float haste = 18;
	float mastery = 43;
	float versatility = 9.35;
	float avoidance = 0;

	int conflagCharges = 2;
	int backdraft = 0;

	//damage meters

	//incinerate
	int incinerateHits = 0;
	int incinerateCritHits = 0;
	int incinerateDamage = 0;
	int incinerateCritDamage = 0;

	//immolate
	int immolateHits = 0;
	int immolateCritHits = 0;
	int immolateDamage = 0;
	int immolateCritDamage = 0;

	//immolateDot
	int immolateDotHits = 0;
	int immolateDotCritHits = 0;
	int immolateDotDamage = 0;
	int immolateDotCritDamage = 0;

	//conflag
	int conflagCritDamage = 0;
	int conflagCritHits = 0;
	int conflagDamage = 0;
	int conflagHits = 0;
	
	//chaosBolts

	int chaosBoltDamage = 0;
	int chaosBoltHits = 0;

	//soul shards
	int soulShardFragments = 30;

	//dot timers
	double castTime = 0;
	double immolateDotTimeLeft = 0; //counts down
	double immolateDotTime = 0; //counts up

	//cooldown timers
	double conflagTimer = 11;

	bool currentlyCasting = false;
public:

	void dpsChart(double fightLength) {
		//incinerate
		std::cout << std::endl << std::endl << "---------------------------------" << std::endl << "fight Length " << fightLength << std::endl <<"dps " << (incinerateCritDamage + incinerateDamage + immolateCritDamage + immolateDamage + immolateDotCritDamage + immolateDotDamage
			+ conflagCritDamage + conflagDamage + chaosBoltDamage) / fightLength << std::endl  << "Total Damage " << incinerateCritDamage + incinerateDamage + immolateCritDamage + immolateDamage + immolateDotCritDamage + immolateDotDamage
			+ conflagCritDamage + conflagDamage + chaosBoltDamage << std::endl << "Incinerate damage : " << incinerateCritDamage + incinerateDamage << std::endl << "Immolate damage : " << immolateCritDamage + immolateDamage << std::endl
			<< "Immolate (dot) : " << immolateDotCritDamage + immolateDotDamage << std::endl << "Conflag : " << conflagDamage + conflagCritDamage << std::endl
			<< "Chaos bolt : " << chaosBoltDamage << std::endl << std::endl << "Shards : " << soulShardFragments << std::endl << "conflag charges " << conflagCharges << std::endl
			<< "conflag cd " << conflagTimer << std::endl << "Immolate timer " << immolateDotTimeLeft << std::endl << "---------------------------------" << std::endl;
	}

	bool canCastChaosBolt() {
		if (soulShardFragments >= 20) {
			return true;
		}
		else
			return false;
	}

	bool canCastConflig() {
		if (conflagCharges >= 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isCasting() 
	{
		if (castTime == 0) 
		{
			return false;
		}
		else
			return true;
	}

	float immoDT() {
		return immolateDotTimeLeft;
	}

	void decreaseTime() {
		if (castTime > 0) {
			castTime -= 0.1;
		}
		if (castTime < 0) {
			castTime = 0;
		}
		
		if (conflagCharges <= 1) {
			conflagTimer -= 0.1;


			if (conflagTimer <= 0) {
				std::cout << "conflag timer";
				conflagCharges += 1;
				conflagTimer = 11;
			}
		}
	}

	void incinerate() 
	{
		if (castTime == 0) 
		{
			float baseCastTime = 2.0;
			castTime = baseCastTime * (1 - (haste / 100));

			if (backdraft > 0) {
				castTime = castTime * (1 - 0.30);
				backdraft -= 1;
			}
			

		}
			if (castTime <= 0.1) 
			{
				//draws fire toward the enemy, dealing 56.4% fire damage.
				float spellPercent = 0.5643294758;
				int baseDamage = intellect * spellPercent;
				int masteryRand = mastery;
				int damage = baseDamage * (1 + (versatility / 100));
				int bonusDamage = damage * (1 + ((mastery + (rand() % masteryRand)) / 100));

				soulShardFragments += 2;
				
				//crit damage
				if (rand() % 100 <= crit) 
				{
					bonusDamage = bonusDamage * 2;
					incinerateCritDamage += bonusDamage;
					incinerateCritHits += 1;
					soulShardFragments += 1;
				}
				else {
					incinerateDamage += bonusDamage;
					incinerateHits += 1;
				}

				if (soulShardFragments > 50) {
					soulShardFragments = 50;
				}
				std::cout << "Cast time = " << castTime << " damage = " << damage << " bonusDamage = " << bonusDamage << std::endl;
			}
	}

	void conflagrate() 
	{
		//gcd
		if (castTime == 0)
		{
			float baseCastTime = 1.5;
			castTime = baseCastTime * (1 - (haste / 100));


			float spellPercent = 0.88;
			int baseDamage = intellect * spellPercent;
			int masteryRand = mastery;
			int damage = baseDamage * (1 + (versatility / 100));
			int bonusDamage = damage * (1 + ((mastery + (rand() % masteryRand)) / 100));

			if (rand() % 100 <= crit)
			{
				bonusDamage = bonusDamage * 2;
				conflagCritDamage += bonusDamage;
				conflagCritHits += 1;

			}
			else {
				conflagDamage += bonusDamage;
				conflagHits += 1;
			}
			soulShardFragments += 5;
			conflagCharges -= 1;
			backdraft += 1;

			if (soulShardFragments > 50) {
				soulShardFragments = 50;
			}
		}
	}

	void chaosBolt() 
	{
		float spellPercent = 2.11;
		int baseDamage = intellect * spellPercent;
		if (castTime == 0)
		{
			float baseCastTime = 3.0;
			castTime = baseCastTime * (1 + (haste / 100));

			if (backdraft > 0) {
				castTime = castTime * (1 - 0.30);
				backdraft -= 1;
			}
		}
		if (castTime <= 0.1)
		{
			int masteryRand = mastery;
			int damage = baseDamage * (1 + (versatility / 100));
			int bonusDamage = damage * (1 + ((mastery + (rand() % masteryRand)) / 100));

			bonusDamage = bonusDamage * 2;
			bonusDamage = bonusDamage * (1 + (crit / 100));

			chaosBoltDamage += bonusDamage;
			chaosBoltHits += 1;

			soulShardFragments -= 20;
		}
	}

	void immolate() 
	{
		if (castTime == 0) 
		{
			float baseCastTime = 1.5;
			castTime = baseCastTime * (1 - (haste / 100));
		}
		float spellPercent = 0.352;
		if (castTime <= 0.1) 
		{
			//initial hit
			int baseDamage = intellect * spellPercent;
			int masteryRand = mastery;
			int damage = baseDamage * (1 + (versatility / 100));
			int bonusDamage = damage * (1 + ((mastery + (rand() % masteryRand)) / 100));

			//crit initial hit
			if (rand() % 100 <= crit) {
				bonusDamage = bonusDamage * 2;
				immolateCritDamage += bonusDamage;
				immolateCritHits += 1;
			}
			else {
				immolateDamage += bonusDamage;
				immolateHits += 1;
			}

			std::cout << "Cast time = " << castTime << " damage = " << damage << " bonusDamage = " << bonusDamage << std::endl;
			if ((immolateDotTimeLeft + 18) >= 23) {
				immolateDotTimeLeft = 23;

			}

			else 
			{
				immolateDotTimeLeft += 18;
			}
		}
	}

	

	void immolateDot()
	{

		immolateDotTime += 0.1;
		immolateDotTimeLeft -= 0.1;
		float baseTickSpeed = 2.55;
		float spellPercent = 0.352;
		float dotDamagePercent = 1.32;
		int nuOfTicks = 18 / (baseTickSpeed / (1 + (haste / 100)));

		if (immolateDotTime >= (baseTickSpeed / (1 + (haste / 100)))) 
		{
			int masteryRand = mastery;
			float dotSum = 0;
			int  dotBaseDamage = (intellect * dotDamagePercent) / nuOfTicks;
			int dotDamage = dotBaseDamage * (1 + (versatility / 100));
			int periodicDamgae = dotBaseDamage * (haste / 100);


			int dotBonusDamage = dotDamage * (1 + ((mastery + (rand() % masteryRand)) / 100));
			soulShardFragments += 1;

			if (rand() % 100 <= crit) {
				dotBonusDamage = dotBonusDamage * 2;
				immolateDotCritDamage += dotBonusDamage;
				immolateDotCritHits += 1;
				if (rand() % 2 == 1) {
					soulShardFragments += 1;
				}
			}
			else {
				immolateDotDamage += dotBonusDamage;
				immolateDotHits += 1;
			}

			dotSum += dotBonusDamage;

			std::cout << " dot damage" << dotBonusDamage << std::endl;
			immolateDotTime = 0;
		}
		else if (immolateDotTimeLeft == 0.1) {
			int  dotBaseDamage = (intellect * dotDamagePercent) / nuOfTicks;
			int dotDamage = dotBaseDamage * (1 + (versatility / 100));
			int periodicDamage = dotBaseDamage * (haste / 100);
			immolateDotTime = 0;
		}

		if (soulShardFragments > 50) {
			soulShardFragments = 50;
		}
	}
	
};