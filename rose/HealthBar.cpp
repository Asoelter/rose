#include "HealthBar.h"
#include "game.h"
#include "SFML/Graphics.hpp"
#include <iostream>



HealthBar::HealthBar()
{
	healthBarSize = sf::Vector2f(18, 5);// this size really fits link
}


HealthBar::~HealthBar()
{
}

void HealthBar::calculateHealthPercentage(Rose::Character::Actor &link) {
	currentHealth = link.getHealth();
	currentHealthPercentage = currentHealth / maxHealth;
}

sf::RectangleShape HealthBar::createOutlineRect(Rose::Character::Actor &link) {
	sf::RectangleShape outlineRect;
	outlineRect.setPosition(link.xPos() + link.getActorWidth() - healthBarSize.x, link.yPos() - 10);
	outlineRect.setSize(healthBarSize);
	outlineRect.setOutlineColor(sf::Color(250, 250, 250, 200));
	return outlineRect;
}

sf::RectangleShape HealthBar::createHealthAmountRect(Rose::Character::Actor &link) {
	sf::RectangleShape healthAmountRect;
	healthAmountRect.setPosition(link.xPos() + link.getActorWidth() - healthBarSize.x, link.yPos() - 10);
	healthAmountRect.setSize(sf::Vector2f(healthBarSize.x*currentHealthPercentage, healthBarSize.y));
	healthAmountRect.setFillColor(sf::Color(250, 0, 0, 200));
	return healthAmountRect;
}

void HealthBar::drawHealthBar(sf::RenderWindow &window, Rose::Character::Actor &link) {
	calculateHealthPercentage(link);
	window.draw(createOutlineRect(link));
	window.draw(createHealthAmountRect(link));	
}
