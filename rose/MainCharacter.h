#pragma once

#include "CharacterStats.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>

class MainCharacter
{
	StateOfCharacter previousCharacterState;
	int animationPicNumber;
	sf::Texture textures[100];
	bool dying;
	CharacterStats mainCharacter;

public:
	MainCharacter();

	void separateImageToArrayOfTextures(sf::String fileName);
	void drawCharacter(sf::RenderWindow& window);

	void walkRight();
	void walkLeft();
	void walkUp();
	void walkDown();
	void setState(StateOfCharacter state);
};


