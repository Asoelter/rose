#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <iostream>
#include "CharacterStats.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "actor.h"

class MainCharacter 
{
	int animationPicNumber;
	bool dying;
	CharacterStats mainCharacter;
	StateOfCharacter currentCharacterState;
	StateOfCharacter nextCharacterState;
	std::vector<sf::Texture> textures;

public:

	/**
	 * @brief Construct a new Main Character object
	 * 
	 */
	MainCharacter(std::vector<sf::Texture> &texturesList);


	/**
	 * @brief Draws the character to the window
	 * 
	 * @param window The window to be drawn to 
	 */
	void drawCharacter(sf::RenderWindow& window);

	/**
	 * @brief The horizontal position of the character
	 * 
	 * @return float The Horizontal position of 
	 * the character in pixels
	 */
	float getXLocation();

	/**
	 * @brief The vertical position of the character
	 * 
	 * @return float The vertical position of 
	 * the character in pixels
	 */
	float getYLocation();

	/**
	 * @brief Moves the character right
	 * 
	 * @param amount The number of pixels 
	 * to move by 
	 */
	void moveRight(float amount);

	/**
	 * @brief Moves the character left
	 * 
	 * @param amount The number of pixels 
	 * to move by 
	 */
	void moveLeft(float amount);

	/**
	 * @brief Moves the character up
	 * 
	 * @param amount The number of pixels 
	 * to move by 
	 */
	void moveUp(float amount);

	/**
	 * @brief Moves the character down
	 * 
	 * @param amount The number of pixels 
	 * to move by 
	 */
	void moveDown(float amount);

	/**
	 * @brief Chases the user 
	 * 
	 * @param UserXPosition The horizontal position of the user 
	 * 
	 * @param UserYPosition The vertical position of the user 
	 */
	void chaseUser(float UserXPosition, float UserYPosition);

	/**
	 * @brief Set the State object
	 * 
	 * @param state The state to be set to 
	 */
	void setState(StateOfCharacter state);
};

#endif //MAIN_CHARACTER_H
