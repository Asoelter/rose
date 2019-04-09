#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>

class Tile;

//Base class for any character type to inherit from 

class Actor
{
public:
	/**
	 * @brief Construct a new Actor object
	 * 
	 */
	Actor();

	/**
	 * @brief Destroy the Actor object
	 * 
	 */
	virtual ~Actor()			= default;

	/**
	 * @brief Moves the actor up 
	 * 
	 */
	virtual void moveUp()		= 0;

	/**
	 * @brief Moves the actor to the right 
	 * 
	 */

	virtual void moveRight()	= 0;

	/**
	 * @brief Moves the actor down 
	 * 
	 */
	virtual void moveDown()		= 0;

	/**
	 * @brief Moves the actor left
	 * 
	 */
	virtual void moveLeft()		= 0;

	/**
	 * @brief Returns the position of the actor in screen 
	 * coordinates measured from the left side of the screen
	 * 
	 * @return float the x-position of the actor 
	 */
	virtual float xPos() const;

	/**
	 * @brief Returns the position of the actor in screen 
	 * coordinates measured from the top of the screen
	 * 
	 * @return float The y-position of the actor 
	 */
	virtual float yPos() const;

	/**
	 * @brief Draws the actor to the window 
	 * 
	 * @param window The window to draw the actor to 
	 */
	virtual void drawTo(sf::RenderWindow& window);

	/**
	 * @brief Not implemented yet, but will be used to connect
	 * a tile and a character 
	 * 
	 * @param tile The tile the character is occupying 
	 */
	void occupy(Tile* tile);

protected:
	enum class Orientation
	{
		IDLE,
		FACING_DOWN,
		FACING_LEFT,
		FACING_UP,
		FACING_RIGHT
	};
	
	std::vector<sf::Texture> textures_;  
	sf::Sprite sprite_;					
	int currentTextureIndex_;			
	Tile* occupiedTile_;
};

