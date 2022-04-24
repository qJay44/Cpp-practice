#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <cstdlib>

using namespace sf;

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(640, 400), "Cat do(d)ge");
	window.setFramerateLimit(75);

	// Cat
	Texture catTex;
	Sprite cat;
	int catSpawnTimer = 15;

	if (!catTex.loadFromFile("Textures/cat.png"))
		throw "Could not load cat.png!";

	cat.setTexture(catTex);
	cat.setScale(Vector2f(0.2f, 0.2f));

	std::vector<Sprite> cats;
	cats.push_back(Sprite(cat));

	// Doge
	Texture dogeTex;
	Sprite doge;
	RectangleShape hpBar;
	int hp = 10;

	hpBar.setFillColor(Color::Red);
	hpBar.setSize(Vector2f(hp * 20.f, 20.f));
	hpBar.setPosition(200.f, 10.f);

	if (!dogeTex.loadFromFile("Textures/doge.png"))
		throw "Could not load cat.png!";

	doge.setTexture(dogeTex);
	doge.setScale(Vector2f(0.3f, 0.3f));

	while (window.isOpen() && hp > 0)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}

		//// Update

		// Doge (Player)

		doge.setPosition(doge.getPosition().x, Mouse::getPosition(window).y);

		if (doge.getPosition().y > window.getSize().y - doge.getGlobalBounds().height)
			doge.setPosition(doge.getPosition().x, window.getSize().y - doge.getGlobalBounds().height);

		if (doge.getPosition().y < 0)
			doge.setPosition(doge.getPosition().x, 0);

		// Cats (Enemies)
		
		for (size_t i = 0; i < cats.size(); i++)
		{
			cats[i].move(-7.f, 0.f);

			if (cats[i].getPosition().x < 0 - cat.getGlobalBounds().width)
				cats.erase(cats.begin() + i);
		}

		if (catSpawnTimer < 40)
			catSpawnTimer++;
		else
		{
			cat.setPosition(window.getSize().x, rand() % int(window.getSize().y - cat.getGlobalBounds().height));
			cats.push_back(Sprite(cat));
			catSpawnTimer = 0;
		}

		// Collision
		for (size_t i = 0; i < cats.size(); i++)
		{
			if (doge.getGlobalBounds().intersects(cats[i].getGlobalBounds()))
			{
				hp--;
				hpBar.setSize(Vector2f(hp * 20.f, 20.f));
				cats.erase(cats.begin() + i);
			}
		}

		//// Draw

		window.clear();

		window.draw(doge);

		for (size_t i = 0; i < cats.size(); i++)
		{
			window.draw(cats[i]);
		}

		// UI
		
		window.draw(hpBar);

		window.display();
	}

	return 0;
}
