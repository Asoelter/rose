#include "attacker.h"

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

	if(victim)
	{
		victim->damage();
	}
}
