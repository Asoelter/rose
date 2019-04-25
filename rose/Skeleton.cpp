#include "Skeleton.h"
#include <cassert>
#include <iostream>

#define DEBUG

#ifdef DEBUG
#	include <chrono>
#	include "log.h"
#endif 

Skeleton::Skeleton()
	: Actor()
	, framesBetweenMoves_(0)
{
	loadTexture("assets/skeletonSpriteSheet.png");

	Actor::sprite_.setPosition({ 800.0f, 300.0f });
	Actor::health_ = 3;
}



void Skeleton::moveUp()
{
	if (Actor::currentTextureIndex_ < 60)
	{
		Actor::currentTextureIndex_ = 60;
	}

	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ > 67)
	{
		Actor::currentTextureIndex_ = 60;
	}

	Actor::sprite_.move({ 0.0f, -4.0f });
	m_xPos = Actor::sprite_.getPosition().x;
	m_yPos = Actor::sprite_.getPosition().y;
	framesBetweenMoves_ = 0;
}


void Skeleton::moveRight()
{
	if (Actor::currentTextureIndex_ < 87)
	{
		Actor::currentTextureIndex_ = 87;
	}

	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ > 95)
	{
		Actor::currentTextureIndex_ = 87;
	}

	Actor::sprite_.move({ 4.0f, 0.0f });
	m_xPos = Actor::sprite_.getPosition().x;
	m_yPos = Actor::sprite_.getPosition().y;
	framesBetweenMoves_ = 0;
}


void Skeleton::moveDown()
{
	if (Actor::currentTextureIndex_ < 78)
	{
		Actor::currentTextureIndex_ = 78;
	}

	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ > 86)
	{
		Actor::currentTextureIndex_ = 78;
	}

	Actor::sprite_.move({ 0.0f, 4.0f });
	m_xPos = Actor::sprite_.getPosition().x;
	m_yPos = Actor::sprite_.getPosition().y;
	framesBetweenMoves_ = 0;
}


void Skeleton::moveLeft()
{
	if (Actor::currentTextureIndex_ < 69)
	{
		Actor::currentTextureIndex_ = 69;
	}
	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ > 77)
	{
		Actor::currentTextureIndex_ = 69;
	}

	Actor::sprite_.move({ -4.0f, 0.0f });
	m_xPos = Actor::sprite_.getPosition().x;
	m_yPos = Actor::sprite_.getPosition().y;
	framesBetweenMoves_ = 0;
}
// index 15-21
void Skeleton::shockWave()
{
	if (Actor::currentTextureIndex_ > 13) 
	{
		Actor::currentTextureIndex_ = 7;
	}
	if (Actor::currentTextureIndex_ < 7) 
	{
		Actor::currentTextureIndex_ = 7;
	}
	for (int i = 7; i < 13; i++) 
	{
		Actor::currentTextureIndex_++;
	}
	framesBetweenMoves_ = 0;
}

void Skeleton::chasePlayer(float playerX, float playerY)
{
	if (m_xPos != playerX) 
	{
		if (m_xPos < playerX) 
		{
			Actor::sprite_.move(3.0f, 0.0f);
			this->moveRight();
		}
		if (m_xPos > playerX)
		{
			Actor::sprite_.move(-3.0f, 0.0f);
			this->moveLeft();
		}
	}
	if (m_yPos != playerY)
	{
		if (m_yPos < playerY)
		{
			Actor::sprite_.move(0.0f, 3.0f);
			this->moveDown();
		}
		if (m_yPos > playerY)
		{
			Actor::sprite_.move(0.0f, 3.0f);
			this->moveUp();
		}
	}
	if (m_xPos == playerX && m_yPos == playerY) 
	{
		this->shockWave();
	}
}


void Skeleton::drawTo(sf::RenderWindow & window)
{
	++framesBetweenMoves_;

	if (framesBetweenMoves_ > 100)
	{
		Actor::currentTextureIndex_ = idleTextureIndex_;
	}

	Actor::drawTo(window);
#ifdef DEBUG
	static int count = 0;

	if(count % 100 == 0)
	{
		Rose::Logger::info("Skeleton index: ", Actor::horizontalTileIndex_, ", ", Actor::verticalTileIndex_);
		Rose::Logger::info("Skeleton Health", Actor::health_);
	}

	++count;
#endif 
	if(Actor::health_ <= 0)
	{
		Rose::Logger::info("SKELETON DEAD");
	}
}


void Skeleton::damage()
{
	--Actor::health_;
}


void Skeleton::loadTexture(const std::string && fileName)
{
	sf::Texture loader;
	int leftEdge = 0;

	//Row 1-4: 7 textures per row
	//Index 0 - 6 Skeleton spreads arms facing backwards

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++) 
		{
			leftEdge = 64 * j;
			
			bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 64*i, 64, 64));
			assert(success);
			Actor::textures_.push_back(loader);
		}
	}

	//Row 5-8: 8 textures per row

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			leftEdge = 64 * j;

			bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 64 * i + 256, 64, 64));
			assert(success);
			Actor::textures_.push_back(loader);
		}
	}

	//Row 9-12: 9 textures per row 

	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			leftEdge = 64 * j;

			bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 64 * i + 512, 64, 64));
			assert(success);
			Actor::textures_.push_back(loader);
		}
	}

	//Row 13-16: 6 textures per row 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			leftEdge = 64 * j;

			bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 64 * i + 768, 64, 64));
			assert(success);
			Actor::textures_.push_back(loader);
		}
	}

	//Row 17-20: 13 textures per row

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			leftEdge = 64 * j;

			bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 64 * i + 1024, 64, 64));
			assert(success);
			Actor::textures_.push_back(loader);
		}
	}
 
	//Last Row: 6 characters per row

	for (int j = 0; j < 6; j++)
	{
		leftEdge = 64 * j;

		bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 1280, 64, 64));
		assert(success);
		Actor::textures_.push_back(loader);
	}
}