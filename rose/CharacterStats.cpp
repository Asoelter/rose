#include "CharacterStats.h"

#pragma region Constructors
CharacterStats::CharacterStats() {
	hitPoints = 10;
	attack = 1;
	speed = 1;
	magic = 1;
	xPosition = 0;
	yPosition = 0;
	characterState = idle;
	facingRight = true;
}

CharacterStats::CharacterStats(int hitPointAmount, int attackAmount, int speedAmount, int magicAmount, int xStartPosition, int yStartPosition) {
	hitPoints = hitPointAmount;
	attack = attackAmount;
	speed = speedAmount;
	magic = magicAmount;
	xPosition = xStartPosition;
	yPosition = yStartPosition;
	characterState = idle;
	facingRight = true;
}
#pragma endregion


#pragma region increaseMethods
void CharacterStats::increaseHitPoints(int hitPointAmount) {
	hitPoints += hitPointAmount;
}

void CharacterStats::increaseAttack(int attackAmount) {
	attack += attackAmount;
}

void CharacterStats::increaseSpeed(int SpeedAmount) {
	speed += SpeedAmount;
}

void CharacterStats::increaseMagic(int MagicAmount) {
	magic += MagicAmount;
}

void CharacterStats::increaseXPosition(int xPositionIncrease) {
	xPosition += xPositionIncrease;
}

void CharacterStats::increaseYPosition(int yPositionIncrease) {
	yPosition += yPositionIncrease;
}
#pragma endregion