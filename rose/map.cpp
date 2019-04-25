#include "map.h"
#include <fstream>
#include <algorithm>
#include <iostream>


Map::Map(int width, int height)
	: tiles_()
	, width_(width)
	, height_(height)
{

}


void Map::drawTo(sf::RenderWindow& window)
{
	for(auto& row : tiles_)
	{
		for(auto& tile : row)
		{
			tile->drawTo(window);
		}
	}
}


//----------------------------------------Grassy Map-----------------------------------------------------------


GrassyMap::GrassyMap(int width, int height)
	: Map(width, height)
{
	fillMap();
}

auto widthOf(std::vector<std::unique_ptr<Tile>>& tiles)
{
	if(tiles.empty()) return 0.0f;

	return tiles[0]->width() * tiles.size();
}

auto heightOf(std::vector<std::vector<std::unique_ptr<Tile>>>& tiles)
{
	if(tiles.empty())	 return 0.0f;

	if(tiles[0].empty()) return 0.0f;

	return tiles[0][0]->width() * tiles.size();
}

void GrassyMap::fillMap()
{
	auto tile = std::make_unique<GrassyTile>(sf::Vector2f{ 0.0f, 0.0f });

	float currentY = 0;
	int currentIndex = 0;

	while(heightOf(Map::tiles_) < Map::height_)
	{
		float currentX = 0;
		Map::tiles_.emplace_back(std::vector<std::unique_ptr<Tile>>());

		do
		{
			auto tempTile = std::make_unique<GrassyTile>(sf::Vector2f{currentX, currentY});
			auto width = tempTile->width();
			Map::tiles_[currentIndex].emplace_back(std::move(tempTile));
			currentX += width;
		}
		while(widthOf(Map::tiles_[currentIndex]) < Map::width_);

		currentY += Map::tiles_[0][0]->width();
		++currentIndex;
	}
}

