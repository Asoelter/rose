#include "MainCharacterTextures.h"



MainCharacterTextures::MainCharacterTextures(std::string filename)
{
	sf::Image completeSpriteSheet;
	completeSpriteSheet.loadFromFile(filename);
	completeSpriteSheetTexture.loadFromImage(completeSpriteSheet);
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			sf::Texture texture;
//			texture.loadFromImage(completeSpriteSheet, sf::IntRect(j * 32, i * 32, 32, 32));
//			textures.push_back(texture); // error thrown here, does not seems to effect anything
//#ifdef _WIN32
//			system("CLS");
//#endif 
//		}
//	}
}


MainCharacterTextures::~MainCharacterTextures()
{
}
