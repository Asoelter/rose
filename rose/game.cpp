#ifdef FINAL
#	define CATCH_CONFIG_RUNNER
#	include "catch.hpp"
#endif
#include <algorithm>
#include "game.h"
#include "log.h"
#include <chrono>
#include "HealthBar.h"


Game::Game()
	: link_(800, 300)
	, window_(sf::VideoMode(1920, 1080), "Tale of Rose")
	, map_(std::make_unique<GrassyMap>(1920, 1080))
{
	Rose::Character::Actor::setMap(map_.get());
}

void Game::run()
{
	mainMenu();
	while(gameState != s_quit)
	{
		if (gameState == s_play) 
		{
			play();
		}
		if (gameState == s_test) 
		{
			test();
		}
		if (gameState == s_quit)
		{
			quit();
		}
		if (gameState == s_lose)
		{
			lose();
		}
		if (gameState == s_win)
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
			currentGame->link_.drawTo(currentGame->window_);
		}
			sf::sleep(sf::milliseconds(100));
	}
}

void Game::play()
{
	//Skeleton skeleton; //This constructor taking a long time 
	sf::RectangleShape tint(sf::Vector2f(1920.f, 1080.f));
	HealthBar healthBar;

	//first wave
	sf::Font font;
	font.loadFromFile("assets/impact.ttf");
	waveLabel.setFont(font);
	waveLabel.setString("WAVE 1: PRESS 'W' FOR NEXT WAVE");
	waveLabel.setColor(sf::Color(0, 0, 0));
	enemies = generateEnemies(5);
	tint.setFillColor(sf::Color(0, 0, 0, 0));

#ifdef _WIN32
	sf::Thread automateEnemies(&runAutomatedEnemies, this);
	automateEnemies.launch();
#endif 

	while (window_.isOpen() && gameState == s_play)
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
#ifdef _WIN32
					automateEnemies.terminate();
#endif
					enemies = generateEnemies(8);
#ifdef _WIN32
					automateEnemies.launch();
#endif
				}
				else if (wave == 3) {
					done = true;
				}
				else if (wave > 3) {
					//purple wave 3
					waveLabel.setString("");
					wave = 4;
					canWin = true;
					tint.setFillColor(sf::Color(200, 0, 100, 200));
#ifdef _WIN32
					automateEnemies.terminate();
#endif
					enemies = generateEnemies(15);
#ifdef _WIN32
					automateEnemies.launch();

#endif
				}
			}
		}


		window_.clear(sf::Color::Black);
		map_->drawTo(window_);
#ifdef __linux__
		moveEnemies();
#endif
		if(enemies.size() > 0)
		{
			updateEnemies();
		}

		window_.draw(tint);

		std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Skeleton>& s) 
		{
			s->drawTo(this->window_);
		});
		if (enemies.size() == 0) {
			if (wave == 4) {
				gameState = s_win;
			}
		}
		if(!link_.isAlive())
		{
			gameState = s_lose;
			Rose::Logger::warn("Link is dead");
		}
		if (gameState == s_win) {
			sf::Texture texture;
			texture.loadFromFile("assets/rose-rpg-win-screen.png");
			sf::Sprite sprite(texture);
			window_.clear(sf::Color::Black);
			window_.draw(sprite);
			window_.display();
		}
		else if (gameState == s_lose) {
			sf::Texture texture;
			texture.loadFromFile("assets/rose-rpg-lose-screen.png");
			sf::Sprite sprite(texture);
			window_.clear(sf::Color::Black);
			window_.draw(sprite);
			window_.display();
		}

		else {
			link_.drawTo(window_);
			healthBar.drawHealthBar(window_, link_);
			window_.draw(waveLabel);
			window_.display();
		}
	}
}


void Game::test()
{
#ifdef FINAL
	Catch::Session().run();
#endif
	quit();
	exit(0);
}

void Game::quit()
{
	gameState = s_quit;
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

	gameState = s_quit;
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

	gameState = s_quit;
}

void Game::moveEnemies()
{
	for(const auto& enemy : enemies)
	{
		enemy->chasePlayer(link_.xPos(), link_.yPos());
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
		texture.loadFromFile("assets/rose-rpg-main-screen.png");
		sf::Sprite sprite(texture);
		window_.clear(sf::Color::Black);
		window_.draw(sprite);
		window_.display();
	}
}


void Game::updateEnemies()
{
	using index = std::vector<Skeleton>::size_type;
	std::vector<index> removeIndices;

	for(index i = 0; i < enemies.size(); ++i)
	{
		if(!enemies[i]->isAlive())
		{
			removeIndices.push_back(i);
		}
	}

	for(index i = 0; i < removeIndices.size(); ++i)
	{
		std::swap(enemies[i], enemies.back());
		enemies.pop_back();
	}
}


std::vector<std::unique_ptr<Skeleton>> Game::generateEnemies(int amount)
{
	std::array<sf::Vector2i, 15> positions = {
		sf::Vector2i(100, 100),
		sf::Vector2i(200, 100),
		sf::Vector2i(300, 100),
		sf::Vector2i(400, 100),
		sf::Vector2i(500, 100),
		sf::Vector2i(600, 100),
		sf::Vector2i(700, 100),
		sf::Vector2i(100, 100),
		sf::Vector2i(100, 200),
		sf::Vector2i(100, 300),
		sf::Vector2i(100, 400),
		sf::Vector2i(100, 500),
		sf::Vector2i(100, 600),
		sf::Vector2i(100, 700),
		sf::Vector2i(200, 200)
	};

	std::vector<std::unique_ptr<Skeleton>> rval;

	for(int i = 0; i < amount; ++i)
	{
		rval.emplace_back(std::make_unique<Skeleton>(Skeleton(positions[i])));
	}

	return rval;
}
