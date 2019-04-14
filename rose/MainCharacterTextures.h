#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class MainCharacterTextures
{
public:
	std::vector<sf::Texture> textures;
	MainCharacterTextures(std::string filename);
	~MainCharacterTextures();
};

