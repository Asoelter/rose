#include "attacker.h"
#include "Skeleton.h"
#include "link.h"

#include <array>
#include <cassert>
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
		std::array<Index, 5> victimIndices;

		switch (Actor::currentOrientation_)
		{
		case Orientation::IDLE:
		case Orientation::FACING_DOWN:
		{
			victimIndices[0].x = attackerIndices.first - 2;
			victimIndices[0].y = attackerIndices.second + 1;

			victimIndices[1].x = attackerIndices.first - 1;
			victimIndices[1].y = attackerIndices.second + 1;

			victimIndices[2].x = attackerIndices.first;
			victimIndices[2].y = attackerIndices.second + 1;

			victimIndices[3].x = attackerIndices.first + 1;
			victimIndices[3].y = attackerIndices.second + 1;

			victimIndices[4].x = attackerIndices.first + 2;
			victimIndices[4].y = attackerIndices.second + 1;
		}break;
		case Orientation::FACING_LEFT:
		{
			victimIndices[0].x = attackerIndices.first - 1;
			victimIndices[0].y = attackerIndices.second -2;

			victimIndices[1].x = attackerIndices.first - 1;
			victimIndices[1].y = attackerIndices.second - 1;

			victimIndices[2].x = attackerIndices.first - 1;
			victimIndices[2].y = attackerIndices.second;

			victimIndices[3].x = attackerIndices.first - 1;
			victimIndices[3].y = attackerIndices.second + 1;

			victimIndices[4].x = attackerIndices.first - 1;
			victimIndices[4].y = attackerIndices.second + 2;
		}break;
		case Orientation::FACING_UP:
		{
			victimIndices[0].x = attackerIndices.first - 2;
			victimIndices[0].y = attackerIndices.second -1;

			victimIndices[1].x = attackerIndices.first - 1;
			victimIndices[1].y = attackerIndices.second - 1;

			victimIndices[2].x = attackerIndices.first;
			victimIndices[2].y = attackerIndices.second - 1;

			victimIndices[3].x = attackerIndices.first + 1;
			victimIndices[3].y = attackerIndices.second - 1;

			victimIndices[4].x = attackerIndices.first + 2;
			victimIndices[4].y = attackerIndices.second - 1;
		}break;
		case Orientation::FACING_RIGHT:
		{
			victimIndices[0].x = attackerIndices.first + 1;
			victimIndices[0].y = attackerIndices.second -2;

			victimIndices[1].x = attackerIndices.first + 1;
			victimIndices[1].y = attackerIndices.second - 1;

			victimIndices[2].x = attackerIndices.first + 1;
			victimIndices[2].y = attackerIndices.second;

			victimIndices[3].x = attackerIndices.first + 1;
			victimIndices[3].y = attackerIndices.second + 1;

			victimIndices[4].x = attackerIndices.first + 1;
			victimIndices[4].y = attackerIndices.second + 2;

		}break;
		}

		std::array<Tile*, 5> victimTiles;
		std::array<Actor*, 5> victims;

		for(std::vector<Tile*>::size_type i = 0; i < victimIndices.size(); ++i)
		{
			victimTiles[i] = map->tileAt(victimIndices[i].x, victimIndices[i].y);
		}

		for(std::vector<Actor*>::size_type i = 0; i < victimTiles.size(); ++i)
		{
			victims[i] = victimTiles[i]->occupier();
		}

		for(const auto& victim : victims)
		{
			if(victim)
			{
				victim->damage();
			}
		}
	}
}
