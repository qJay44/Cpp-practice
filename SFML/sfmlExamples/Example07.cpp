#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 480), "Simple game");
	window.setFramerateLimit(90);

	CircleShape hoop;
	int dir = 0;
	hoop.setRadius(50.f);
	hoop.setFillColor(Color::White);
	hoop.setOutlineThickness(2.f);
	hoop.setOutlineColor(Color::Blue);
	hoop.setPosition(Vector2f(0.f, 10.f));

	CircleShape ball;
	bool isShot = false;
	ball.setRadius(20.f);
	ball.setFillColor(Color::Red);
	ball.setPosition(Vector2f(0.f, window.getSize().y - ball.getRadius() * 3));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}

		// Update hoop

		if (hoop.getPosition().x <= 0)
			dir = 1;
		else if (hoop.getPosition().x + hoop.getRadius() * 2 >= window.getSize().x)
			dir = 0;

		if (dir == 0)
		{
			hoop.move(-5.f, 0);
		}
		else
		{
			hoop.move(5.f, 0);
		}
		
		// Update ball

		if (Mouse::isButtonPressed(Mouse::Left))
			isShot = true;

		if (!isShot)
			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
		else
			ball.move(0.f, -5.f);

		// Collision ball

		if (ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
		{
			isShot = false;
			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
		}

		window.clear();

		window.draw(hoop);
		window.draw(ball);

		window.display();
	}

	return 0;
}
