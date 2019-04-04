#include "MainCharacter.h"

#pragma region Constructors
MainCharacter::MainCharacter() 
	: mainCharacter()
	, previousCharacterState(idle)
	, animationPicNumber(1)
	, dying(false)
{
	separateImageToArrayOfTextures("warrior spritesheet calciumtrice.png");
}
#pragma endregion


void MainCharacter::separateImageToArrayOfTextures(sf::String fileName) {
	sf::Texture texture;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <10; j++)
		{
			if (!texture.loadFromFile(fileName, sf::IntRect(j * 32, i * 32, 32, 32)))
			{
				printf("Could not load main character image!");
			}
			textures[(10 * i) + j] = texture;
		}
	}

	
}

void MainCharacter::drawCharacter(sf::RenderWindow& window) {

	if (!dying)
	{
		if (nextCharacterState != death)
		{
			if (nextCharacterState != attacking) {
				if (nextCharacterState != walking)
				{
					nextCharacterState = mainCharacter.getCharacterState();
				}
				else {
					if ((mainCharacter.getCharacterState() == attacking) || (mainCharacter.getCharacterState() == death))
					{
						nextCharacterState = mainCharacter.getCharacterState();
					}
				}
			}
			else {
				if (mainCharacter.getCharacterState() == death)
				{
					nextCharacterState = death;
				}
			}
		}
	}
	else {
		currentCharacterState = death;
	}
	if (currentCharacterState == death)
	{
		dying = true;
	}
	sf::Sprite sprite;
	sprite.setTexture(textures[((int(currentCharacterState) + 1)*10) + (((animationPicNumber - (animationPicNumber % 5)) / 5) - 1)]);
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
	if (currentCharacterState != walking)
	{
		animationPicNumber++;
	}
	else {
		animationPicNumber += 5;
	}
	if (animationPicNumber > 59)
	{
		if (dying)
		{
			exit(0);
		}
		else {
			animationPicNumber = 1;
			currentCharacterState = nextCharacterState;
			nextCharacterState = idle;
		}
	}

}

void MainCharacter::walkRight()
{
	mainCharacter.setCharacterState(walking);
	mainCharacter.increaseXPosition(4);
	mainCharacter.setCharacterDirectionalOrientation(true);
}

void MainCharacter::walkLeft()
{
	mainCharacter.setCharacterState(walking);
	mainCharacter.increaseXPosition(-4);
	mainCharacter.setCharacterDirectionalOrientation(false);
}

void MainCharacter::walkUp()
{
	mainCharacter.setCharacterState(walking);
	mainCharacter.increaseYPosition(-4);
}

void MainCharacter::walkDown()
{
	mainCharacter.setCharacterState(walking);
	mainCharacter.increaseYPosition(4);
}

void MainCharacter::setState(StateOfCharacter state)
{
	mainCharacter.setCharacterState(state);
}
