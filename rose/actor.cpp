#include "actor.h"
#include <iostream>

Actor::Actor()
	: textures_()
	, sprite_()
	, currentTextureIndex_(0)
{
}


void Actor::drawTo(sf::RenderWindow & window)
{
	sprite_.setTexture(textures_[currentTextureIndex_]);
	window.draw(sprite_);
}
