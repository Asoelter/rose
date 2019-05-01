#include "Enemy.h"



Enemy::Enemy()
	: Attacker()
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


//void Enemy::follow(const Rose::Character::Actor& actor)
//{
//	auto xDiff = actor.xPos() - this->xPos();
//	auto yDiff = actor.yPos() - this->yPos();
//
//	if(xDiff > 0)
//	{
//		moveRight();
//	}
//	else
//	{
//		moveLeft();
//	}
//
//	if(yDiff > 0)
//	{
//		moveUp();
//	}
//	else
//	{
//		moveDown();
//	}
//}
