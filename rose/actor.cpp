#include "actor.h"

#include <iostream>
#include <cmath>

Map const* Actor::map = nullptr;

Actor::Actor()
	: textures_()
	, sprite_()
	, occupiedTile_(nullptr)
	, currentOrientation_(Orientation::IDLE)
	, currentTextureIndex_(0)
	, horizontaltileIndex_(0)
	, verticalTileIndex_(0)
{
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
	auto numHorizontaltiles = width  / Actor::map->tileWidth();
	auto numVerticalTiles	= height / Actor::map->tileHeight();

	horizontaltileIndex_	= std::floor(std::abs(width  - xPos()) / numHorizontaltiles);
	verticalTileIndex_		= std::floor(std::abs(height - yPos()) / numVerticalTiles);

	if(occupiedTile_)
	{
		occupiedTile_->setOccupier(nullptr);
	}

	occupiedTile_ = Actor::map->tileAt(horizontaltileIndex_, verticalTileIndex_);
	occupiedTile_->setOccupier(this);
}


Tile* Actor::occupiedTile() const
{
	return Actor::map->tileAt(horizontaltileIndex_, verticalTileIndex_);
}

std::pair<int, int> Actor::mapIndices() const
{
	return std::make_pair(horizontaltileIndex_, verticalTileIndex_);
}
