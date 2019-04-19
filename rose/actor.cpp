#include "actor.h"

#include <iostream>
#include <cmath>

#define DEBUG

Map const* Actor::map = nullptr;

Actor::Actor()
	: textures_()
	, sprite_()
	, occupiedTile_(nullptr)
	, currentOrientation_(Orientation::IDLE)
	, currentTextureIndex_(0)
	, horizontalTileIndex_(0)
	, verticalTileIndex_(0)
	, health_(0)
{
	updatePosition();
}


float Actor::xPos() const
{
	return sprite_.getPosition().x;
}


float Actor::yPos() const
{
	return sprite_.getPosition().y;
}


void Actor::drawTo(sf::RenderWindow & window)
{
	sprite_.setTexture(textures_[currentTextureIndex_]);
	window.draw(sprite_);
}


void Actor::setMap(Map* map)
{
	Actor::map = map;
}


void Actor::updatePosition()
{
	auto width				= Actor::map->width();
	auto height				= Actor::map->height();
	auto tileWdith			= Actor::map->tileWidth();
	auto tileHeight			= Actor::map->tileHeight();

	horizontalTileIndex_	= std::floor((width  - xPos()) / tileWdith);
	verticalTileIndex_		= std::floor((height - yPos()) / tileHeight);

	if(occupiedTile_)
	{
		occupiedTile_->setOccupier(nullptr);
	}

	occupiedTile_ = Actor::map->tileAt(verticalTileIndex_, horizontalTileIndex_);
	occupiedTile_->setOccupier(this);
}


Tile* Actor::occupiedTile() const
{
	return Actor::map->tileAt(horizontalTileIndex_, verticalTileIndex_);
}

std::pair<int, int> Actor::mapIndices() const
{
	return std::make_pair(horizontalTileIndex_, verticalTileIndex_);
}
