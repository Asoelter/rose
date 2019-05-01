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
		int wave = 0;
		sf::Text waveLabel;
		bool done = false;
		Game();
		/**
		* @brief enum describing the different game states
		*/
		enum State
		{
			s_play, s_test, s_quit, s_win, s_lose, s_initial
		};
		/**
		* @brief calls main menu then checks game state until in s_quit()
		*/
		void run();
		/**
		* @brief displays the main menu and changes gameState depending 
		* on user input
		*/
		/**
		* @brief begins main game loop
		*/
		void mainMenu();
		/**
		* @brief begins main game loop
		*/
		void play();
		/**
		* @brief begins test loop
		*/
		void test();
		/**
		* @brief closes main window
		*/
		void quit();
		/**
		* @brief displays win screen and allows user to press p to 
		* play again or q to quit.
		*/
		void win();
		/**
		* @brief displays lose screen and allows user to press p to 
		* play again or q to quit.
		*/
		void lose();
		void moveEnemies();


		std::vector<std::unique_ptr<Skeleton>>	enemies;
		Rose::Character::Link					link_;
		sf::RenderWindow						window_;

	private:
		std::vector<std::unique_ptr<Skeleton>> generateEnemies(int amount);

		State gameState =				s_initial;
		std::unique_ptr<Map>			map_;
		Rose::Character::MainCharacter	mainCharacter_;
};

#endif //GAME_H
