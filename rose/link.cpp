#include "link.h"
#include <cassert>
#include <iostream>
#include "log.h"

#define persistant static

std::vector<int>	Rose::Character::Link::textureRectsDescribedByFourInts_;
bool						Rose::Character::Link::loaded_ = false;

namespace Rose::Character
{

	Link::Link(float xPos, float yPos)
		: Attacker()
		, isAttacking_(false)
	{
		Actor::textureRectsDescribedByFourInts_ = &textureRectsDescribedByFourInts_;
		if(!loaded_)
		{
			completeSpriteSheet.loadFromFile("assets/link2.png");
			sf::Texture texture;
			texture.loadFromImage(completeSpriteSheet);
			Actor::completeSpriteSheetTexture = texture;
			loadTextures();
			loaded_ = true;
		}
		Actor::sprite_.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
		Actor::health_ = 100;
	}


	Link::~Link()
	{
		Actor::occupiedTile_->setOccupier(nullptr);
	}


	void Link::moveUp()
	{
		genericMove(startOfWalkUp, endOfWalkUp);
		if (getYPos() > minY) {
			Actor::sprite_.move(0.0f, -4.0f);
		}
		currentOrientation_ = Orientation::FACING_UP;
		Actor::updatePosition();
	}

	void Link::moveRight()
	{
		if (getXPos() < maxX) {
			Actor::sprite_.move(4.0f, 0.0f);
		}
		genericMove(startOfWalkRight, endOfWalkRight);
		currentOrientation_ = Orientation::FACING_RIGHT;
		Actor::updatePosition();
	}

	void Link::moveDown()
	{
		genericMove(startOfWalkDown, endOfWalkDown);
		if (getYPos() < maxY) {
			Actor::sprite_.move(0.0f, 4.0f);
		}
		currentOrientation_ = Orientation::FACING_DOWN;
		Actor::updatePosition();
	}

	void Link::moveLeft()
	{
		genericMove(startOfWalkLeft, endOfWalkLeft);
		if (getXPos() > minX) {
			Actor::sprite_.move(-4.0f, 0.0f);
		}
		
		currentOrientation_ = Orientation::FACING_LEFT;
		Actor::updatePosition();
	}

	void Link::runTests()
	{
		testMoveDown();
		testMoveLeft();
		testMoveUp();
		testMoveRight();
	}
	void Link::testMoveDown()
	{
		float testPos = getYPos();
		moveDown();
		if(testPos == getYPos())
		{
			std::cout << "LINK--TEST MOVE DOWN -> TEST FAILED: Y VALUE DID NOT CHANGE\n";
		}
		else
		{
			std::cout << "LINK--TEST MOVE DOWN -> TEST PASSED: Y VALUE CORRECTLY CHANGED\n";
		}
	}
	void Link::testMoveLeft() 
	{
		float testPos = getXPos();
		moveLeft();
		if (testPos == getXPos())
		{
			std::cout << "LINK--TEST MOVE LEFT -> TEST FAILED: X VALUE DID NOT CHANGE\n";
		}
		else
		{
			std::cout << "LINK--TEST MOVE LEFT -> TEST PASSED: X VALUE CORRECTLY CHANGED\n";
		}
	}
	void Link::testMoveUp()
	{
		float testPos = getYPos();
		moveUp();
		if (testPos == getYPos())
		{
			std::cout << "LINK--TEST MOVE UP -> TEST FAILED: Y VALUE DID NOT CHANGE\n";
		}
		else
		{
			std::cout << "LINK--TEST MOVE UP -> TEST PASSED: Y VALUE CORRECTLY CHANGED\n";
		}
	}
	void Link::testMoveRight()
	{
		float testPos = getXPos();
		moveRight();
		if (testPos == getXPos())
		{
			std::cout << "LINK--TEST MOVE RIGHT -> TEST FAILED: X VALUE DID NOT CHANGE\n";
		}
		else
		{
			std::cout << "LINK--TEST MOVE RIGHT -> TEST PASSED: X VALUE CORRECTLY CHANGED\n";
		}
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

		if(health_ <= 0)
		{
			Rose::Logger::info("LINK IS DEAD");
		}

		Attacker::drawTo(window);
	}


