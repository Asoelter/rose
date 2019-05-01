#ifndef ATTACKER_H
#define ATTACKER_H

#include "actor.h"

/**
 * @brief Base class for all characters who are 
 * able to attack to inherit from 
 * 
 */
namespace Rose::Character
{
	class Attacker : public Actor
	{
	public:

		virtual ~Attacker() = default;
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

	private:
		struct Index
		{
			float x;
			float y;
		};
	};
}

#endif //ATTACKER_H
