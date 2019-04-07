#pragma once
#include <iostream>
#include "CharacterStats.h"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class MainCharacter
{
	//StateOfCharacter previousCharacterState; //this was unused so i removed it
	int animationPicNumber;
	std::vector<Texture> textures;
	bool dying;
	CharacterStats mainCharacter;
	StateOfCharacter currentCharacterState;
	StateOfCharacter nextCharacterState;

public:
	MainCharacter();
	void separateImageToArrayOfTextures(const std::string& filename);
	void drawCharacter(sf::RenderWindow& window);

	float getXLocation();
	float getYLocation();
	void walkRight(float amount);
	void walkLeft(float amount);
	void walkUp(float amount);
	void walkDown(float amount);
	void chaseUser(float UserXPosition, float UserYPosition);
	void setState(StateOfCharacter state);
};


