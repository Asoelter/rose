#pragma once

#include "Character.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>

using namespace sf;
class MainCharacter
{
	StateOfCharacter previousCharacterState;
	int animationPicNumber;

public:
	CharacterStats mainCharacter;
	MainCharacter();

	void drawCharacter(sf::RenderWindow& window);

};


