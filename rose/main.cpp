#include <SFML/Graphics.hpp>
#include "MainCharacter.cpp"
using namespace sf;

RenderWindow window(VideoMode(1000, 200), "SFML works!");
bool open = true;

int main()
{
	MainCharacter mainCharacter;
	mainCharacter = MainCharacter();
	Vector2i mousePosition;
	while (window.isOpen())
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			mousePosition = Mouse::getPosition(window);
			if (mousePosition.x > (window.getSize().x - 50) && (mousePosition.y > (window.getSize().y - 20)))
			{
				window.close();
			}
		}
		mainCharacter.mainCharacter.setCharacterState(idle);
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			mainCharacter.mainCharacter.setCharacterState(walking);
			mainCharacter.mainCharacter.increaseXPosition(-4);
			mainCharacter.mainCharacter.setCharacterDirectionalOrientation(false);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			mainCharacter.mainCharacter.setCharacterState(walking);
			mainCharacter.mainCharacter.increaseXPosition(4);
			mainCharacter.mainCharacter.setCharacterDirectionalOrientation(true);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			mainCharacter.mainCharacter.setCharacterState(walking);
			mainCharacter.mainCharacter.increaseYPosition(-4);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			mainCharacter.mainCharacter.setCharacterState(walking);
			mainCharacter.mainCharacter.increaseYPosition(4);
		}
		sf::sleep(milliseconds(5));



		window.clear();
		mainCharacter.drawCharacter(window);
		window.display();
	}

	return 0;
}
