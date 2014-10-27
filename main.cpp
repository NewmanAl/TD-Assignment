#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	TextureManager* tm = new TextureManager();
	sf::Sprite s;
	s.setTexture(tm->getTexture(TextureManager::SPRITE));
	s.setScale(0.1, 0.1);
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}

		if (tm == NULL)
			cout << "AHSHIT";

		window.clear();
		window.draw(s);
		window.display();
		

	}

	delete tm;
	tm = NULL;


	return 0;
}