#include "Cowboy.h"
#include <cassert>
#include <iostream>


Cowboy::Cowboy()
	: Actor()
	, framesBetweenMoves_(0)
{
	loadTexture("assets/18thCenturyAssets.png");
	Actor::sprite_.setPosition({ 500.0f, 300.0f });
}


float Cowboy::getXLocation() {
	return Actor::sprite_.getPosition().x;
}


float Cowboy::getYLocation() {
	return Actor::sprite_.getPosition().y;
}


void Cowboy::moveUp()
{
	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ > 2)
	{
		Actor::currentTextureIndex_ = 0;
	}

	Actor::sprite_.move({ 0.0f, -4.0f });
	framesBetweenMoves_ = 0;
}


void Cowboy::moveRight()
{
	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ < 3 || Actor::currentTextureIndex_ > 5)
	{
		Actor::currentTextureIndex_ = 3;
	}

	Actor::sprite_.move({ 4.0f, 0.0f });
	framesBetweenMoves_ = 0;
}


void Cowboy::moveDown()
{
	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ < 6 || Actor::currentTextureIndex_ > 8)
	{
		Actor::currentTextureIndex_ = 6;
	}

	Actor::sprite_.move({ 0.0f, 4.0f });
	framesBetweenMoves_ = 0;
}


void Cowboy::moveLeft()
{
	++Actor::currentTextureIndex_;

	if (Actor::currentTextureIndex_ < 9 || Actor::currentTextureIndex_ > 11)
	{
		Actor::currentTextureIndex_ = 9;
	}

	Actor::sprite_.move({ -4.0f, 0.0f });
	framesBetweenMoves_ = 0;
}


void Cowboy::drawTo(sf::RenderWindow & window)
{
	++framesBetweenMoves_;

	if (framesBetweenMoves_ > 100)
	{
		Actor::currentTextureIndex_ = idleTextureIndex_;
	}

	Actor::drawTo(window);
}


void Cowboy::loadTexture(const std::string && fileName)
{
	sf::Texture loader;
	for (int i = 0; i < 12; ++i)
	{
		int leftEdge = 64 * i;
		bool success = loader.loadFromFile(std::move(fileName), sf::IntRect(leftEdge, 0, 64, 60));
		assert(success);
		Actor::textures_.push_back(loader);
	}
}
