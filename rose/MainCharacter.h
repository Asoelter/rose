#pragma once

#include "CharacterStats.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>
#include <string>

class MainCharacter
{
	//StateOfCharacter previousCharacterState; //this was unused so i removed it
	int animationPicNumber;
	sf::Texture textures[100];
	bool dying;
	CharacterStats mainCharacter;
	StateOfCharacter currentCharacterState;
	StateOfCharacter nextCharacterState;

public:
	MainCharacter();

	void separateImageToArrayOfTextures(std::string fileName);
	void drawCharacter(sf::RenderWindow& window);

	void walkRight();
	void walkLeft();
	void walkUp();
	void walkDown();
	void setState(StateOfCharacter state);
};


