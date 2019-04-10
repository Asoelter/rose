#include "actor.h"
#include <iostream>

Actor::Actor()
	: textures_()
	, sprite_()
	, currentTextureIndex_(0)
	, occupiedTile_(nullptr)
{
}


void Actor::drawTo(sf::RenderWindow & window)
{
	sprite_.setTexture(textures_[currentTextureIndex_]);
	window.draw(sprite_);
}


float Actor::xPos() const
{
	return sprite_.getPosition().x;
}


float Actor::yPos() const
{
	return sprite_.getPosition().y;
}


void Actor::occupy(Tile* tile)
{
	occupiedTile_ = tile;
}
