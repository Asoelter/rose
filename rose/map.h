#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

#include "tile.h"

/**
 * @brief A Base class for all other map classes to inherit from 
 * 
 */
class Map
{
	using MapElements = std::vector<std::vector<std::unique_ptr<Tile>>> ;

	public:
		/**
		 * @brief Construct a new Map object
		 * 
		 * @param width  The width  of the map in pixels
		 * @param height The height of the map in pixels
		 */
		Map(int width, int height);

		/**
		 * @brief Destroy the Map object
		 * 
		 */
		virtual ~Map() = default;

		/**
		 * @brief Draws the map to the window
		 * 
		 * @param window The window to draw the map to
		 */
		virtual void drawTo(sf::RenderWindow& window);
		
		constexpr auto width()  const {return width_;}
		constexpr auto height() const {return height_;}

		constexpr auto tileWidth()  const {return tiles_[0][0]->width();}
		constexpr auto tileHeight() const {return tiles_[0][0]->height();}

		auto tileAt(int row, int col) const {return tiles_[row][col].get();}

	protected:
		MapElements tiles_;
		int			width_;
		int			height_;
};

//------------------------------Grassy Map-----------------------------------------

/**
 * @brief Implements Map, Displays all grassy tiles
 * 
 */
class GrassyMap : public Map
{
	public:
		/**
		 * @brief Construct a new Grassy Map object
		 * 
		 * @param width  width  The width  of the map in pixels
		 * @param height height The height of the map in pixels
		 */
		GrassyMap(int width, int height);

	private:
		/**
		 * @brief Fills the map with tiles
		 * 
		 */
		void fillMap();
};

#endif //MAP_H
