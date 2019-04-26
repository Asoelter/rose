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
		virtual void drawTo(sf::RenderWindow& window);


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

		void updatePosition();
		Tile* occupiedTile() const;
		std::pair<int, int> mapIndices() const;

		std::vector<sf::Texture>*	textures_;
		sf::Sprite					sprite_;
		Tile*						occupiedTile_;
		Orientation					currentOrientation_;
		int							currentTextureIndex_;
		int							horizontalTileIndex_;
		int							verticalTileIndex_;
		int							health_;
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
