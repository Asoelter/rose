#include "MainCharacter.h"

#pragma region Constructors
MainCharacter::MainCharacter() {
	mainCharacter = CharacterStats();
	previousCharacterState = idle;
	animationPicNumber = 1;
}
#pragma endregion


void MainCharacter::drawCharacter(sf::RenderWindow& window) {
	StateOfCharacter currentCharacterState = mainCharacter.getCharacterState();
	if (previousCharacterState != currentCharacterState)
	{
		previousCharacterState = currentCharacterState;
		animationPicNumber = 1;
	}
	sf::Texture texture;
	if (!texture.loadFromFile("warrior spritesheet calciumtrice.png", sf::IntRect((((animationPicNumber - (animationPicNumber % 5)) / 5) - 1) * 32, (int(currentCharacterState) + 1) * 32, 32, 32)))
	{
		printf("Could not load main character image!");
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(16.f, 16.f);
	if (!mainCharacter.getCharacterDirectionalOrientation()) {
		sprite.scale(-1.f, 2.f);
	}
	else
	{
		sprite.scale(1.f, 2.f);
	}
	sprite.setPosition(mainCharacter.getXPosition(), mainCharacter.getYPosition());
	window.draw(sprite);
	if (currentCharacterState == 0)
	{
		animationPicNumber++;
	}
	else {
		animationPicNumber += 5;
	}
	if (animationPicNumber > 50)
	{
		animationPicNumber = 1;
	}
}