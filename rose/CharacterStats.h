#pragma once

#include "StateOfCharacter.h"
class CharacterStats
{
	int hitPoints;
	int attack;
	int speed;
	int magic;
	float xPosition;
	float yPosition;
	bool facingRight;
	StateOfCharacter characterState;

public:
	/**
	 * @brief Construct a new Character Stats object
	 * 
	 */
	CharacterStats();

	/**
	 * @brief Construct a new Character Stats object
	 * 
	 * @param hitPointAmount  	The number of hitpoints the character has
	 * @param attackAmount 		The damage the character deals
	 * @param speedAmount 		The speed of the character
	 * @param magicAmount 		The amount of magic the character has (unused)
	 * @param xStartPosition 	The horizontal starting position of the character
	 * @param yStartPosition 	The vertical starting position of the character
	 */
	CharacterStats(int hitPointAmount, int attackAmount, int speedAmount, int magicAmount, float xStartPosition, float yStartPosition);

#pragma region getProperties
	/**
	 * @brief Get the Hit Points 
	 * 
	 * @return int The number of hit points
	 * the character has
	 */
	int getHitPoints() {
		return hitPoints;
	}

	/**
	 * @brief Get the amount of damage that
	 * the player deals
	 * 
	 * @return int The amount of damage the player deals
	 */
	int getAttack() {
		return attack;
	}

	/**
	 * @brief Get the Speed of the character
	 * 
	 * @return int The speed of the character
	 */
	int getSpeed() {
		return speed;
	}

	/**
	 * @brief Get the amount of magic the character has
	 * 
	 * @return int The amount of magic the character has 
	 */
	int getMagic() {
		return magic;
	}

	/**
	 * @brief The horizontal position of the character
	 * 
	 * @return float The horizontal position of the character 
	 */
	float getXPosition() {
		return xPosition;
	}

	/**
	 * @brief The vertical position of the character
	 * 
	 * @return float The vertical position of the character
	 */
	float getYPosition() {
		return yPosition;
	}

	/**
	 * @brief Get the Character State 
	 * 
	 * @return StateOfCharacter The state of the character
	 */
	StateOfCharacter getCharacterState() {
		return characterState;
	}

	/**
	 * @brief Get the Character Directional Orientation 
	 * 
	 * @return true If the character is facing right
	 * @return false If the character is not facing right 
	 */
	bool getCharacterDirectionalOrientation() {
		return facingRight;
	}
#pragma endregion

#pragma region setProperties
	/**
	 * @brief Set the amount of Hit Points of the character
	 * 
	 * @param hitPointAmount The amount of HP for the
	 * character
	 */
	void setHitPoints(int hitPointAmount) {
		hitPoints = hitPointAmount;
	}

	/**
	 * @brief Set the Attack amount
	 * 
	 * @param attackAmount The amount of damage the character
	 * can deal 
	 */
	void setAttack(int attackAmount) {
		attack = attackAmount;
	}

	/**
	 * @brief Set the Speed of the character
	 * 
	 * @param speedAmount The speed of the character
	 */
	void setSpeed(int speedAmount) {
		speed = speedAmount;
	}

	/**
	 * @brief Set the Magic amount
	 * 
	 * @param MagicAmount The amount of magic the character has 
	 */
	void setMagic(int MagicAmount) {
		magic = MagicAmount;
	}

	/**
	 * @brief Sets the horizontal position of the character
	 * 
	 * @param newXPosition The new horizontal position 
	 */
	void setXPosition(float newXPosition) {
		xPosition = newXPosition;
	}

	/**
	 * @brief Sets the new vertical position of the character
	 * 
	 * @param newYPosition The new vertical position 
	 */
	void setYPosition(float newYPosition) {
		yPosition = newYPosition;
	}

	/**
	 * @brief Set the Character State object
	 * 
	 * @param newCharacterState The new state 
	 */
	void setCharacterState(StateOfCharacter newCharacterState) {
		characterState = newCharacterState;
	}

	/**
	 * @brief Set the Character Directional Orientation object
	 * 
	 * @param faceRight A flag that determines if the character is facing
	 * right or not 
	 */
	void setCharacterDirectionalOrientation(bool faceRight) {
		facingRight = faceRight;
	}
#pragma endregion


#pragma region increaseMethods

	/**
	 * @brief Increases the characters hp by the hitPointAmount
	 * 
	 * @param hitPointAmount the amount to increase the characters
	 * hp by 
	 */
	void increaseHitPoints(int hitPointAmount);

	/**
	 * @brief Increases the characters attack by 
	 * attackAmount
	 * 
	 * @param attackAmount The amount to increase 
	 * the characters attack by  
	 */
	void increaseAttack(int attackAmount);

	/**
	 * @brief Increases the characters speed by 
	 * speedAmount
	 * 
	 * @param SpeedAmount The amount to increase 
	 * the characters speed by  
	 */
	void increaseSpeed(int SpeedAmount);

	/**
	 * @brief Increases the characters magic by 
	 * MagicAmount
	 * 
	 * @param SpeedAmount The amount to increase 
	 * the characters speed by  
	 */
	void increaseMagic(int MagicAmount);

	/**
	 * @brief Increases the characters horizontal position by 
	 * xPositionIncrease
	 * 
	 * @param SpeedAmount The amount to increase 
	 * the characters horizontal position by  
	 */
	void increaseXPosition(float xPositionIncrease);

	/**
	 * @brief Increases the characters vertical position by 
	 * xPositionIncrease
	 * 
	 * @param SpeedAmount The amount to increase 
	 * the characters vertical position by  
	 */
	void increaseYPosition(float yPositionIncrease);
#pragma endregion




};



