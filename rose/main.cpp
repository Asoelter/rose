#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"
#include "tile.h"
#include <vector>
#include "link.h"
#include "map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	Link cowboy;
	GrassyTile tile({ 0.0f, 0.0f });
	GrassyTile tile2({500.f, 300.f});
	GrassyMap grassyMap;
	
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
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				cowboy.attack();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		tile.drawTo(window);
		tile2.drawTo(window);
		grassyMap.drawTo(window);
		cowboy.drawTo(window);
		window.display();

	}
}
