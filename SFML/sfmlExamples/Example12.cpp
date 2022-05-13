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
	Bullet(Texture* texture, Vector2f pos)
	{
		this->shape.setTexture(*texture);
		this->shape.setScale(0.07f, 0.07f);
		this->shape.setPosition(pos);
	}

	~Bullet() {}

	inline Sprite& getShape() { return this->shape; }
	void moveBullet(const float x, const float y) { this->shape.move(x, y); }



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

	inline Sprite& getShape() { return this->shape; }
	inline std::vector<Bullet>& getBullets() { return this->bullets; }

	inline const float getX() const { return this->shape.getPosition().x; }
	inline const float getY() const { return this->shape.getPosition().y; }

	void addBullet(Bullet texture) { this->bullets.push_back(texture); }
	void delBullet(const size_t i) { this->bullets.erase(bullets.begin() + i); }

	void movePlayer(const float x, const float y) { this->shape.move(x, y); }
	void setPlayerPos(const float x, const float y) { this->shape.setPosition(x, y); }

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
	Enemy(Texture* texture, Vector2f pos)
	{
		this->HP_Max = rand() % 3 + 1;
		this->HP = this->HP_Max;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.2f, 0.2f);
		this->shape.setPosition(pos);
	}

	~Enemy() {};

private:
	int HP;
	int HP_Max;

	Sprite shape;

};

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(800, 600), "Spaceship action", Style::Close);
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
	int shootTimer = 20;
	const float step = 10.f;

	// Enemy init
	std::vector<Enemy> enemies;

	const unsigned int w = window.getSize().x;
	const unsigned int h = window.getSize().y;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//// Update

		// Player
		if (Keyboard::isKeyPressed(Keyboard::W)) player.movePlayer(0.f  , -step);
		if (Keyboard::isKeyPressed(Keyboard::A)) player.movePlayer(-step, 0.f  );
		if (Keyboard::isKeyPressed(Keyboard::S)) player.movePlayer(0.f  , step);
		if (Keyboard::isKeyPressed(Keyboard::D)) player.movePlayer(step , 0.f  );

		// Collision with window

		if (player.getX() <= 0) player.setPlayerPos(0.f, player.getY());
		if (player.getY() <= 0) player.setPlayerPos(player.getX(), 0.f);
		if (player.getX() + player.getShape().getGlobalBounds().width >= w) player.setPlayerPos(player.getX() - step, player.getY());
		if (player.getY() + player.getShape().getGlobalBounds().height >= h) player.setPlayerPos(player.getX(), player.getY() - step);

		// Update controls

		if (shootTimer < 20) shootTimer++;

		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 20)
		{
			player.addBullet(Bullet(&bulletTex, player.getShape().getPosition()));
			shootTimer = 0;
		}

		std::vector<Bullet>& bullets = player.getBullets();

		// Bullets

		for (size_t i = 0; i < bullets.size(); i++)
		{
			// Move
			bullets[i].moveBullet(20.f, 0.f);

			// Out of the window bounds
			if (bullets[i].getShape().getPosition().x > window.getSize().x) player.delBullet(i);

			// Enemy collision
			for (size_t i = 0; i < length; i++)
			{

			}
		}


		//// Draw

		window.clear();

		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i].getShape());
		}

		window.draw(player.getShape());

		window.display();
	}

	return 0;
}
