#include "skeleton.h"
#include <cassert>
#include <iostream>


skeleton::skeleton()
	: Actor()
	, framesBetweenMoves_(0)
{

	{
		loadTexture("assets/skeletonSpriteSheet.png");
		Actor::sprite_.setPosition({ 800.0f, 300.0f });
	}
}


void skeleton::idle() 
{

	
	++Actor::currentTextureIndex_;
	if (Actor::currentTextureIndex_ > 6)
	{
		Actor::currentTextureIndex_ = 0;
	}
	std::cout << currentTextureIndex_ << "\n";

	
	
	
	
	
	
	framesBetweenMoves_ = 0;
}
void skeleton::moveUp()
{
	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ > 2)
	{
		Actor::currentTextureIndex_ = 0;
	}

	Actor::sprite_.move({ 0.0f, -4.0f });
	framesBetweenMoves_ = 0;
}


void skeleton::moveRight()
{
	
}


void skeleton::moveDown()
{
	
}


void skeleton::moveLeft()
{
	
}


void skeleton::drawTo(sf::RenderWindow & window)
{
	++framesBetweenMoves_;

	if (framesBetweenMoves_ > 100)
	{
		Actor::currentTextureIndex_ = idleTextureIndex_;
	}

	Actor::drawTo(window);
}


void skeleton::loadTexture(const std::string && fileName)
{
	sf::Texture loader;
	int column = 64;
	int leftEdge = 0;
	for (int i = 0; i < 7; ++i)
	{
		leftEdge = 64 * i;
		bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 135, 64, 64));
		assert(success);
		Actor::textures_.push_back(loader);
	}
}

