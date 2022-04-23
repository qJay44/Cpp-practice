#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "Simple game");
	window.setFramerateLimit(90);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();

		window.display();
	}

	return 0;
}
