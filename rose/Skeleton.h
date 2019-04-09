#pragma once
#include <array>
#include <stdint.h>
#include "actor.h"
#include "Enemy.h"

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

	/**
	 * @brief 
	 * 
	 */
	void moveUp();

	/**
	 * @brief 
	 * 
	 */
	void moveRight();

	/**
	 * @brief 
	 * 
	 */
	void moveDown();

	/**
	 * @brief 
	 * 
	 */
	void moveLeft();

	/**
	 * @brief 
	 * 
	 */
	void shockWave();

	/**
	 * @brief 
	 * 
	 * @param playerX 
	 * @param playerY 
	 */
	void chasePlayer(float playerX, float playerY);

	/**
	 * @brief 
	 * 
	 * @param window 
	 */
	virtual void drawTo(sf::RenderWindow& window);

private:
	float m_xPos;
	float m_yPos;
	float enemyMovementSpeed = 3;

	/**
	 * @brief 
	 * 
	 * @param fileName 
	 */
	void loadTexture(const std::string&& fileName);

	static constexpr int idleTextureIndex_ = 0;

	uint8_t		framesBetweenMoves_;
};

