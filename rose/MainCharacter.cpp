#include "MainCharacter.h"

#pragma region Constructors
MainCharacter::MainCharacter() {
	mainCharacter = CharacterStats();
	previousCharacterState = idle;
	animationPicNumber = 1;
	separateImageToArrayOfTextures("warrior spritesheet calciumtrice.png");
	dying = false;
}
#pragma endregion


void MainCharacter::separateImageToArrayOfTextures(String fileName) {
	Texture texture;
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
	StateOfCharacter currentCharacterState = mainCharacter.getCharacterState();
	if (currentCharacterState == death)
	{
		dying = true;
	}
	if (previousCharacterState != currentCharacterState)
	{
		previousCharacterState = currentCharacterState;
		animationPicNumber = 1;
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
	if (currentCharacterState == 0)
	{
		animationPicNumber++;
	}
	else {
		animationPicNumber += 5;
	}
	if (animationPicNumber > 50)
	{
		if (dying)
		{
			exit(0);
		}
		else {
			animationPicNumber = 1;
		}
	}

}
