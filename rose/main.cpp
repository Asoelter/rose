#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "Cowboy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works");
	Cowboy cowboy;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				cowboy.moveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				cowboy.moveRight();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				cowboy.moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				cowboy.moveLeft();
			}
		}

		window.clear(sf::Color::Black);
		cowboy.drawTo(window);
		window.display();
	}
}

/*int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
	bool open = true;	
	MainCharacter mainCharacter;
	mainCharacter = MainCharacter();
	sf::Vector2i mousePosition;
	Cowboy cowboy;

	while (window.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mousePosition = sf::Mouse::getPosition(window);
			if (mousePosition.x > (window.getSize().x - 50) && (mousePosition.y > (window.getSize().y - 20)))
			{
				window.close();
			}
		}

		mainCharacter.setState(idle);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			mainCharacter.walkLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			mainCharacter.walkRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			mainCharacter.walkUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			mainCharacter.walkDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mainCharacter.setState(attacking);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mainCharacter.setState(death);
		}
		sf::sleep(sf::milliseconds(10));

		window.clear();
		mainCharacter.drawCharacter(window);
		cowboy.drawTo(window);
		cowboy.walkRight();
		window.display();
	}

	return 0;
}*/
