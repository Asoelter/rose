#ifndef ATTACKER_H
#define ATTACKER_H

#include "actor.h"

struct Attacker : public Actor
{
	Attacker() : Actor() {}

	virtual void attack() = 0;
};

#endif //ATTACKER_H