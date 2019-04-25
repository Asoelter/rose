#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <ctime>

#include "Cowboy.h"
#include "link.h"
#include "MainCharacter.h"
#include "map.h"
#include "Skeleton.h"
#include "tile.h"
#include "log.h"

//TODO: Move this all to an executive class 
#include "MainCharacterTextures.h"

using size = std::vector<MainCharacter>::size_type;

std::vector<MainCharacter> mainCharacters;
MainCharacterTextures mainCharactersTextures("warrior spritesheet calciumtrice.png");
bool enabled = false;


/*void runContinuousPartOfGame() 
{
	int counter = 0;
	while (true)
	{
#	ifdef _WIN32
		//system("CLS");
#	else
		//system("clear");
#	endif 
		if (enabled) {
			if (counter % 100 == 0)
			{
				mainCharacters.push_back(MainCharacter(mainCharactersTextures.textures));
			}
			for (size i = 0; i < mainCharacters.size(); i++)
			{
				mainCharacters[i].chaseUser(link.xPos(), link.yPos());
			}
			sf::sleep(sf::milliseconds(100));
			counter++;
			skeleton.chasePlayer(link.xPos(), link.yPos());
		}
	}

}*/

int main()
{
	//sf::Thread thread(&runContinuousPartOfGame);
	//thread.launch();

	Rose::Logger::warn("This is a warning", 5, "keep going");
	Rose::Logger::error("This is an error", 5, "keep going");
	Rose::Logger::info("This is some info", 5, "keep going");
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	GrassyTile tile({ 0.0f, 0.0f });
	GrassyTile tile2({500.f, 300.f});
	GrassyMap grassyMap(1000, 600);


	Rose::Character::Actor::setMap(&grassyMap);
	Rose::Character::Link link(800, 300);
	//auto before = std::chrono::system_clock::now();
	Skeleton skeleton; //This constructor taking a long time 
	//auto after = std::chrono::system_clock::now();
	//std::chrono::duration<double> duration = after - before;
	//std::cout << "elapsed time: " << duration.count() << std::endl;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			enabled = true;
			if (event.type == sf::Event::Closed)
				window.close();
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
		for (size i = 0; i < mainCharacters.size(); i++)
		{
			mainCharacters[i].drawCharacter(window);
		}
		skeleton.drawTo(window);
		window.display();
	}

	//thread.terminate();
}

