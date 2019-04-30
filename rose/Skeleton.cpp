#include "Skeleton.h"
#include <cassert>
#include <iostream>

#define DEBUG

#ifdef DEBUG
#	include <chrono>
#	include "log.h"
#endif 

using namespace Rose::Character;

std::vector<sf::Texture>		Skeleton::textures_;
bool							Skeleton::loaded_ = false;

//Constructors and destructors
Skeleton::Skeleton()
	: Enemy()
	, framesBetweenMoves_(0)
{
	Actor::textures_ = &textures_;

	if(!loaded_)
	{
		loadTexture("assets/skeletonSpriteSheet.png");
		loaded_ = true;
	}

	Actor::sprite_.setPosition({ 800.0f, 300.0f });
	Actor::health_ = 3;
}
Skeleton::Skeleton(int xPos, int yPos)
	: Enemy()
	, framesBetweenMoves_(0)
{
	Actor::textures_ = &textures_;

	if(!loaded_)
	{
		loadTexture("assets/skeletonSpriteSheet.png");
		loaded_ = true;
	}

	Actor::sprite_.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
	Actor::health_ = 3;
}
Skeleton::Skeleton(sf::Vector2i position)
	: Enemy()
	, framesBetweenMoves_(0)
{
	Actor::textures_ = &textures_;

	if(!loaded_)
	{
		loadTexture("assets/skeletonSpriteSheet.png");
		loaded_ = true;
	}

	Actor::sprite_.setPosition(static_cast<float>(position.x), static_cast<float>(position.y));
	Actor::health_ = 3;
}
//movement functions
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
//tests for movement functions
void Skeleton::runTests()
{
	testMoveLeft();
	testMoveRight();
	testMoveDown();
	testMoveUp();
}
void Skeleton::testMoveLeft()
{
	m_xPos = 10;
	float testxPos = 10;

	//test move left
	moveLeft();
	if(m_xPos == 10)
	{
		std::cout << "SKELETON--TEST MOVE LEFT -> TEST FAILED: X VALUE DID NOT CHANGE\n";
	}
	else
	{
		std::cout << "SKELETON--TEST MOVE LEFT -> TEST PASSED: X VALUE CORRECTLY CHANGED\n";
	}
}
void Skeleton::testMoveRight()
{
	m_xPos = 10;
	float testxPos = 10;

	//test move right
	moveRight();
	if (m_xPos == 10)
	{
		std::cout << "SKELETON--TEST MOVE RIGHT -> TEST FAILED: X VALUE DID NOT CHANGE\n";
	}
	else
	{
		std::cout << "SKELETON--TEST MOVE RIGHT -> TEST PASSED: X VALUE CORRECTLY CHANGED\n";
	}
}
void Skeleton::testMoveUp()
{
	m_yPos = 10;
	float testyPos = 10;

	//test move right
	moveUp();
	if (m_yPos == 10)
	{
		std::cout << "SKELETON--TEST MOVE UP -> TEST FAILED: X VALUE DID NOT CHANGE\n";
	}
	else
	{
		std::cout << "SKELETON--TEST MOVE UP -> TEST PASSED: Y VALUE CORRECTLY CHANGED\n";
	}
}
void Skeleton::testMoveDown()
{
	m_yPos = 10;
	float testyPos = 10;

	//test move right
	moveDown();
	if (m_yPos == 10)
	{
		std::cout << "SKELETON--TEST MOVE DOWN -> TEST FAILED: X VALUE DID NOT CHANGE\n";
	}
	else
	{
		std::cout << "SKELETON--TEST MOVE DOWN -> TEST PASSED: Y VALUE CORRECTLY CHANGED\n";
	}
}
//attacks
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
//chasing function
void Skeleton::chasePlayer(float playerX, float playerY)
{
	bool withinX = false;
	bool withinY = false;
	float width = sprite_.getLocalBounds().width;
	float height = sprite_.getLocalBounds().height;
		if (m_xPos < (playerX - width + 10) )
		{
			Actor::sprite_.move(1.0f, 0.0f);
			this->moveRight();
		}else
		if (m_xPos > (playerX))
		{
			Actor::sprite_.move(-1.0f, 0.0f);
			this->moveLeft();
		}
		else {
			withinX = true;
		}
		if (m_yPos < (playerY - height + 5))
		{
			Actor::sprite_.move(0.0f, 1.0f);
			this->moveDown();
		}else
		if (m_yPos > (playerY - 5))
		{
			Actor::sprite_.move(0.0f, 1.0f);
			this->moveUp();
		}
		else {
			withinY = true;
		}
	if (withinX && withinY) 
	{
		this->shockWave();
	}
}
//draw to window
void Skeleton::drawTo(sf::RenderWindow & window)
{
	++framesBetweenMoves_;

	if (framesBetweenMoves_ > 100)
	{
		Actor::currentTextureIndex_ = idleTextureIndex_;
	}

	Actor::drawTo(window);
#ifdef DEBUG
	//static int count = 0;

	//if(count % 100 == 0)
	//{
	//	Rose::Logger::info("Skeleton index:", Actor::horizontalTileIndex_, ',', Actor::verticalTileIndex_);
	//	Rose::Logger::info("Skeleton Health", Actor::health_);
	//}

	//++count;
#endif 
	if(Actor::health_ <= 0)
	{
		Rose::Logger::info("SKELETON DEAD");
	}
}
//take damage
void Skeleton::damage()
{
	--Actor::health_;
}
//spritesheet loader
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
			textures_.push_back(loader);
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
			textures_.push_back(loader);
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
			textures_.push_back(loader);
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
			textures_.push_back(loader);
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
			textures_.push_back(loader);
		}
	}
 
	//Last Row: 6 characters per row

	for (int j = 0; j < 6; j++)
	{
		leftEdge = 64 * j;

		bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 1280, 64, 64));
		assert(success);
		textures_.push_back(loader);
	}
}
