#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "link.h"
#include "map.h"

class Game
{
	public:
		Game();
		
		void run();

	private:
		sf::RenderWindow		window_;
		std::unique_ptr<Map>	map_;
		Rose::Character::Link	link_;
};

#endif //GAME_H
