#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"
#include "tile.h"
#include <vector>

#define ENABLED

auto widthOf(std::vector<GrassyTile>& tiles)
{
	return tiles[0].width() * tiles.size();
}

auto heightOf(std::vector<std::vector<GrassyTile>>& tiles)
{
	return tiles[0][0].width() * tiles.size();
}

void draw(std::vector<std::vector<GrassyTile>>& tiles, sf::RenderWindow& window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	Cowboy cowboy;
	GrassyTile tile({ 0.0f, 0.0f });
	GrassyTile tile2({500.f, 300.f});

#ifdef ENABLED
	std::vector<std::vector<GrassyTile>> tiles;
	tiles.push_back(std::vector<GrassyTile>());
	tiles[0].push_back(tile);

	float currentY = 0;
	int currentIndex = 0;

	while(heightOf(tiles) < 600)
	{
		float currentX = 0;

		do
		{
			tiles[currentIndex].emplace_back(GrassyTile({currentX, currentY}));
			currentX += tiles[0][0].width();
		}
		while(widthOf(tiles[currentIndex]) < 1000);

		tiles.emplace_back(std::vector<GrassyTile>());
		currentY += tiles[0][0].width();
		++currentIndex;
	}
#endif 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				cowboy.moveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				cowboy.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				cowboy.moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				cowboy.moveLeft();
			}
		}

		window.clear(sf::Color::Black);
		tile.drawTo(window);
		tile2.drawTo(window);
#ifdef ENABLED
		draw(tiles, window);
#endif
		cowboy.drawTo(window);
		window.display();

	}
}

void draw(std::vector<std::vector<GrassyTile>>& tiles, sf::RenderWindow& window)
{
	for(auto& row : tiles)
	{
		for(auto& col : row)
		{
			col.drawTo(window);
		}
	}
}