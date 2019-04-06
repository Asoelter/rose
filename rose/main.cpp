#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"
#include "tile.h"
#include "skeleton.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	Cowboy cowboy;
	skeleton skeleton1;
	//GrassyTile tile({ 500.0f, 300.0f });
	GrassyTile tile({ 0.0f, 0.0f });

	std::cout << tile.width() << std::endl;

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
		cowboy.drawTo(window);
		skeleton1.drawTo(window);
		skeleton1.idle();
		window.display();
	}
}

