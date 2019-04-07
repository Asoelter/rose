#include "Enemy.h"



Enemy::Enemy()
{
}

void Enemy::heal()
{
	m_health = m_health + (m_health*0.5);
}

void Enemy::takeDamage(int damage)
{
	m_damage = m_damage + damage;
	m_health = m_health - damage;
	if (m_health <= 0) 
	{
		alive = false;
	}
}

int Enemy::sendXP(int x)
{
	return x;
}

