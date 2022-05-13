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

		this->shape.setTexture(*texture);
		this->shape.setScale(0.1f, 0.1f);
	}

	~Player() {}

	inline Sprite& getShape() { return this->shape; }
	inline const int getHP(const int mode) { return mode == 0 ? this->HP : this->HP_Max; } const

	inline const float getX() const { return this->shape.getPosition().x; }
	inline const float getY() const { return this->shape.getPosition().y; }

	inline const float getWidth() const { return this->shape.getGlobalBounds().width; }
	inline const float getHeight() const { return this->shape.getGlobalBounds().height; }

	void movePlayer(const float x, const float y) { this->shape.move(x, y); }
	void hitPlayer() { this->HP--; }

private:
	int HP;
	int HP_Max;

	Sprite shape;

};

class Enemy
{
public:
	Enemy(Texture* texture, const unsigned int w, const unsigned int h)
	{
		this->HP_Max = rand() % 3 + 1;
		this->HP = this->HP_Max;

		this->shape.setTexture(*texture);
		this->shape.setScale(0.1f, 0.1f);
		this->shape.setPosition(w - this->shape.getGlobalBounds().width, rand() % (int) (h - this->shape.getGlobalBounds().height));
	}

	inline Sprite& getShape() { return this->shape; }
	inline const int getHP(const int mode) { return mode == 0 ? this->HP : this->HP_Max; } const

	inline const float getX() const { return this->shape.getPosition().x; }
	inline const float getY() const { return this->shape.getPosition().y; }

	void moveEnemy(const float x, const float y) { this->shape.move(x, y); }
	void hitEnemy() { this->HP--; }

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

	const unsigned int w = window.getSize().x;
	const unsigned int h = window.getSize().y;

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

	// UI init
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(10.f, 10.f);

	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(100.f, h / 2.f);
	gameOverText.setString("GAME OVER!");

	// Player init
	int score = 0;
	Player player(&playerTex);
	int shootTimer = 20;
	const float step = 10.f;
	Text hpText;
	hpText.setFont(font);
	hpText.setCharacterSize(12);
	hpText.setFillColor(Color::White);

	// Bullets
	std::vector<Bullet> bullets;

	// Enemy init
	int enemySpawnTimer = 0;
	std::vector<Enemy> enemies;
	Text eHpText;
	eHpText.setFont(font);
	eHpText.setCharacterSize(12);
	eHpText.setFillColor(Color::White);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		hpText.setPosition(player.getX(), player.getY() - hpText.getGlobalBounds().height);
		hpText.setString(std::to_string(player.getHP(0)) + "/" + std::to_string(player.getHP(1)));

		if (player.getHP(0) > 0)
		{
			//// Update

			// Player

			if (Keyboard::isKeyPressed(Keyboard::W)) player.movePlayer(0.f, -step);
			if (Keyboard::isKeyPressed(Keyboard::A)) player.movePlayer(-step, 0.f);
			if (Keyboard::isKeyPressed(Keyboard::S)) player.movePlayer(0.f, step);
			if (Keyboard::isKeyPressed(Keyboard::D)) player.movePlayer(step, 0.f);


			// Collision with window

			if (player.getX() <= 0) player.movePlayer(step, 0.f);
			if (player.getY() <= 0) player.movePlayer(0.f, step);
			if (player.getX() + player.getWidth() >= w) player.movePlayer(-step, 0.f);
			if (player.getY() + player.getHeight() >= h) player.movePlayer(0.f, -step);

			// Update controls

			if (shootTimer < 5) shootTimer++;

			else if (Mouse::isButtonPressed(Mouse::Left))
			{
				bullets.push_back(Bullet(&bulletTex, player.getShape().getPosition()));
				shootTimer = 0;
			}

			// Bullets

			for (size_t i = 0; i < bullets.size(); i++)
			{
				// Move
				bullets[i].moveBullet(20.f, 0.f);

				// Out of the window bounds
				if (bullets[i].getShape().getPosition().x > w)
				{
					bullets.erase(bullets.begin() + i);
					break;
				}

				// Enemy collision
				for (size_t k = 0; k < enemies.size(); k++)
				{
					if (bullets[i].getShape().getGlobalBounds().intersects(enemies[k].getShape().getGlobalBounds()))
					{
						if (enemies[k].getHP(0) <= 1)
						{
							score += enemies[k].getHP(1);
							enemies.erase(enemies.begin() + k);
						}
						else enemies[k].hitEnemy();

						bullets.erase(bullets.begin() + i);

						break;
					}
				}
			}

			// Enemy

			if (enemySpawnTimer < 25) enemySpawnTimer++;
			else
			{
				enemies.push_back(Enemy(&enemyTex, w, h));
				enemySpawnTimer = 0;
			}

			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].moveEnemy(-2.f, 0.f);

				Sprite enemy = enemies[i].getShape();

				if (enemy.getPosition().x + enemy.getGlobalBounds().width <= 0)
				{
					enemies.erase(enemies.begin() + i);
					break;
				}

				if (enemy.getGlobalBounds().intersects(player.getShape().getGlobalBounds()))
				{
					enemies.erase(enemies.begin() + i);
					player.hitPlayer();

					break;
				}
			}
		}

		// UI update
		scoreText.setString("Score: " + std::to_string(score));

		//// Draw

		window.clear();

		// Player
		window.draw(player.getShape());

		// Bullets
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i].getShape());
		}

		// Enemy
		for (size_t i = 0; i < enemies.size(); i++)
		{
			eHpText.setString(std::to_string(enemies[i].getHP(0)) + "/" + std::to_string(enemies[i].getHP(1)));
			eHpText.setPosition(enemies[i].getX(), enemies[i].getY() - eHpText.getGlobalBounds().height);
			window.draw(eHpText);
			window.draw(enemies[i].getShape());
		}

		// UI

		window.draw(scoreText);
		window.draw(hpText);

		if (player.getHP(0) == 0) window.draw(gameOverText);

		window.display();
	}

	return 0;
}
