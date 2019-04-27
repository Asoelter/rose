#pragma once
#include "game.h"
#include "actor.h"

class HealthBar
{
public:
	const float maxHealth = 100;//This is just an idea for the max health
	sf::Vector2f healthBarSize;
	int currentHealth;
	float currentHealthPercentage;

	HealthBar(sf::RenderWindow &window);
	~HealthBar();

	void calculateHealthPercentage(Rose::Character::Actor &link);
	sf::RectangleShape createOutlineRect(Rose::Character::Actor &link);
	sf::RectangleShape createHealthAmountRect(Rose::Character::Actor &link);
	void drawHealthBar(sf::RenderWindow &window, Rose::Character::Actor &link);
};

