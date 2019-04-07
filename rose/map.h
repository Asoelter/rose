#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

#include "tile.h"

class Map
{
	using MapElements = std::vector<std::vector<std::unique_ptr<Tile>>> ;

	public:
		Map();
		virtual ~Map() = default;
		virtual void drawTo(sf::RenderWindow& window);

	protected:
		MapElements tiles_;
};

//------------------------------Grassy Map-----------------------------------------

class GrassyMap : public Map
{
	public:
		GrassyMap();

	private:
		void fillMap();
};

#endif //MAP_H
