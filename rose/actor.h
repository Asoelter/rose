#pragma once 

#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"

namespace Rose::Character
{
	/**
	 * @brief Base class for any character type to inherit from
	 *
	 */
	class Actor
	{
	public:
		/**
		 * @brief Construct a new Actor object
		 *
		 */
		Actor();

		/**
		 * @brief Destroy the Actor object
		 *
		 */
		virtual ~Actor() = default;

		/**
		 * @brief Moves the actor up
		 *
		 */
		virtual void moveUp() = 0;

		/**
		 * @brief Moves the actor to the right
		 *
		 */
		virtual void moveRight() = 0;

		/**
		 * @brief Moves the actor down
		 *
		 */
		virtual void moveDown() = 0;

		/**
		 * @brief Moves the actor left
		 *
		 */
		virtual void moveLeft() = 0;

		/**
		 * @brief Makes the actor take damage
		 *
		 */
		virtual void damage() = 0;

		/**
		 * @brief Returns the position of the actor in screen
		 * coordinates measured from the left side of the screen
		 *
		 * @return float the x-position of the actor
		 */
		virtual float xPos() const;

		/**
		 * @brief Returns the position of the actor in screen
		 * coordinates measured from the top of the screen
		 *
		 * @return float The y-position of the actor
		 */
		virtual float yPos() const;

		/**
		 * @brief Draws the actor to the window
		 *
		 * @param window The window to draw the actor to
		 */

		virtual float getHealth() const;

		/**
		 * @brief Get the width of the actor
		 * 
		 * @return float the width of the actor
		 */
		virtual float getActorWidth() const;

		/**
		 * @brief Get the height of the actor
		 * 
		 * @return float The height of the actor
		 */
		virtual float getActorHeight() const;

		/**
		 * @brief Draws the actor to the window
		 * 
		 * @param window The window to draw to 
		 */
		virtual void drawTo(sf::RenderWindow& window);

		/**
		 * @brief Returns whether or not the actor is still alive 
		 * 
		 * @return true The actor is alive
		 * @return false The actor is dead
		 */
		virtual bool isAlive() const;

		/**
		 * @brief Sets a pointer to the map that the actors
		 * are being displayed one
		 * 
		 * @param map The map that the actors are being displayed on 
		 */
		static void setMap(Map* map);
		static Map const *	map;

	protected:
		enum class Orientation
		{
			IDLE,
			FACING_DOWN,
			FACING_LEFT,
			FACING_UP,
			FACING_RIGHT
		};

		/**
		 * @brief Updates the characters position
		 * 
		 */
		void updatePosition();

		/**
		 * @brief Returns a pointer to the tile the 
		 * actor is occupying.
		 * 
		 * @return Tile* The tile the actor is occupying
		 */
		Tile* occupiedTile() const;

		/**
		 * @brief Returns the map indices of the tile the actor is occupying
		 * 
		 * @return std::pair<int, int> The indices of the tile the actor
		 * is occupying
		 */
		std::pair<int, int> mapIndices() const;

		sf::Texture					completeSpriteSheetTexture;
		std::vector<int>*			textureRectsDescribedByFourInts_;
		std::vector<sf::Texture>*	textures_;
		sf::Sprite					sprite_;
		Tile*						occupiedTile_;
		Orientation					currentOrientation_;
		int							currentTextureIndex_;
		int							horizontalTileIndex_;
		int							verticalTileIndex_;
		int							health_;
		bool						isAlive_;
	};
}

/*
#define CHARACTER_CLASS()			private:\
									static std::vector<sf::Texture> textures;\
									static bool loaded;

#define REGISTER_CHARACTER_CLASS()	loaded = true;

#define REGISTER_TEXTURE(texture)	if(!loaded)\
									{\
										textures.push_back(texture);\
									}\
									*/
