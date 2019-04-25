#include "attacker.h"

#define DEBUG

#ifdef DEBUG
#	include <iostream>
#	include "log.h"
#endif 

namespace Rose::Character
{
	void Attacker::attack()
	{
		auto attackerIndices = Rose::Character::Actor::mapIndices();
		int victimXpos = 0;
		int victimYpos = 0;

		switch (Actor::currentOrientation_)
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

#		ifdef DEBUG
		Rose::Logger::info("ATTACKER INDEX: ", attackerIndices.first, ", ", attackerIndices.second);
		Rose::Logger::info("VICTIM INDEX: ", victimXpos, ", ", victimYpos);
#		endif 

		if (victim)
		{
			victim->damage();
		}
	}
}
