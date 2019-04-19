#include "attacker.h"

#define DEBUG

#ifdef DEBUG
#	include <iostream>
#endif 

void Attacker::attack()
{
	auto attackerIndices = Actor::mapIndices();
	int victimXpos = 0;
	int victimYpos = 0;

	switch(Actor::currentOrientation_)
	{
		case Orientation::IDLE:
		case Orientation::FACING_DOWN:
		{
			victimXpos = attackerIndices.first;
			victimYpos = attackerIndices.second + 1;
		}break;
		case Orientation::FACING_LEFT:
		{
			victimXpos = attackerIndices.first - 1;
			victimYpos = attackerIndices.second;
		}break;
		case Orientation::FACING_UP:
		{
			victimXpos = attackerIndices.first;
			victimYpos = attackerIndices.second - 1;
		}break;
		case Orientation::FACING_RIGHT:
		{
			victimXpos = attackerIndices.first + 1;
			victimYpos = attackerIndices.second;
		}break;
	}

	auto victimTile = Actor::map->tileAt(victimYpos, victimXpos);
	auto victim = victimTile->occupier();

	std::cout << "ATTACKER INDEX: " << attackerIndices.first << ", " << attackerIndices.second << std::endl;
	std::cout << "VICTIM INDEX: " << victimXpos << ", " << victimYpos << std::endl;

	if(victim)
	{
		victim->damage();

#		ifdef DEBUG
			std::cout << "found a victim" << std::endl;
#		endif 
	}
}
