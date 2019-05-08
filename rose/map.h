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
		
		/**
		 * @brief Returns the width of the map in pixels
		 * 
		 * @return auto The width of the map in pixels
		 */
		auto width()					const {return width_;}

		/**
		 * @brief Returns the height of the map in pixels
		 * 
		 * @return auto The height of the map in pixels
		 */
		auto height()					const {return height_;}

		/**
		 * @brief Returns the width of each tile in pixels
		 * 
		 * @return auto The width of each tile in pixels
		 */
		auto tileWidth()				const {return tiles_[0][0]->width();}

		/**
		 * @brief Returns the height of each tile in pixels
		 * 
		 * @return auto The height of each tile in pixels
		 */
		auto tileHeight()				const {return tiles_[0][0]->height();}

		/**
		 * @brief Returns the number of vertical tiles
		 * 
		 * @return auto The number of vertical tiles
		 */
		auto verticalTiles()			const {return tiles_.size();}

		/**
		 * @brief Returns the number of horizontal tiles in pixels
		 * 
		 * @return auto The number of horizontal tiles in pixels 
		 */
		auto horizontalTiles()			const {return tiles_[1].size();}

		/**
		 * @brief Returns a pointer to the tile at the given indices
		 * 
		 * @param row The Vertical index of the tile
		 * 
		 * @param col The horizontal index of the tile
		 *  
		 * @return auto A pointer to the tile  
		 */
		auto tileAt(int row, int col)	const {return tiles_[row][col].get();}

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
