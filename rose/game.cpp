#define CATCH_CONFIG_RUNNER
#include <algorithm>
#include "game.h"
#include "log.h"
#include <chrono>
#include "catch.hpp"
#include "HealthBar.h"


Game::Game()
	: link_(800, 300)
	, window_(sf::VideoMode(1920, 1080), "Tale of Rose")
	, map_(std::make_unique<GrassyMap>(1920, 1080))
	, mainCharacter_(300, 200)
{
	Rose::Character::Actor::setMap(map_.get());
}


void Game::run()
{
	mainMenu();
	while(gameState != s_quit)
	{
		if (gameState == s_play) {
			play();
		}
		else if (gameState == s_test) {
			test();
		}
		else if (gameState == s_quit)
		{
			quit();
		}
		else if (gameState == s_lose)
		{
			lose();
		}
		else if (gameState == s_win)
		{
			win();
		}
	}
	


}


void runAutomatedEnemies(Game *currentGame)
{
	while (true)
	{
		for (std::vector<Skeleton>::size_type i = 0; i < currentGame->enemies.size(); i++)
		{
			currentGame->enemies[i]->chasePlayer(currentGame->link_.xPos(), currentGame->link_.yPos());
			currentGame->enemies[i]->drawTo(currentGame->window_);

		}
			sf::sleep(sf::milliseconds(100));
	}
}

void Game::play()
{
	//Skeleton skeleton; //This constructor taking a long time 
	sf::RectangleShape tint(sf::Vector2f(1000.f, 600.f));
	HealthBar healthBar;

	auto start = std::chrono::system_clock::now();
	//first wave
	sf::Font font;
	font.loadFromFile("assets/impact.ttf");
	waveLabel.setFont(font);
	waveLabel.setString("WAVE 1: PRESS 'W' FOR NEXT WAVE");
	waveLabel.setColor(sf::Color(0, 0, 0));
	enemies = generateEnemies(5);
	auto stop = std::chrono::system_clock::now();
	std::chrono::duration<double> length = stop - start;
	Rose::Logger::info("Duration:", length.count());
	tint.setFillColor(sf::Color(0, 0, 0, 0));
	sf::Thread automateEnemies(&runAutomatedEnemies, this);
	automateEnemies.launch();

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				wave++;
				if (wave == 2) {
					//blue: wave 2
					if (done == true) {
						window_.close();
					}
					waveLabel.setString("Wave 2: PRESS 'W' FOR NEXT WAVE");

					tint.setFillColor(sf::Color(0, 0, 200, 150));
					enemies = generateEnemies(8);
				}
				else if (wave == 3) {
					done = true;
				}
				else if (wave > 3) {
					//purple wave 3
					waveLabel.setString("Wave 3: PRESS 'W' TO QUIT");
					wave = 1;
					tint.setFillColor(sf::Color(200, 0, 100, 200));
					enemies = generateEnemies(15);
				}

			}
		}

		window_.clear(sf::Color::Black);
		map_->drawTo(window_);
		//skeleton.drawTo(window_);
		window_.draw(tint);
		std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Skeleton>& s) 
		{
			s->drawTo(this->window_);
		});
		mainCharacter_.drawTo(window_);
		link_.drawTo(window_);
		healthBar.drawHealthBar(window_, link_);
		window_.draw(waveLabel);
		window_.display();
	}
}
void Game::test()
{
	Catch::Session().run();
	// call all tests in here
	Skeleton skeleton; //This constructor taking a long time 
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				skeleton.runTests();
				link_.runTests();
				mainCharacter_.runTests();
			}
		}

		window_.clear(sf::Color::Black);
		link_.drawTo(window_);
		skeleton.drawTo(window_);
		mainCharacter_.drawTo(window_);
		window_.display();
	}
}
void Game::quit()
{
	window_.close();
}
void Game::win()
{
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				gameState = s_quit;
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				gameState = s_play;
				break;
			}

		}
		if(gameState != s_win)
		{
			break;
		}
		sf::Texture texture;
		texture.loadFromFile("assets/rose-rpg-win-screen.png");
		sf::Sprite sprite(texture);
		window_.clear(sf::Color::Black);
		window_.draw(sprite);
		window_.display();
	}
}
void Game::lose()
{
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				gameState = s_quit;
				window_.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				gameState = s_play;
				break;
			}

		}
		if(gameState != s_lose)
		{
			break;
		}
		sf::Texture texture;
		texture.loadFromFile("assets/rose-rpg-lose-screen.png");
		sf::Sprite sprite(texture);
		window_.clear(sf::Color::Black);
		window_.draw(sprite);
		window_.display();
	}
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
				gameState = s_play;
				window_.clear(sf::Color::Black);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
				gameState = s_test;
				window_.clear(sf::Color::Black);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				gameState = s_quit;
				window_.clear(sf::Color::Black);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				gameState = s_win;
				window_.clear(sf::Color::Black);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
				gameState = s_lose;
				window_.clear(sf::Color::Black);
				break;
			}

		}
		if (gameState != s_initial) {
			break;
		}
		
		sf::Texture texture;
		texture.loadFromFile("assets/title_screen/rose-rpg-main-screen.png");
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

	std::array<sf::Vector2i, 15> positions = {
		//wave 1
		sf::Vector2i(xMid, top),
		sf::Vector2i(right, yMid),
		sf::Vector2i(xMid, bot),
		sf::Vector2i(left, yMid),
		sf::Vector2i(xMid + 100, top + 100),
		//wave 2
		sf::Vector2i(xMid + 80, top + 200),
		sf::Vector2i(right + 160, yMid + 240),
		sf::Vector2i(xMid + 320, bot + 12),
		sf::Vector2i(left + 65, yMid + 90),
		sf::Vector2i(xMid + 50, top + 50),
		//wave 3
		sf::Vector2i(xMid + 28, top + 100),
		sf::Vector2i(right + 97, yMid + 186),
		sf::Vector2i(xMid + 145, bot + 210),
		sf::Vector2i(left + 630, yMid + 4),
		sf::Vector2i(xMid + 2, top + 112)
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
