#pragma once
#include <array>
#include <stdint.h>
#include "actor.h"

class Skeleton : public Actor
{
public:
	Skeleton();
	virtual ~Skeleton() = default;
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	void shockWave();
	virtual void drawTo(sf::RenderWindow& window);

private:
	float enemyMovementSpeed = 3;

	void loadTexture(const std::string&& fileName);

	static constexpr int idleTextureIndex_ = 0;

	uint8_t		framesBetweenMoves_;
};

