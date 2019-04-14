#ifndef ATTACKER_H
#define ATTACKER_H

#include "actor.h"

/**
 * @brief Base class for all characters who are 
 * able to attack to inherit from 
 * 
 */
class Attacker : public Actor
{
	public:
	/**
	 * @brief A virtual function for attacking
	 * 
	 */
	virtual void attack();

	protected:
	/**
	 * @brief Construct a new Attacker object
	 * 
	 */
	Attacker() : Actor() {}
};

#endif //ATTACKER_H
