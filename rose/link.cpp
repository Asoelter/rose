#include "link.h"
#include <cassert>
#include <iostream>

#define BE_EXACT
//#define DEBUG

#define persistant static

std::vector<sf::Texture>	Rose::Character::Link::textures_;
bool						Rose::Character::Link::loaded_ = false;

namespace Rose::Character
{

	Link::Link(float xPos, float yPos)
		: Attacker()
		, isAttacking_(false)
	{
		Actor::textures_ = &textures_;
		if(!loaded_)
		{
			loadTextures("assets/link2.png");
			loaded_ = true;
		}
		Actor::sprite_.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
		Actor::health_ = 20;
	}

	void Link::moveUp()
	{
		genericMove(startOfWalkUp, endOfWalkUp);
		Actor::sprite_.move(0.0f, -4.0f);
		currentOrientation_ = Orientation::FACING_UP;
		Actor::updatePosition();
	}

	void Link::moveRight()
	{
		genericMove(startOfWalkRight, endOfWalkRight);
		Actor::sprite_.move(4.0f, 0.0f);
		currentOrientation_ = Orientation::FACING_RIGHT;
		Actor::updatePosition();
	}

	void Link::moveDown()
	{
		genericMove(startOfWalkDown, endOfWalkDown);
		Actor::sprite_.move(0.0f, 4.0f);
		currentOrientation_ = Orientation::FACING_DOWN;
		Actor::updatePosition();
	}

	void Link::moveLeft()
	{
		genericMove(startOfWalkLeft, endOfWalkLeft);
		Actor::sprite_.move(-4.0f, 0.0f);
		currentOrientation_ = Orientation::FACING_LEFT;
		Actor::updatePosition();
	}

	void Link::attack()
	{
		isAttacking_ = true;
		Attacker::attack();
	}

	void Link::drawTo(sf::RenderWindow& window)
	{
		if (isAttacking_)
		{
			switch (currentOrientation_)
			{
			case Orientation::FACING_UP:	 attackUp();	break;
			case Orientation::FACING_RIGHT:	 attackRight();	break;
			case Orientation::FACING_DOWN:	 attackDown();	break;
			case Orientation::FACING_LEFT:	 attackLeft();	break;
			case Orientation::IDLE:			 attackDown();	break;
			}
		}

#ifdef DEBUG
		static int count = 0;

		if (count % 100 == 0)
		{
			Actor::updatePosition();
			std::cout << "Link index: "
				<< Actor::horizontalTileIndex_ << ", "
				<< Actor::verticalTileIndex_
				<< std::endl;
		}

		++count;
#endif

		Attacker::drawTo(window);
	}


	void Link::damage()
	{
		--Actor::health_;
	}

	void Link::genericMove(int startingIndex, int endingIndex)
	{
		int& index = ++Actor::currentTextureIndex_;

		if (index < startingIndex || index > endingIndex)
		{
			index = startingIndex;
		}
	}


	void Link::genericAttack(int startingIndex, int endingIndex)
	{
		persistant bool shouldReset = true;

		++Actor::currentTextureIndex_;

		if (shouldReset)
		{
			Actor::currentTextureIndex_ = startingIndex;
			shouldReset = false;
		}

#ifdef DEBUG
		//printAttackDebugInfo();
#endif 

		if (Actor::currentTextureIndex_ >= endingIndex)
		{
			isAttacking_ = false;
			shouldReset = true;
#ifdef DEBUG
			std::cout << '\n';
#endif
		}
	}

	void Link::attackUp()
	{
		genericAttack(startOfSwordUp, endOfSwordUp);
		currentOrientation_ = Orientation::FACING_UP;
	}

	void Link::attackRight()
	{
		genericAttack(startOfSwordRight, endOfSwordRight);
		currentOrientation_ = Orientation::FACING_RIGHT;
	}

	void Link::attackDown()
	{
		genericAttack(startOfSwordDown, endOfSwordDown);
		currentOrientation_ = Orientation::FACING_DOWN;
	}

	void Link::attackLeft()
	{
		genericAttack(startOfSwordLeft, endOfSwordLeft);
		currentOrientation_ = Orientation::FACING_LEFT;
	}


	void Link::loadTextures(const std::string&& fileName)
	{
		loadWalkDownTextures(fileName);
		loadWalkLeftTextures(fileName);
		loadWalkUpTextures(fileName);
		loadWalkRightTextures(fileName);
		loadSwordDownTextures(fileName);
		loadSwordLeftTextures(fileName);
		loadSwordUpTextures(fileName);
		loadSwordRightTextures(fileName);

	}

	void Link::loadWalkDownTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

