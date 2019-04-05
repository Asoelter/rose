#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Tile
{
public:
	explicit Tile(const std::string&  fileName, const sf::Vector2f&  position);
	explicit Tile(const std::string&& fileName, const sf::Vector2f&& position);

	virtual ~Tile() = default;

	virtual void drawTo(sf::RenderWindow& window);

	float width() const;
	float height() const;

private:
	sf::Texture texture_;
	sf::Sprite	sprite_;
};

//--------------------------------------------------------Grassy Tile----------------------------------------------------------------

struct GrassyTile : public Tile
{
	explicit GrassyTile(const sf::Vector2f& position);
	explicit GrassyTile(const sf::Vector2f&& position);
};