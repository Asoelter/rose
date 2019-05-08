#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class MainCharacterTextures
{
public:
	//std::vector<sf::Texture> textures;
	sf::Texture completeSpriteSheetTexture;
	/**
	 * @brief Construct a new Main Character Textures object
	 * 
	 * @param filename The name of the file to load textures from
	 */
	MainCharacterTextures(std::string filename);

	/**
	 * @brief Destroy the Main Character Textures object
	 * 
	 */
	~MainCharacterTextures();
};

