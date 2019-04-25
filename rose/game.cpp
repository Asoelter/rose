#include "game.h"
#include "log.h"
#include "Skeleton.h"


Game::Game()
	: window_(sf::VideoMode(1000, 600), "SFML works")
	, map_(std::make_unique<GrassyMap>(1000, 600))
	, link_(800, 300)
{
	Rose::Character::Actor::setMap(map_.get());
}


void Game::run()
{
	Skeleton skeleton; //This constructor taking a long time 
	
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				link_.moveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				link_.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				link_.moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				link_.moveLeft();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				link_.attack();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window_.close();
			}
		}

		window_.clear(sf::Color::Black);
		map_->drawTo(window_);
		link_.drawTo(window_);
		skeleton.drawTo(window_);
		window_.display();
	}

}
