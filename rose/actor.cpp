#include "actor.h"

#include <iostream>
#include <cmath>
#include <cassert>

#define DEBUG

namespace Rose::Character
{
	Map const* Actor::map = nullptr;

	Actor::Actor()
		: completeSpriteSheetTexture()
		, textureRectsDescribedByFourInts_()
		, textures_(nullptr)
		, sprite_()
		, occupiedTile_(nullptr)
		, currentOrientation_(Orientation::IDLE)
		, currentTextureIndex_(0)
		, horizontalTileIndex_(0)
		, verticalTileIndex_(0)
		, health_(0)
		, isAlive_(true)
	{
		if(map)
		{
			updatePosition();
		}
	}


	float Actor::xPos() const
	{
		return sprite_.getPosition().x;
	}


	float Actor::yPos() const
	{
		return sprite_.getPosition().y;
	}


	float Actor::getActorWidth() const
	{
		return 	sprite_.getLocalBounds().width;
	}


	float Actor::getActorHeight() const
	{
		return 	sprite_.getLocalBounds().height;
	}


	float Actor::getHealth() const 
	{
		return health_;
	}


	void Actor::drawTo(sf::RenderWindow & window)
	{
		Actor::updatePosition();
		if (textures_ != nullptr) {
			sprite_.setTexture((*textures_)[currentTextureIndex_]);
			window.draw(sprite_);
		}
		else{
			//sf::Sprite sprite;
			sprite_.setTexture(completeSpriteSheetTexture);
			sprite_.setTextureRect(sf::IntRect((*textureRectsDescribedByFourInts_)[4 * currentTextureIndex_], 
						(*textureRectsDescribedByFourInts_)[4 * currentTextureIndex_ + 1],
						(*textureRectsDescribedByFourInts_)[4 * currentTextureIndex_ + 2], 
						(*textureRectsDescribedByFourInts_)[4 * currentTextureIndex_ + 3]));
			window.draw(sprite_);
		}

		if(health_ <= 0)
		{
			isAlive_ = false;
		}

	}

	
	bool Actor::isAlive() const
	{
		return isAlive_;
	}


	void Actor::setMap(Map* map)
	{
		Actor::map = map;
	}


	void Actor::updatePosition()
	{
		
		auto width		= Actor::map->width();
		auto height		= Actor::map->height();
		auto tileWdith	= Actor::map->tileWidth();
		auto tileHeight = Actor::map->tileHeight();

		horizontalTileIndex_ = map->horizontalTiles() - std::floor((width - xPos()) / tileWdith);
		verticalTileIndex_	 = map->verticalTiles() - std::floor((height - yPos()) / tileHeight);

		if (occupiedTile_)
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
		return std::make_pair(verticalTileIndex_, horizontalTileIndex_);
	}
}
