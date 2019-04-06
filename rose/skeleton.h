#pragma once
#include <array>
#include <stdint.h>
#include "actor.h"

class skeleton : public Actor
{
public:
	skeleton();
	virtual ~skeleton()=default;
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	void idle();
	virtual void drawTo(sf::RenderWindow& window);

private:
	float enemyMovementSpeed = 3;

	void loadTexture(const std::string&& fileName);

	static constexpr int idleTextureIndex_ = 0;

	uint8_t		framesBetweenMoves_;
};

