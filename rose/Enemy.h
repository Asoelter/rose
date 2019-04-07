#pragma once
class Enemy
{
public:
	Enemy();
	virtual ~Enemy() = default;

protected:
	double m_health = 100;
	int m_damage = 0;
	int xp;
	bool alive;

	virtual void heal();
	virtual void takeDamage(int damage);
	virtual int sendXP(int x);
};

