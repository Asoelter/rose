#pragma once
#include "game.h"
#include "actor.h"

class HealthBar
{
public:
	const float maxHealth = 100;//This is just an idea for the max health
	sf::Vector2f healthBarSize;
	float currentHealth;
	float currentHealthPercentage;

	/**
	 * @brief Construct a new Health Bar object
	 * 
	 */
	HealthBar();

	/**
	 * @brief Destroy the Health Bar object
	 * 
	 */
	~HealthBar();

	/**
	 * @brief Calculates the percentage of health the character
	 * has left
	 * 
	 * @param link The character to calculate the percentage of 
	 * health remaining
	 */
	void calculateHealthPercentage(Rose::Character::Actor &link);

	/**
	 * @brief Create the border of the healthbar
	 * 
	 * @param link The character to create the outline for
	 * 
	 * @return sf::RectangleShape The outline rectangle
	 */
	sf::RectangleShape createOutlineRect(Rose::Character::Actor &link);

	/**
	 * @brief Create a rectangle the shows the amount of
	 * health the actor has remaining
	 * 
	 * @param link The actor
	 * @return sf::RectangleShape The healthbar 
	 */
	sf::RectangleShape createHealthAmountRect(Rose::Character::Actor &link);

	/**
	 * @brief Draws the healthbar to the window
	 * 
	 * @param window The window to draw to 
	 * 
	 * @param link The character who's healthbar is 
	 * being drawn 
	 */
	void drawHealthBar(sf::RenderWindow &window, Rose::Character::Actor &link);
};