	void Link::damage()
	{
		--Actor::health_;
	}

	int Link::getHealth()
	{
		return Actor::health_;
	}

	float Link::getXPos(){
		return xPos();
	}

	float Link::getYPos(){
		return yPos();
	}

	//sf::Vector2f Link::getPos() {
	//	return Actor::sprite_.getPosition();
	//}

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

		if (Actor::currentTextureIndex_ >= endingIndex)
		{
			isAttacking_ = false;
			shouldReset = true;
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


	void Link::loadTextures()
	{
		loadWalkDownTextures();
		loadWalkLeftTextures();
		loadWalkUpTextures();
		loadWalkRightTextures();
		loadSwordDownTextures();
		loadSwordLeftTextures();
		loadSwordUpTextures();
		loadSwordRightTextures();

	}

	void Link::loadWalkDownTextures()
	{

		//If BE_EXACT is defined then the exact coordinates of the texture are
		//used, otherwise a for loop is used to approximate. I'm hoping the for 
		//loop is close enough 
		textureRectsDescribedByFourInts_.push_back(3);
		textureRectsDescribedByFourInts_.push_back(31);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);


		textureRectsDescribedByFourInts_.push_back(33);
		textureRectsDescribedByFourInts_.push_back(31);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);


		textureRectsDescribedByFourInts_.push_back(63);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(93);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(123);
		textureRectsDescribedByFourInts_.push_back(31);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(153);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(183);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(213);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(16);
		textureRectsDescribedByFourInts_.push_back(24);
	}

	void Link::loadWalkLeftTextures()
	{
		textureRectsDescribedByFourInts_.push_back(392);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(361);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(331);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(301);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(272);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(241);
		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);
	}

	void Link::loadWalkUpTextures()
	{
		textureRectsDescribedByFourInts_.push_back(2);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(32);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);;

		textureRectsDescribedByFourInts_.push_back(62);
		textureRectsDescribedByFourInts_.push_back(121);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(92);
		textureRectsDescribedByFourInts_.push_back(121);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(122);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(152);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(182);
		textureRectsDescribedByFourInts_.push_back(121);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(212);
		textureRectsDescribedByFourInts_.push_back(121);
		textureRectsDescribedByFourInts_.push_back(17);
		textureRectsDescribedByFourInts_.push_back(24);
	}

	void Link::loadWalkRightTextures()
	{
		textureRectsDescribedByFourInts_.push_back(241);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(272);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(301);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(331);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(361);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(392);
		textureRectsDescribedByFourInts_.push_back(120);
		textureRectsDescribedByFourInts_.push_back(19);
		textureRectsDescribedByFourInts_.push_back(24);
	}

	void Link::loadSwordDownTextures()
	{
		textureRectsDescribedByFourInts_.push_back(1);
		textureRectsDescribedByFourInts_.push_back(90);
		textureRectsDescribedByFourInts_.push_back(20);
		textureRectsDescribedByFourInts_.push_back(23);

		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(90);
		textureRectsDescribedByFourInts_.push_back(22);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(61);
		textureRectsDescribedByFourInts_.push_back(86);
		textureRectsDescribedByFourInts_.push_back(20);
		textureRectsDescribedByFourInts_.push_back(31);

		textureRectsDescribedByFourInts_.push_back(91);
		textureRectsDescribedByFourInts_.push_back(86);
		textureRectsDescribedByFourInts_.push_back(20);
		textureRectsDescribedByFourInts_.push_back(31);

		textureRectsDescribedByFourInts_.push_back(115);
		textureRectsDescribedByFourInts_.push_back(87);
		textureRectsDescribedByFourInts_.push_back(28);
		textureRectsDescribedByFourInts_.push_back(29);

		textureRectsDescribedByFourInts_.push_back(145);
		textureRectsDescribedByFourInts_.push_back(88);
		textureRectsDescribedByFourInts_.push_back(32);
		textureRectsDescribedByFourInts_.push_back(27);
	}

	void Link::loadSwordLeftTextures()
	{
		textureRectsDescribedByFourInts_.push_back(359);
		textureRectsDescribedByFourInts_.push_back(86);
		textureRectsDescribedByFourInts_.push_back(23);
		textureRectsDescribedByFourInts_.push_back(31);

		 textureRectsDescribedByFourInts_.push_back(327);
		 textureRectsDescribedByFourInts_.push_back(91);
		 textureRectsDescribedByFourInts_.push_back(28);
		 textureRectsDescribedByFourInts_.push_back(21);

		 textureRectsDescribedByFourInts_.push_back(295);
		 textureRectsDescribedByFourInts_.push_back(91);
		 textureRectsDescribedByFourInts_.push_back(31);
		 textureRectsDescribedByFourInts_.push_back(21);

		 textureRectsDescribedByFourInts_.push_back(268);
		 textureRectsDescribedByFourInts_.push_back(90);
		 textureRectsDescribedByFourInts_.push_back(26);
		 textureRectsDescribedByFourInts_.push_back(24);

		 textureRectsDescribedByFourInts_.push_back(242);
		 textureRectsDescribedByFourInts_.push_back(90);
		 textureRectsDescribedByFourInts_.push_back(18);
		 textureRectsDescribedByFourInts_.push_back(23);
	}

	void Link::loadSwordUpTextures()
	{
		textureRectsDescribedByFourInts_.push_back(0);
		textureRectsDescribedByFourInts_.push_back(181);
		textureRectsDescribedByFourInts_.push_back(22);
		textureRectsDescribedByFourInts_.push_back(22);

		textureRectsDescribedByFourInts_.push_back(30);
		textureRectsDescribedByFourInts_.push_back(177);
		textureRectsDescribedByFourInts_.push_back(22);
		textureRectsDescribedByFourInts_.push_back(30);

		textureRectsDescribedByFourInts_.push_back(61);
		textureRectsDescribedByFourInts_.push_back(174);
		textureRectsDescribedByFourInts_.push_back(20);
		textureRectsDescribedByFourInts_.push_back(35);

		textureRectsDescribedByFourInts_.push_back(89);
		textureRectsDescribedByFourInts_.push_back(177);
		textureRectsDescribedByFourInts_.push_back(24);
		textureRectsDescribedByFourInts_.push_back(30);

		textureRectsDescribedByFourInts_.push_back(115);
		textureRectsDescribedByFourInts_.push_back(180);
		textureRectsDescribedByFourInts_.push_back(32);
		textureRectsDescribedByFourInts_.push_back(23);
	}

	void Link::loadSwordRightTextures()
	{
		textureRectsDescribedByFourInts_.push_back(242);
		textureRectsDescribedByFourInts_.push_back(180);
		textureRectsDescribedByFourInts_.push_back(18);
		textureRectsDescribedByFourInts_.push_back(23);

		textureRectsDescribedByFourInts_.push_back(268);
		textureRectsDescribedByFourInts_.push_back(180);
		textureRectsDescribedByFourInts_.push_back(28);
		textureRectsDescribedByFourInts_.push_back(26);

		textureRectsDescribedByFourInts_.push_back(295);
		textureRectsDescribedByFourInts_.push_back(181);
		textureRectsDescribedByFourInts_.push_back(35);
		textureRectsDescribedByFourInts_.push_back(25);

		textureRectsDescribedByFourInts_.push_back(327);
		textureRectsDescribedByFourInts_.push_back(181);
		textureRectsDescribedByFourInts_.push_back(33);
		textureRectsDescribedByFourInts_.push_back(24);

		textureRectsDescribedByFourInts_.push_back(359);
		textureRectsDescribedByFourInts_.push_back(176);
		textureRectsDescribedByFourInts_.push_back(25);
		textureRectsDescribedByFourInts_.push_back(35);
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
