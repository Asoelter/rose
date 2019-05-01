#pragma once

#include <string>

#include <SFML/Graphics.hpp>

//#include "actor.h"
namespace Rose::Character
{
	class Actor;
}

class Tile
{
public:
	/**
	 * @brief Construct a new Tile object
	 * 
	 * @param fileName The name of the file to load the texture from 
	 * @param position A vector that contains the screen coordinates
	 * to display the tile at
	 */
	explicit Tile(const std::string&  fileName, const sf::Vector2f&  position);

	/**
	 * @brief Construct a new Tile object
	 * 
	 * @param fileName The name of the file to load the texture from 
	 * @param position A vector that contains the screen coordinates
	 * to display the tile at
	 */
	explicit Tile(const std::string&& fileName, const sf::Vector2f&& position);

	/**
	 * @brief Construct a new Tile object
	 * 
	 * @param other The tile object to copy from 
	 */
	Tile(const Tile& other);

	/**
	 * @brief Destroy the Tile object
	 * 
	 */
	virtual ~Tile() = default;

	/**
	 * @brief Draws the tile to the window 
	 * 
	 * @param window The window to draw the tile to
	 */
	virtual void drawTo(sf::RenderWindow& window);
	virtual void setColor(sf::Color color);

	/**
	 * @brief Returns the width of the tile in pixels 
	 * 
	 * @return float The width of the tile in pixels
	 */
	float width() const;

	/**
	 * @brief Returns the height of the tile in pixels 
	 * 
	 * @return float The height of the tile in pixels
	 */
	float height() const;

	/**
	 * @brief Set the Occupier Actor. (Not currently implemented)
	 * 
	 * @param occupier The actor that is occupying the tile 
	 */
	void setOccupier(Rose::Character::Actor* occupier);

	Rose::Character::Actor* occupier();

private:
	sf::Texture					texture_;
	sf::Sprite					sprite_;
	Rose::Character::Actor*		occupier_;
};

//--------------------------------------------------------Grassy Tile----------------------------------------------------------------

struct GrassyTile : public Tile
{
	/**
	 * @brief Construct a new Grassy Tile object
	 * 
	 * @param position The position to display the
	 * tile at 
	 */
	explicit GrassyTile(const sf::Vector2f& position);

	/**
	 * @brief Construct a new Grassy Tile object
	 * 
	 * @param position The position to display the
	 * tile at 
	 */
	explicit GrassyTile(const sf::Vector2f&& position);
};

//--------------------------------------------------------Sandy Tile----------------------------------------------------------------

struct SandyTile : public Tile
{
	/**
	 * @brief Construct a new Sandy Tile object
	 * 
	 * @param position The position to display the
	 * tile at 
	 */
	explicit SandyTile(const sf::Vector2f& position);

	/**
	 * @brief Construct a new Sandy Tile object
	 * 
	 * @param position The position to display the
	 * tile at 
	 */
	explicit SandyTile(const sf::Vector2f&& position);
};
