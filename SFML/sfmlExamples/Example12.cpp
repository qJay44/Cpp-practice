#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>

using namespace sf;

class Bullet
{
public:
	Bullet(Texture* texture)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.3f, 0.3f);
	}

	~Bullet() {}

private:
	Sprite shape;
};


class Player
{
public:
	Player(Texture* texture)
	{
		this->HP_Max = 10;
		this->HP = this->HP_Max;
		this->textrue = texture;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.1f, 0.1f);
	}

	~Player() {}

	inline const Sprite getShape() const { return this->shape; }

private:
	int HP;
	int HP_Max;

	Sprite shape;
	Texture* textrue;

	std::vector<Bullet> bullets;
};

class Enemy
{
public:
	Enemy();
	~Enemy();

private:

};

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(800, 600), "Spaceship action", Style::Default);
	window.setFramerateLimit(75);

	// Init text
	Font font;
	font.loadFromFile("Fonts/Dosis-Light.ttf");

	// Init textures
	Texture playerTex;
	playerTex.loadFromFile("Textures/ship.png");

	Texture enemyTex;
	enemyTex.loadFromFile("Textures/enemy.png");

	Texture bulletTex;
	bulletTex.loadFromFile("Textures/missileTex01.png");

	// Player init
	Player player(&playerTex);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Update

		// Draw

		window.clear();

		window.draw(player.getShape());

		window.display();
	}

	return 0;
}
