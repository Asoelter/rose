#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>

class Tile;

//Base class for any character type to inherit from 
class Actor
{
public:
	Actor();
	virtual ~Actor()			= default;

	virtual void moveUp()		= 0;
	virtual void moveRight()	= 0;
	virtual void moveDown()		= 0;
	virtual void moveLeft()		= 0;

	virtual float xPos() const;
	virtual float yPos() const;

	virtual void drawTo(sf::RenderWindow& window);

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

