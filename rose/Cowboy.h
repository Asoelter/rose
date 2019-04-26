#pragma once

#include <array>
#include <stdint.h>
#include <vector>

#include "actor.h"

/**
 * @brief A class for drawing a cowboy character.
 * 
 */
class Cowboy : public Rose::Character::Actor
{
public:

	/**
	 * @brief Construct a new Cowboy object
	 * 
	 */
	Cowboy();

	/**
	 * @brief Destroy the Cowboy object
	 * 
	 */
	virtual ~Cowboy() = default;

	void moveUp();

	void moveRight();

	void moveDown();

	void moveLeft();

	virtual void drawTo(sf::RenderWindow& window);

private:

	/**
	 * @brief Loads the texture from the file 
	 * 
	 * @param fileName The name of the file that holds the textures
	 */
	void loadTexture(const std::string&& fileName);

	static std::vector<sf::Texture> textures_;
	static bool loaded_;
	static constexpr int idleTextureIndex_ = 7;

	uint8_t	framesBetweenMoves_;
};

