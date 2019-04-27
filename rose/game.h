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
		
		void run();

	private:
		std::vector<std::unique_ptr<Skeleton>> generateEnemies(int amount);

		sf::RenderWindow		window_;
		std::unique_ptr<Map>	map_;
		Rose::Character::Link	link_;
		Rose::Character::MainCharacter	mainCharacter_;
};

#endif //GAME_H
