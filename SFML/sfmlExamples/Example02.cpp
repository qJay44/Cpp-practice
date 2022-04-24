#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 400), "SFML works!", Style::Default);
	window.setFramerateLimit(75);

	CircleShape shape(50.f);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Update
		shape.move(0.1f, 0.f);

		// Draw
		window.clear();

		// Draw everything
		window.draw(shape);

		window.display();
	}

	return 0;
}
