#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"
#include "Skeleton.h"
#include "tile.h"
#include <vector>
#include "link.h"
#include "map.h"

<<<<<<< HEAD
=======
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

>>>>>>> 58f91d5bcbd835c747ba7e67fe8813861522e368
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	GrassyTile tile({ 0.0f, 0.0f });
	GrassyTile tile2({500.f, 300.f});
	GrassyMap grassyMap(1000, 600);
	Link link;
	
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
<<<<<<< HEAD
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
			{

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				link.moveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				link.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				link.moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				link.moveLeft();
=======
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
>>>>>>> 58f91d5bcbd835c747ba7e67fe8813861522e368
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				link.attack();
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
		link.drawTo(window);
		window.display();
	}
}
