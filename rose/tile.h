#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#ifndef ACTOR_H
#	include "actor.h"
#endif 

class Tile
{
public:
	explicit Tile(const std::string&  fileName, const sf::Vector2f&  position);
	explicit Tile(const std::string&& fileName, const sf::Vector2f&& position);

	Tile(const Tile& other);

	virtual ~Tile() = default;

	virtual void drawTo(sf::RenderWindow& window);

	float width() const;
	float height() const;

	void setOccupier(Actor* occupier);

private:
	sf::Texture texture_;
	sf::Sprite	sprite_;
	Actor*		occupier_;
};

//--------------------------------------------------------Grassy Tile----------------------------------------------------------------

struct GrassyTile : public Tile
{
	explicit GrassyTile(const sf::Vector2f& position);
	explicit GrassyTile(const sf::Vector2f&& position);
};

//--------------------------------------------------------Sandy Tile----------------------------------------------------------------

struct SandyTile : public Tile
{
	explicit SandyTile(const sf::Vector2f& position);
	explicit SandyTile(const sf::Vector2f&& position);
};
