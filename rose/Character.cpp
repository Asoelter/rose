class CharacterStats
{
	int hitPoints;
	int attack;
	int speed;
	int magic;
	int xPosition;
	int yPosition;

public:
	CharacterStats() {
		hitPoints = 10;
		attack = 1;
		speed = 1;
		magic = 1;
		xPosition = 0;
		yPosition = 0;
	}
	CharacterStats(int hitPointAmount, int attackAmount, int speedAmount, int magicAmount, int xStartPosition, int yStartPosition) {
		hitPoints = hitPointAmount;
		attack = attackAmount;
		speed = speedAmount;
		magic = magicAmount;
		xPosition = xStartPosition;
		yPosition = yStartPosition;
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