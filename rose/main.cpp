#include "game.h"

/*void runContinuousPartOfGame() 
{
	int counter = 0;
	while (true)
	{
#	ifdef _WIN32
		//system("CLS");
#	endif 
		if (enabled) {
			if (counter % 100 == 0)
			{
				mainCharacters.push_back(MainCharacter(mainCharactersTextures.textures));
			}
			for (size i = 0; i < mainCharacters.size(); i++)
			{
				mainCharacters[i].chaseUser(link.xPos(), link.yPos());
			}
			sf::sleep(sf::milliseconds(100));
			counter++;
			skeleton.chasePlayer(link.xPos(), link.yPos());
		}
	}

}*/

//main must return int
int main()
{
	Game game;
	game.run();

	return 0;
}

