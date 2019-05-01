#include "tile.h"
#include <cassert>

#include <iostream>



//--------------------------------------------------------Base Tile----------------------------------------------------------------


Tile::Tile(const std::string & fileName, const sf::Vector2f& position)
	: texture_()
	, sprite_()
	, occupier_(nullptr)
{
	bool success = texture_.loadFromFile(fileName);
	assert(success);
	sprite_.setTexture(texture_);
	sprite_.setPosition(position);
}


Tile::Tile(const std::string && fileName, const sf::Vector2f&& position)
	: texture_()
	, sprite_()
	, occupier_(nullptr)
{
	bool success = texture_.loadFromFile(std::move(fileName));
	assert(success);
	sprite_.setTexture(texture_);
	sprite_.setPosition(std::move(position));
}

Tile::Tile(const Tile& other)
	: texture_(other.texture_)
{
	sprite_.setTexture(texture_);
	auto xPos = other.sprite_.getPosition().x;
	auto yPos = other.sprite_.getPosition().y;
	sprite_.setPosition({xPos, yPos});
}

void Tile::drawTo(sf::RenderWindow & window)
{
	window.draw(sprite_);
}


void Tile::setColor(sf::Color color)
{
	sprite_.setColor(color);
}


float Tile::width() const
{
	return sprite_.getGlobalBounds().width;
}


float Tile::height() const
{
	return sprite_.getGlobalBounds().height;
}

void Tile::setOccupier(Rose::Character::Actor* occupier)
{
	occupier_ = occupier;
}


Rose::Character::Actor* Tile::occupier()
{
	return occupier_;
}


//--------------------------------------------------------Grassy Tile----------------------------------------------------------------


GrassyTile::GrassyTile(const sf::Vector2f & position)
	: Tile("assets/rpg_pack/tiles/generic-rpg-tile01.png", position)
{
	
}


GrassyTile::GrassyTile(const sf::Vector2f && position)
	: Tile("assets/rpg_pack/tiles/generic-rpg-tile01.png", std::move(position))
{

}


//--------------------------------------------------------Grassy Tile----------------------------------------------------------------

SandyTile::SandyTile(const sf::Vector2f& position)
	: Tile("assets/rpg_pack/tiles/generic-rpg-tile02.png", position)
{

}


SandyTile::SandyTile(const sf::Vector2f&& position)
	: Tile("assets/rpg_pack/tiles/generic-rpg-tile02.png", std::move(position))
{

}
