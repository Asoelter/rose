#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

#include "link.h"
#include "map.h"
#include "Skeleton.h"
#include "MainCharacter.h"

class Game
{
	public:
		Game();
		enum State
		{
			s_play, s_test, s_quit, s_win, s_lose, s_initial
		};

		void run();
		void mainMenu();
		void play();
		void test();
		void quit();
		void win();
		void lose();

	private:
		std::vector<std::unique_ptr<Skeleton>> generateEnemies(int amount);
		State gameState = s_initial;
		sf::RenderWindow		window_;
		std::unique_ptr<Map>	map_;
		Rose::Character::Link	link_;
		Rose::Character::MainCharacter	mainCharacter_;
};

#endif //GAME_H
