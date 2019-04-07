#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"
#include "Skeleton.h"
#include "tile.h"
#include <vector>

#define ENABLED

Cowboy cowboy;
MainCharacter mainCharacter;
Skeleton skeleton;


void runContinuousPartOfGame() {
	while (true)
	{
		mainCharacter.chaseUser(cowboy.getXLocation(), cowboy.getYLocation());
		sf::sleep(sf::milliseconds(100));
	}
}


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
	sf::Thread thread(&runContinuousPartOfGame);
	// run it
	thread.launch();
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
			{
				skeleton.shockWave();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				cowboy.moveUp();
				skeleton.moveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				cowboy.moveRight();
				skeleton.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				cowboy.moveDown();
				skeleton.moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				cowboy.moveLeft();
				skeleton.moveLeft();
			}
		}

		window.clear(sf::Color::Black);
		tile.drawTo(window);
		tile2.drawTo(window);
#ifdef ENABLED
		draw(tiles, window);
#endif
		cowboy.drawTo(window);
		mainCharacter.drawCharacter(window);
		skeleton.drawTo(window);
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
