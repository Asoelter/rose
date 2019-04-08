#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"
#include "Skeleton.h"
#include "tile.h"
#include <vector>
#include "link.h"
#include "map.h"

using size = std::vector<MainCharacter>::size_type;

Link cowboy;
std::vector<MainCharacter> mainCharacters;
Skeleton skeleton;




void runContinuousPartOfGame() {
	int counter = 0;
	while (true)
	{
		if (counter%100==0)
		{
			mainCharacters.push_back(MainCharacter());
		}
		for (size i = 0; i < mainCharacters.size(); i++)
		{
			mainCharacters[i].chaseUser(cowboy.getXLocation(), cowboy.getYLocation());
		}
		sf::sleep(sf::milliseconds(100));
		counter++;
		skeleton.chasePlayer(cowboy.getXLocation(), cowboy.getYLocation());
	}

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	GrassyTile tile({ 0.0f, 0.0f });
	GrassyTile tile2({500.f, 300.f});
	GrassyMap grassyMap;
	sf::Thread thread(&runContinuousPartOfGame);
	thread.launch();

	
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
		for (size i = 0; i < mainCharacters.size(); i++)
		{
			mainCharacters[i].drawCharacter(window);
		}
		skeleton.drawTo(window);
		window.display();

	}

	thread.terminate();
}
