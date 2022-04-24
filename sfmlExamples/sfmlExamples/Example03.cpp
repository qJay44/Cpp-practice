#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 400), "SFML works!", Style::Default);
	window.setFramerateLimit(90);

	CircleShape circle(50.f);
	circle.setPosition(Vector2f(0.f, 0.f));

	RectangleShape rect(Vector2f(50.f, 100.f));
	rect.setPosition(Vector2f(400.f, 200.f));

	circle.setFillColor(Color(255, 115, 200, 200));
	rect.setFillColor(Color(55, 115, 200, 200));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Update
		circle.move(0.5f, 0.1f);
		circle.rotate(2.f);
		rect.move(-0.5f, -0.1f);
		rect.rotate(22.f);

		window.clear();

		// Draw everything
		window.draw(circle);
		window.draw(rect);

		window.display();
	}

	return 0;
}
