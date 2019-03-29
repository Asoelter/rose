#include "Character.cpp"
#include "StateOfCharacter.h"
#include <SFML/Graphics.hpp>
class MainCharacter
{
	CharacterStats mainCharacter;
	StateOfCharacter previousCharacterState;
	int animationPicNumber;


public:
	MainCharacter() {
		mainCharacter = CharacterStats();
		previousCharacterState = idle;
		animationPicNumber = 1;
	}

	void drawCharacter(sf::RenderWindow& window) {
		StateOfCharacter currentCharacterState = mainCharacter.getCharacterState();
		if (previousCharacterState != currentCharacterState)
		{
			previousCharacterState = currentCharacterState;
			animationPicNumber = 1;
		}
		sf::Texture texture;

		if (!texture.loadFromFile("warrior spritesheet calciumtrice.png", sf::IntRect((animationPicNumber-1)*32, (int(currentCharacterState) + 1) * 32, 32, 32)))
		{
			printf("Could not load main character image!");
		}

		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);

		if (animationPicNumber>9)
		{
			animationPicNumber = 1;
		}
		else
		{
			animationPicNumber++;
		}
	}

};