//#include<iostream>
//#include<vector>
//#include "MainCharacter.h"
//#include "Math.h"
//#include "ChaseUser.h"
//
//#pragma region Constructors
//MainCharacter::MainCharacter(std::vector<sf::Texture> &texturesList)
//	: animationPicNumber(1)			//This should be added 
//	, dying(false)					//in the order they're 
//	, mainCharacter()				//declared in the .h file
//{
//	textures = texturesList;
//}
//#pragma endregion
//
//
//float MainCharacter::getXLocation() {
//	return mainCharacter.getXPosition();
//}
//
//float MainCharacter::getYLocation() {
//	return mainCharacter.getYPosition();
//}
//
//void MainCharacter::drawCharacter(sf::RenderWindow& window) {
//
//	if (!dying)
//	{
//		if (nextCharacterState != death)
//		{
//			if (nextCharacterState != attacking) {
//				if (nextCharacterState != walking)
//				{
//					nextCharacterState = mainCharacter.getCharacterState();
//				}
//				else {
//					if ((mainCharacter.getCharacterState() == attacking) || (mainCharacter.getCharacterState() == death))
//					{
//						nextCharacterState = mainCharacter.getCharacterState();
//					}
//				}
//			}
//			else {
//				if (mainCharacter.getCharacterState() == death)
//				{
//					nextCharacterState = death;
//				}
//			}
//		}
//	}
//	else {
//		currentCharacterState = death;
//	}
//	if (currentCharacterState == death)
//	{
//		dying = true;
//	}
	//sf::Sprite sprite;
	//sprite.setTexture(textures[((int(currentCharacterState) + 1)*10) + (((animationPicNumber - (animationPicNumber % 5)) / 5) - 1)]);
	//sprite.setOrigin(16.f, 16.f);
	//if (!mainCharacter.getCharacterDirectionalOrientation()) {
	//	sprite.scale(-1.f, 2.f);
	//}
	//else
	//{
	//	sprite.scale(1.f, 2.f);
	//}
	//sprite.setPosition(mainCharacter.getXPosition() + 8, mainCharacter.getYPosition() + 16);
	//window.draw(sprite);
//	animationPicNumber += 5;
//	if (animationPicNumber > 59)
//	{
//		if (dying)
//		{
//			exit(0);
//		}
//		else {
//			animationPicNumber = 1;
//			currentCharacterState = nextCharacterState;
//			mainCharacter.setCharacterState(idle);
//			nextCharacterState = idle;
//		}
//	}
//
//}
//
//void MainCharacter::moveRight(float amount)
//{
//	if (amount>=1)
//	{
//		mainCharacter.setCharacterState(walking);
//	}
//	mainCharacter.increaseXPosition(amount);
//	mainCharacter.setCharacterDirectionalOrientation(true);
//}
//
//void MainCharacter::moveLeft(float amount)
//{
//	if (amount >= 1)
//	{
//		mainCharacter.setCharacterState(walking);
//	}
//	mainCharacter.increaseXPosition(-1*amount);
//	mainCharacter.setCharacterDirectionalOrientation(false);
//}
//
//void MainCharacter::moveUp(float amount)
//{
//	if (amount >= 1)
//	{
//		mainCharacter.setCharacterState(walking);
//	}
//	mainCharacter.increaseYPosition(-1*amount);
//}
//
//void MainCharacter::moveDown(float amount)
//{
//	if (amount>=1)
//	{
//		mainCharacter.setCharacterState(walking);
//	}
//	mainCharacter.increaseYPosition(amount);
//}
//
//void MainCharacter::setState(StateOfCharacter state)
//{
//	mainCharacter.setCharacterState(state);
//}
//
//
//void MainCharacter::chaseUser(float UserXPosition, float UserYPosition) {
//	std::vector<float> coordinates = getChaseUserMovementAmount(UserXPosition, 
//																UserYPosition, 
//																getXLocation(), 
//																getYLocation());
//	if (coordinates[0]>0)
//	{
//		moveRight(coordinates[0]);
//	}
//	else if (coordinates[0] < 0) {
//		moveLeft(-1 * coordinates[0]);
//	}
//	if (coordinates[1] >0)
//	{
//		moveDown(coordinates[1]);
//	}
//	else if (coordinates[1] < 0) {
//		moveUp(-1 * coordinates[1]);
//	}
//	if (coordinates[4] <17)
//	{
//		mainCharacter.setCharacterState(attacking);
//	}
//}
#include "MainCharacter.h"
#include "MainCharacterTextures.h"
#include <cassert>
#include <iostream>

