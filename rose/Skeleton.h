#pragma once
#include <array>
#include <stdint.h>
#include "actor.h"
#include "Enemy.h"

class Skeleton : public Actor, public Enemy
{
public:
	Skeleton();
	virtual ~Skeleton() = default;
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	void shockWave();
	void chasePlayer(float playerX, float playerY);
	virtual void drawTo(sf::RenderWindow& window);

private:
	float m_xPos;
	float m_yPos;
	float enemyMovementSpeed = 3;

	void loadTexture(const std::string&& fileName);

	static constexpr int idleTextureIndex_ = 0;

	uint8_t		framesBetweenMoves_;
};

