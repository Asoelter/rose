#pragma once
#include "game.h"

class HealthBar
{
public:
	const float maxHealth = 100;//This is just an idea for the max health
	sf::Vector2f healthBarSize;
	int currentHealth;
	float currentHealthPercentage;

	HealthBar(sf::RenderWindow &window);
	~HealthBar();

	void calculateHealthPercentage(Rose::Character::Link link);
	sf::RectangleShape createOutlineRect(Rose::Character::Link link);
	sf::RectangleShape createHealthAmountRect(Rose::Character::Link link);
	void drawHealthBar(sf::RenderWindow &window, Rose::Character::Link link);
};

