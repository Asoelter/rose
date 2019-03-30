#pragma once

#include "Character.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>

using namespace sf;
class MainCharacter
{
	StateOfCharacter previousCharacterState;
	int animationPicNumber;
	Texture textures[100];
	bool dying;
public:
	CharacterStats mainCharacter;
	MainCharacter();

	void separateImageToArrayOfTextures(String fileName);
	void drawCharacter(sf::RenderWindow& window);


};


