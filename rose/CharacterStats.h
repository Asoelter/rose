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
	 * @param hitPointAmount 
	 * @param attackAmount 
	 * @param speedAmount 
	 * @param magicAmount 
	 * @param xStartPosition 
	 * @param yStartPosition 
	 */
	CharacterStats(int hitPointAmount, int attackAmount, int speedAmount, int magicAmount, float xStartPosition, float yStartPosition);

#pragma region getProperties
	/**
	 * @brief Get the Hit Points object
	 * 
	 * @return int 
	 */
	int getHitPoints() {
		return hitPoints;
	}

	/**
	 * @brief Get the Attack object
	 * 
	 * @return int 
	 */
	int getAttack() {
		return attack;
	}

	/**
	 * @brief Get the Speed object
	 * 
	 * @return int 
	 */
	int getSpeed() {
		return speed;
	}

	/**
	 * @brief Get the Magic object
	 * 
	 * @return int 
	 */
	int getMagic() {
		return magic;
	}

	/**
	 * @brief 
	 * 
	 * @return float 
	 */
	float getXPosition() {
		return xPosition;
	}

	/**
	 * @brief 
	 * 
	 * @return float 
	 */
	float getYPosition() {
		return yPosition;
	}

	/**
	 * @brief Get the Character State object
	 * 
	 * @return StateOfCharacter 
	 */
	StateOfCharacter getCharacterState() {
		return characterState;
	}

	/**
	 * @brief Get the Character Directional Orientation object
	 * 
	 * @return true 
	 * @return false 
	 */
	bool getCharacterDirectionalOrientation() {
		return facingRight;
	}
#pragma endregion

#pragma region setProperties
	/**
	 * @brief Set the Hit Points object
	 * 
	 * @param hitPointAmount 
	 */
	void setHitPoints(int hitPointAmount) {
		hitPoints = hitPointAmount;
	}

	/**
	 * @brief Set the Attack object
	 * 
	 * @param attackAmount 
	 */
	void setAttack(int attackAmount) {
		attack = attackAmount;
	}

	/**
	 * @brief Set the Speed object
	 * 
	 * @param speedAmount 
	 */
	void setSpeed(int speedAmount) {
		speed = speedAmount;
	}

	/**
	 * @brief Set the Magic object
	 * 
	 * @param MagicAmount 
	 */
	void setMagic(int MagicAmount) {
		magic = MagicAmount;
	}

	/**
	 * @brief 
	 * 
	 * @param newXPosition 
	 */
	void setXPosition(float newXPosition) {
		xPosition = newXPosition;
	}

	/**
	 * @brief 
	 * 
	 * @param newYPosition 
	 */
	void setYPosition(float newYPosition) {
		yPosition = newYPosition;
	}

	/**
	 * @brief Set the Character State object
	 * 
	 * @param newCharacterState 
	 */
	void setCharacterState(StateOfCharacter newCharacterState) {
		characterState = newCharacterState;
	}

	/**
	 * @brief Set the Character Directional Orientation object
	 * 
	 * @param faceRight 
	 */
	void setCharacterDirectionalOrientation(bool faceRight) {
		facingRight = faceRight;
	}
#pragma endregion


#pragma region increaseMethods

	/**
	 * @brief 
	 * 
	 * @param hitPointAmount 
	 */
	void increaseHitPoints(int hitPointAmount);

	/**
	 * @brief 
	 * 
	 * @param attackAmount 
	 */
	void increaseAttack(int attackAmount);

	/**
	 * @brief 
	 * 
	 * @param SpeedAmount 
	 */
	void increaseSpeed(int SpeedAmount);

	/**
	 * @brief 
	 * 
	 * @param MagicAmount 
	 */
	void increaseMagic(int MagicAmount);

	/**
	 * @brief 
	 * 
	 * @param xPositionIncrease 
	 */
	void increaseXPosition(float xPositionIncrease);

	/**
	 * @brief 
	 * 
	 * @param yPositionIncrease 
	 */
	void increaseYPosition(float yPositionIncrease);
#pragma endregion




};



