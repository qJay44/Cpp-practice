#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Text into", Style::Default);
	window.setFramerateLimit(75);

	Font font;
	if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
		throw("Could not open the font!");

	Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);
	text.setString("Hey I am a string of text in sfml");
	text.setPosition(10.f, window.getSize().y / 2.f);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Update
		text.move(5.1f, 0.f);

		if (text.getPosition().x > window.getSize().x)
			text.setPosition(0.f, text.getPosition().y);

		// Draw
		window.clear();

		window.draw(text);

		// Draw everything

		window.display();
	}

	return 0;
}
