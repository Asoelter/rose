#include "attacker.h"

//#define DEBUG

#ifdef DEBUG
#	include <iostream>
#endif 

void Attacker::attack()
{
	auto attackerIndices = Actor::mapIndices();
	Actor* victim = nullptr;

	switch(Actor::currentOrientation_)
	{
		case Orientation::IDLE:
		case Orientation::FACING_DOWN:
		{
			auto victimTile = Actor::map->tileAt(attackerIndices.first + 1, attackerIndices.second);
			victim = victimTile->occupier();
		}break;
		case Orientation::FACING_LEFT:
		{
			auto victimTile = Actor::map->tileAt(attackerIndices.first, attackerIndices.second - 1);
			victim = victimTile->occupier();
		}break;
		case Orientation::FACING_UP:
		{
			auto victimTile = Actor::map->tileAt(attackerIndices.first - 1, attackerIndices.second);
			victim = victimTile->occupier();
		}break;
		case Orientation::FACING_RIGHT:
		{
			auto victimTile = Actor::map->tileAt(attackerIndices.first, attackerIndices.second + 1);
			victim = victimTile->occupier();
		}break;
	}

#ifdef DEBUG
	std::cout << "Link Indices: " << attackerIndices.first << ", " << attackerIndices.second << std::endl;
#endif 

	if(victim)
	{
		victim->damage();
#ifdef DEBUG
		std::cout << "found a victim" << std::endl;
#endif 
	}
}
