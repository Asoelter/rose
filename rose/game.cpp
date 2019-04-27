#include <algorithm>
#include "game.h"
#include "log.h"
#include <chrono>
#include "HealthBar.h"

Game::Game()
	: window_(sf::VideoMode(1920, 1080), "Tale of Rose")
	, map_(std::make_unique<GrassyMap>(1000, 600))
	, link_(800, 300)
	, mainCharacter_(300, 200)
{
	Rose::Character::Actor::setMap(map_.get());
}


void Game::run()
{
	mainMenu();
	if (gameState == p) {
		play();
	}
	else if (gameState == t) {
		test();
	}
	else if (gameState == q)
	{
		quit();
	}


}
void Game::play()
{
	Skeleton skeleton; //This constructor taking a long time 
	HealthBar healthBar(window_);

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				link_.attack();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window_.close();
			}
		}

		window_.clear(sf::Color::Black);
		map_->drawTo(window_);
		skeleton.drawTo(window_);
<<<<<<< HEAD
		std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Skeleton>& s)
			{
				s->drawTo(this->window_);
			});
=======
		std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Skeleton>& s) 
		{
			s->drawTo(this->window_);
		});
		mainCharacter_.drawTo(window_);
>>>>>>> 05b2801a60555006676de280bb60bd25c665f1c2
		link_.drawTo(window_);
		healthBar.drawHealthBar(window_, link_);
		window_.display();
	}
}
void Game::test()
{
	// call all tests in here
}
void Game::quit()
{
	window_.close();
}
void Game::mainMenu()
{
	while (window_.isOpen())
	{	
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				gameState = p;
				window_.clear(sf::Color::Black);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
				gameState = t;
				window_.clear(sf::Color::Black);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				gameState = q;
				window_.clear(sf::Color::Black);
				break;
			}

		}
		if (gameState != w) {
			break;
		}
		
		sf::Texture texture;
		texture.loadFromFile("assets/rose-rpg-main-screen.png");
		sf::Sprite sprite(texture);
		window_.clear(sf::Color::Black);
		window_.draw(sprite);
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
