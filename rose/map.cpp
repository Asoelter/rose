#include "map.h"
#include <fstream>
#include <algorithm>
#include <iostream>


Map::Map()
	: tiles_()
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


GrassyMap::GrassyMap()
	: Map()
{
	fillMap();
}

auto widthOf(std::vector<std::unique_ptr<Tile>>& tiles)
{
	return tiles[0]->width() * tiles.size();
}

auto heightOf(std::vector<std::vector<std::unique_ptr<Tile>>>& tiles)
{
	return tiles[0][0]->width() * tiles.size();
}

void GrassyMap::fillMap()
{
	Map::tiles_.push_back(std::vector<std::unique_ptr<Tile>>());
	auto tile = std::make_unique<GrassyTile>(sf::Vector2f{ 0.0f, 0.0f });
	Map::tiles_[0].emplace_back(std::move(tile));

	float currentY = 0;
	int currentIndex = 0;

	while(heightOf(Map::tiles_) < 600)
	{
		float currentX = 0;

		do
		{
			std::unique_ptr<Tile> tempTile;

			if(currentIndex % 2 == 0)
			{
				tempTile = std::make_unique<GrassyTile>(sf::Vector2f{currentX, currentY});
			}
			else
			{
				tempTile = std::make_unique<SandyTile>(sf::Vector2f{currentX, currentY});
			}
			Map::tiles_[currentIndex].emplace_back(std::move(tempTile));
			currentX += Map::tiles_[0][0]->width();
		}
		while(widthOf(Map::tiles_[currentIndex]) < 1000);

		Map::tiles_.emplace_back(std::vector<std::unique_ptr<Tile>>());
		currentY += Map::tiles_[0][0]->width();
		++currentIndex;
	}
}

