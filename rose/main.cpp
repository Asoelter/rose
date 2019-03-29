#include <SFML/Graphics.hpp>
#include "MainCharacter.cpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	MainCharacter mainCharacter;
	mainCharacter = MainCharacter();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		mainCharacter.drawCharacter(window);
		window.display();
	}

	return 0;
}