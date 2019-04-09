#ifndef ATTACKER_H
#define ATTACKER_H

#include "actor.h"

/**
 * @brief Base class for all characters who are 
 * able to attack to inherit from 
 * 
 */
struct Attacker : public Actor
{
	/**
	 * @brief Construct a new Attacker object
	 * 
	 */
	Attacker() : Actor() {}

	/**
	 * @brief A virtual function for attacking
	 * 
	 */
	virtual void attack() = 0;
};

#endif //ATTACKER_H
