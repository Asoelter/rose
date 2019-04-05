#include "tile.h"
#include <cassert>


//--------------------------------------------------------Base Tile----------------------------------------------------------------


Tile::Tile(const std::string & fileName, const sf::Vector2f& position)
	: texture_()
	, sprite_()
{
	bool success = texture_.loadFromFile(fileName);
	assert(success);
	sprite_.setTexture(texture_);
	sprite_.setPosition(position);
}


Tile::Tile(const std::string && fileName, const sf::Vector2f&& position)
{
	bool success = texture_.loadFromFile(std::move(fileName));
	assert(success);
	sprite_.setTexture(texture_);
	sprite_.setPosition(std::move(position));
}


void Tile::drawTo(sf::RenderWindow & window)
{
	window.draw(sprite_);
}


float Tile::width() const
{
	return sprite_.getGlobalBounds().width;
}


float Tile::height() const
{
	return sprite_.getGlobalBounds().height;
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
