#pragma once

#include <array>
#include <stdint.h>

#include "actor.h"

/**
 * @brief A class for drawing a cowboy character.
 * 
 */
class Cowboy : public Actor
{
public:
	Cowboy();
	virtual ~Cowboy() = default;

	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();

	virtual void drawTo(sf::RenderWindow& window);

private:

	void loadTexture(const std::string&& fileName);

	static constexpr int idleTextureIndex_ = 7;

	uint8_t	framesBetweenMoves_;
};

