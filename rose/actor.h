#pragma once 

#include <SFML/Graphics.hpp>

class Actor : public sf::Drawable
{
public:
	Actor(sf::String&& fileName);
	virtual ~Actor();

private:
	sf::Texture texture_;
	sf::Sprite sprite_;
};

