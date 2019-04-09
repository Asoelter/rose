#pragma once
#include <iostream>
#include "CharacterStats.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "actor.h"

class MainCharacter : public Actor
{
	int animationPicNumber;
	std::vector<sf::Texture> textures;
	bool dying;
	CharacterStats mainCharacter;
	StateOfCharacter currentCharacterState;
	StateOfCharacter nextCharacterState;

public:

	/**
	 * @brief Construct a new Main Character object
	 * 
	 */
	MainCharacter();

	/**
	 * @brief 
	 * 
	 * @param filename 
	 */
	void separateImageToArrayOfTextures(const std::string& filename);

	/**
	 * @brief 
	 * 
	 * @param window 
	 */
	void drawCharacter(sf::RenderWindow& window);

	/**
	 * @brief 
	 * 
	 * @return float 
	 */
	float getXLocation();

	/**
	 * @brief 
	 * 
	 * @return float 
	 */
	float getYLocation();

	/**
	 * @brief 
	 * 
	 * @param amount 
	 */
	void walkRight(float amount);

	/**
	 * @brief 
	 * 
	 * @param amount 
	 */
	void walkLeft(float amount);

	/**
	 * @brief 
	 * 
	 * @param amount 
	 */
	void walkUp(float amount);

	/**
	 * @brief 
	 * 
	 * @param amount 
	 */
	void walkDown(float amount);

	/**
	 * @brief 
	 * 
	 * @param UserXPosition 
	 * @param UserYPosition 
	 */
	void chaseUser(float UserXPosition, float UserYPosition);

	/**
	 * @brief Set the State object
	 * 
	 * @param state 
	 */
	void setState(StateOfCharacter state);
};