		//If BE_EXACT is defined then the exact coordinates of the texture are
		//used, otherwise a for loop is used to approximate. I'm hoping the for 
		//loop is close enough 
#ifdef BE_EXACT
		success = loader.loadFromFile(fileName, sf::IntRect(3, 31, 16, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(33, 31, 16, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(63, 30, 16, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(93, 30, 16, 24)); //IDLE
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(123, 31, 16, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(153, 30, 16, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(183, 30, 16, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(213, 30, 16, 24));
		assert(success);
		textures_.push_back(loader);
#else

		int leftEdge = 3;

		for (int i = 0; i < 8; ++i)
		{
			success = loader.loadFromFile(fileName, sf::IntRect(leftEdge, 30, 16, 24));
			assert(success);
			textures_.push_back(loader);
			leftEdge += 30;
		}
#endif
	}

	void Link::loadWalkLeftTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;
#ifdef BE_EXACT

		success = loader.loadFromFile(fileName, sf::IntRect(392, 30, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(361, 30, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(331, 30, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(301, 30, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(272, 30, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(241, 30, 19, 24));
		assert(success);
		textures_.push_back(loader);
#else
		int leftEdge = 392;

		for (int i = 0; i < 6; ++i)
		{
			success = loader.loadFromFile(fileName, sf::IntRect(leftEdge, 30, 19, 24));
			assert(success);
			textures_.push_back(loader);
			leftEdge -= 30;
		}
#endif
	}

	void Link::loadWalkUpTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

#ifdef BE_EXACT
		success = loader.loadFromFile(fileName, sf::IntRect(2, 120, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(32, 120, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(62, 121, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(92, 121, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(122, 120, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(152, 120, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(182, 121, 17, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(212, 121, 17, 24));
		assert(success);
		textures_.push_back(loader);
#else
		int leftEdge = 2;

		for (int i = 0; i < 8; ++i)
		{
			success = loader.loadFromFile(fileName, sf::IntRect(leftEdge, 120, 17, 24));
			assert(success);
			 textures_.push_back(loader);
			leftEdge += 30;
		}
#endif
	}

	void Link::loadWalkRightTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

#ifdef BE_EXACT
		success = loader.loadFromFile(fileName, sf::IntRect(241, 120, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(272, 120, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(301, 120, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(331, 120, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(361, 120, 19, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(392, 120, 19, 24));
		assert(success);
		textures_.push_back(loader);

#else
		int leftEdge = 241;

		for (int i = 0; i < 6; ++i)
		{
			success = loader.loadFromFile(fileName, sf::IntRect(leftEdge, 120, 19, 24));
			assert(success);
			 textures_.push_back(loader);
			leftEdge += 30;
		}
#endif
	}

	void Link::loadSwordDownTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

		success = loader.loadFromFile(fileName, sf::IntRect(1, 90, 20, 23));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(30, 90, 22, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(61, 86, 20, 31));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(91, 86, 20, 31));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(115, 87, 28, 29));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(145, 88, 32, 27));
		assert(success);
		textures_.push_back(loader);
	}

	void Link::loadSwordLeftTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

		success = loader.loadFromFile(fileName, sf::IntRect(359, 86, 23, 31));
		assert(success);
		 textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(327, 91, 28, 21));
		assert(success);
		 textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(295, 91, 31, 21));
		assert(success);
		 textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(268, 90, 26, 24));
		assert(success);
		 textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(242, 90, 18, 23));
		assert(success);
		textures_.push_back(loader);
	}

	void Link::loadSwordUpTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

		success = loader.loadFromFile(fileName, sf::IntRect(0, 181, 22, 22));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(30, 177, 22, 30));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(61, 174, 20, 35));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(89, 177, 24, 30));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(115, 180, 32, 23));
		assert(success);
		textures_.push_back(loader);
	}

	void Link::loadSwordRightTextures(const std::string& fileName)
	{
		sf::Texture loader;
		bool success = true;

		success = loader.loadFromFile(fileName, sf::IntRect(242, 180, 18, 23));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(268, 180, 26, 24));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(295, 181, 31, 21));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(327, 181, 28, 12));
		assert(success);
		textures_.push_back(loader);

		success = loader.loadFromFile(fileName, sf::IntRect(359, 176, 23, 31));
		assert(success);
		textures_.push_back(loader);
	}

	void Link::printAttackDebugInfo() const
	{
		std::cout << "Index = " <<  currentTextureIndex_ << " while attacking ";

		std::string word;

		switch (currentOrientation_)
		{
		case Orientation::FACING_UP:		word = "up";	break;
		case Orientation::FACING_RIGHT:		word = "right"; break;
		case Orientation::FACING_DOWN:		word = "down";	break;
		case Orientation::FACING_LEFT:		word = "left";	break;
		case Orientation::IDLE:				word = "idle";	break;
		}

		std::cout << word << std::endl;
		std::cout << "Sprite width = " << Actor::sprite_.getGlobalBounds().width << std::endl;;
	}
}
