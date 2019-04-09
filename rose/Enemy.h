#include "actor.h"
#pragma once

class Enemy 
{
public:
	/**
	 * @brief Construct a new Enemy object
	 * 
	 */
	Enemy();

	/**
	 * @brief Destroy the Enemy object
	 * 
	 */
	virtual ~Enemy() = default;

protected:
	double m_health = 100;
	int m_damage = 0;
	int xp;
	bool alive;

	/**
	 * @brief 
	 * 
	 */
	virtual void heal();

	/**
	 * @brief 
	 * 
	 * @param damage 
	 */
	virtual void takeDamage(int damage);

	/**
	 * @brief 
	 * 
	 * @param x 
	 * @return int 
	 */
	virtual int sendXP(int x);

};

