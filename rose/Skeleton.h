#pragma once
#include <array>
#include <stdint.h>
#include "actor.h"
#include "Enemy.h"

/**
 * @brief A class for drawing a Skeleton character
 * 
 */
class Skeleton : public Enemy
{
public:

	/**
	 * @brief Construct a new Skeleton object
	 * 
	 */
	Skeleton();
	/**
	* @brief constructs a new skeleton at a specified position.
	* @param int xPos: The x position for the skeleton to spawn.
	* @param int yPos: The y position for the skeleton to spawn.
	*/
	Skeleton(int xPos, int yPos);
	/**
	* @brief constructs a new skeleton at a specified position.
	* @param sf::Vector2i position: position vector for the skeleton
	*/
	Skeleton(sf::Vector2i position);

	/**
	 * @brief Destroy the Skeleton object
	 * 
	 */
	virtual ~Skeleton();
	/**
	* @brief moves the skeleton upwards on the screen while 
	* cycling through animations.
	*/
	void moveUp();
	/**
	* @brief moves the skeleton right on the screen while 
	* cycling through animations.
	*/
	void moveRight();
	/**
	* @brief moves the skeleton down on the screen while 
	* cycling through animations.
	*/
	void moveDown();
	/**
	* @brief moves the skeleton left on the screen while 
	* cycling through animations.
	*/
	void moveLeft();

	/**
	 * @brief The skeletons attack
	 * 
	 */
	void attack();

	/**
	 * @brief Chases the player
	 * 
	 * @param playerX The players horizontal position 
	 * @param playerY The players vertical position 
	 */
	void chasePlayer(float playerX, float playerY);
	/**
	* @brief draws the skeleton to the window.
	*/
	virtual void drawTo(sf::RenderWindow& window);
	/**
	* @brief subtracts health from the skeleton.
	*/
	void damage();
	/**
	* @brief calls all testing functions
	*/
	void runTests();
	/**
	* @brief checks to see if skeleton position changes 
	* correctly along x axis
	*/
	void testMoveLeft();
	/**
	* @brief checks to see if skeleton position changes correctly along x axis
	*/
	void testMoveRight();
	/**
	* @brief checks to see if skeleton position changes correctly along y axis
	*/
	void testMoveUp();
	/**
	* @brief checks to see if skeleton position changes correctly along y axis
	*/
	void testMoveDown();

private:
	float m_xPos;
	float m_yPos;
	sf::Image completeSpriteSheet;
	//float enemyMovementSpeed = 3; //Unused so commented out

	/**
	 * @brief Loads the textures from the file 
	 * 
	 * @param fileName The name of the file to 
	 * load the textures from 
	 */
	void loadTexture();

	static std::vector<int> textureRectsDescribedByFourInts_;
	//static std::vector<sf::Texture>		textures_;
	static bool							loaded_;
	static constexpr int				idleTextureIndex_ = 0;
	uint8_t								framesBetweenMoves_;
};