#define persistant static

std::vector<sf::Texture>	Rose::Character::MainCharacter::textures_;
bool						Rose::Character::MainCharacter::loaded_ = false;

namespace Rose::Character
{

	MainCharacter::MainCharacter(float xPos, float yPos)
		: Attacker()
		, isAttacking_(false)
		, animationPicNumber(0)
	{
		currentOrientation_ = Orientation::IDLE;
		Actor::textures_ = &textures_;
		if (!loaded_)
		{
			loadTextures("assets/warrior spritesheet calciumtrice.png");
			loaded_ = true;
		}
		Actor::sprite_.setPosition(static_cast<float>(xPos), static_cast<float>(yPos));
		Actor::health_ = 20;
	}

	void MainCharacter::moveUp()
	{
		genericMove();
		Actor::sprite_.move(0.0f, -4.0f);
		Actor::updatePosition();
	}

	void MainCharacter::moveRight()
	{
		currentOrientation_ = Orientation::FACING_RIGHT;
		genericMove();
		Actor::sprite_.move(4.0f, 0.0f);
		Actor::updatePosition();
	}

	void MainCharacter::moveDown()
	{
		genericMove();
		Actor::sprite_.move(0.0f, 4.0f);
		Actor::updatePosition();
	}

	void MainCharacter::moveLeft()
	{
		currentOrientation_ = Orientation::FACING_LEFT;
		genericMove();
		Actor::sprite_.move(-4.0f, 0.0f);
		Actor::updatePosition();
	}

	void MainCharacter::attack()
	{
		isAttacking_ = true;
		Attacker::attack();
	}

	void MainCharacter::drawTo(sf::RenderWindow& window)
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

		sf::Sprite sprite;
		if (currentOrientation_ == Orientation::IDLE)
		{
			sprite.setTexture(textures_[10 + (((animationPicNumber - (animationPicNumber % 5)) / 5) - 1)]);
		}
		else
		{
			sprite.setTexture(textures_[20 + (((animationPicNumber - (animationPicNumber % 5)) / 5) - 1)]);
		}
		sprite.setOrigin(16.f, 16.f);
		if (currentOrientation_ == Orientation::FACING_LEFT) {
			sprite.scale(-1.f, 2.f);
		}
		else
		{
			sprite.scale(1.f, 2.f);
		}
		sprite.setPosition(xPos() + 8, yPos() + 16);
		window.draw(sprite);
	}


	void MainCharacter::damage()
	{
		--Actor::health_;
	}

	int MainCharacter::getHealth()
	{
		return Actor::health_;
	}

	float MainCharacter::getXPos() {
		return xPos();
	}

	float MainCharacter::getYPos() {
		return yPos();
	}

	sf::Vector2f MainCharacter::getPos() {
		return Actor::sprite_.getPosition();
	}

	void MainCharacter::animate() {
		if (animationPicNumber < 59)
		{
			animationPicNumber++;
		}
		else {
			animationPicNumber = 0;
		}
	}

	void MainCharacter::genericMove()
	{

	}


	void MainCharacter::genericAttack()
	{

	}

	void MainCharacter::attackUp()
	{
		genericAttack();
	}

	void MainCharacter::attackRight()
	{
		currentOrientation_ = Orientation::FACING_RIGHT;
		genericAttack();
	}

	void MainCharacter::attackDown()
	{
		genericAttack();
	}

	void MainCharacter::attackLeft()
	{
		currentOrientation_ = Orientation::FACING_LEFT;
		genericAttack();
	}


	void MainCharacter::loadTextures(const std::string fileName)
	{
		MainCharacterTextures textureLoader(fileName);
		textures_ = textureLoader.textures;
	}

	void MainCharacter::printAttackDebugInfo() const
	{
		std::cout << "Index = " << currentTextureIndex_ << " while attacking ";

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
