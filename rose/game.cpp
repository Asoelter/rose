#include <algorithm>
#include "game.h"
#include "log.h"
#include <chrono>

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

	auto start = std::chrono::system_clock::now();
	auto enemies = generateEnemies(5);
	auto stop = std::chrono::system_clock::now();
	std::chrono::duration<double> length = stop - start;
	Rose::Logger::info("Duration:", length.count());
	
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
		std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Skeleton>& s) 
		{
			s->drawTo(this->window_);
		});
		window_.display();
	}

}


std::vector<std::unique_ptr<Skeleton>> Game::generateEnemies(int amount)
{
	auto xMid	= map_->width() / 2;
	auto yMid	= map_->height() / 2;
	auto top	= 0; 
	auto bot	= map_->height();
	auto right	= map_->width();
	auto left	= 0;

	std::array<sf::Vector2i, 4> positions = {
		sf::Vector2i(xMid, top),
		sf::Vector2i(right, yMid),
		sf::Vector2i(xMid, bot),
		sf::Vector2i(left, yMid)
	};

	std::vector<std::unique_ptr<Skeleton>> rval;
	int index = 0;

	for(int i = 0; i < amount; ++i)
	{
		rval.emplace_back(std::make_unique<Skeleton>(Skeleton(positions[index])));
		index = (index + 1) % positions.size();
	}

	return rval;
}
