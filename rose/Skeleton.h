#pragma once
#include <array>
#include <stdint.h>
#include "actor.h"
#include "Enemy.h"

/**
 * @brief A class for drawing a Skeleton character
 * 
 */
class Skeleton : public Actor, public Enemy
{
public:

	/**
	 * @brief Construct a new Skeleton object
	 * 
	 */
	Skeleton();

	/**
	 * @brief Destroy the Skeleton object
	 * 
	 */
	virtual ~Skeleton() = default;

	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();

	/**
	 * @brief The skeletons attack
	 * 
	 */
	void shockWave();

	/**
	 * @brief Chases the player
	 * 
	 * @param playerX The players horizontal position 
	 * @param playerY The players vertical position 
	 */
	void chasePlayer(float playerX, float playerY);

	virtual void drawTo(sf::RenderWindow& window);
	void damage();

private:
	float m_xPos;
	float m_yPos;
	//float enemyMovementSpeed = 3; //Unused so commented out

	/**
	 * @brief Loads the textures from the file 
	 * 
	 * @param fileName The name of the file to 
	 * load the textures from 
	 */
	void loadTexture(const std::string&& fileName);

	static constexpr int idleTextureIndex_ = 0;

	uint8_t		framesBetweenMoves_;
};

