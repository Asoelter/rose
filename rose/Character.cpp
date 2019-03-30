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
	CharacterStats() {
		hitPoints = 10;
		attack = 1;
		speed = 1;
		magic = 1;
		xPosition = 0;
		yPosition = 0;
		characterState = idle;
		facingRight = true;
	}
	CharacterStats(int hitPointAmount, int attackAmount, int speedAmount, int magicAmount, int xStartPosition, int yStartPosition) {
		hitPoints = hitPointAmount;
		attack = attackAmount;
		speed = speedAmount;
		magic = magicAmount;
		xPosition = xStartPosition;
		yPosition = yStartPosition;
		characterState = idle;
		facingRight = true;
	}

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

	void increaseHitPoints(int hitPointAmount) {
		hitPoints += hitPointAmount;
	}

	void increaseAttack(int attackAmount) {
		attack += attackAmount;
	}

	void increaseSpeed(int SpeedAmount) {
		speed += SpeedAmount;
	}

	void increaseMagic(int MagicAmount) {
		magic += MagicAmount;
	}

	void increaseXPosition(int xPositionIncrease) {
		xPosition += xPositionIncrease;
	}

	void increaseYPosition(int yPositionIncrease) {
		yPosition += yPositionIncrease;
	}
#pragma endregion




};