#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class MainCharacterTextures
{
public:
	//std::vector<sf::Texture> textures;
	sf::Texture completeSpriteSheetTexture;
	MainCharacterTextures(std::string filename);
	~MainCharacterTextures();
};

