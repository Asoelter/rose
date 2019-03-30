#pragma once

#include "StateOfCharacter.h"
class CharacterStats
{
	int hitPoints;
	int attack;
	int speed;
	int magic;
	int xPosition;
	int yPosition;
	bool facingRight;
	StateOfCharacter characterState;

public:
	CharacterStats();
	CharacterStats(int hitPointAmount, int attackAmount, int speedAmount, int magicAmount, int xStartPosition, int yStartPosition);

#pragma region getProperties
	int getHitPoints() {
		return hitPoints;
	}

	int getAttack() {
		return attack;
	}

	int getSpeed() {
		return speed;
	}

	int getMagic() {
		return magic;
	}

	int getXPosition() {
		return xPosition;
	}

	int getYPosition() {
		return yPosition;
	}

	StateOfCharacter getCharacterState() {
		return characterState;
	}

	bool getCharacterDirectionalOrientation() {
		return facingRight;
	}
#pragma endregion

#pragma region setProperties
	void setHitPoints(int hitPointAmount) {
		hitPoints = hitPointAmount;
	}

	void setAttack(int attackAmount) {
		attack = attackAmount;
	}

	void setSpeed(int speedAmount) {
		speed = speedAmount;
	}

	void setMagic(int MagicAmount) {
		magic = MagicAmount;
	}

	void setXPosition(int newXPosition) {
		xPosition = newXPosition;
	}

	void setYPosition(int newYPosition) {
		yPosition = newYPosition;
	}

	void setCharacterState(StateOfCharacter newCharacterState) {
		characterState = newCharacterState;
	}

	void setCharacterDirectionalOrientation(bool faceRight) {
		facingRight = faceRight;
	}
#pragma endregion


#pragma region increaseMethods
	void increaseHitPoints(int hitPointAmount);

	void increaseAttack(int attackAmount);

	void increaseSpeed(int SpeedAmount);

	void increaseMagic(int MagicAmount);

	void increaseXPosition(int xPositionIncrease);

	void increaseYPosition(int yPositionIncrease);
#pragma endregion




};



