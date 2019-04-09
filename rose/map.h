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
		Map(int width, int height);
		virtual ~Map() = default;
		virtual void drawTo(sf::RenderWindow& window);

	protected:
		MapElements tiles_;
		int width_;
		int height_;
};

//------------------------------Grassy Map-----------------------------------------

class GrassyMap : public Map
{
	public:
		GrassyMap(int width, int height);

	private:
		void fillMap();
};

#endif //MAP_H
