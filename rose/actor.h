#pragma once 

#include <vector>
#include <SFML/Graphics.hpp>

//Base class for any character type to inherit from 
class Actor
{
public:
	Actor();
	virtual ~Actor() = default;

	virtual void moveUp()		= 0;
	virtual void moveRight()	= 0;
	virtual void moveDown()		= 0;
	virtual void moveLeft()		= 0;

	virtual void drawTo(sf::RenderWindow& window);

protected:
	enum class State
	{
		WALKING_UP,
		WALKING_RIGHT,
		WALKING_DOWN,
		WALKING_LEFT,
		IDLE
	};
	
	std::vector<sf::Texture> textures_; //A vector of textures to be loaded by the derived class
	sf::Sprite sprite_;					//The sprite used to draw with 
	int currentTextureIndex_;			//The index of the current texture in textures_...
										//manipulated by the derived class
};

