#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

#include "link.h"
#include "map.h"
#include "Skeleton.h"

class Game
{
	public:
		Game();
		enum State
		{
			p, t, q, w
		};

		void run();
		void mainMenu();
		void play();
		void test();
		void quit();

	private:
		std::vector<std::unique_ptr<Skeleton>> generateEnemies(int amount);
		State gameState = w;
		sf::RenderWindow		window_;
		std::unique_ptr<Map>	map_;
		Rose::Character::Link	link_;
};

#endif //GAME_H
