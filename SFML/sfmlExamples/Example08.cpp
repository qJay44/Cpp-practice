#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <cstdlib>

#include <vector>

using namespace sf;

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(640, 480), "Ball Shooter");
	window.setFramerateLimit(75);

	// Balls
	CircleShape projectile;
	projectile.setFillColor(Color::Red);
	projectile.setRadius(5.f);

	// Enemy
	RectangleShape enemy;
	enemy.setFillColor(Color::Magenta);
	enemy.setSize(Vector2f(50.f, 50.f));
	int enemySpawnTimer = 0;

	// Player
	CircleShape player;
	player.setFillColor(Color::White);
	player.setRadius(50.f);
	player.setPosition(window.getSize().x / 2.f - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 10.f);
	Vector2f playerCenter;
	int shootTimer = 0;

	std::vector<CircleShape> projectiles;
	projectiles.push_back(CircleShape(projectile));
	
	std::vector<RectangleShape> enemies;
	enemies.push_back(RectangleShape(enemy));

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

		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());

		player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);

		// Projectiles
		
		if (shootTimer < 5) shootTimer++;

		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 3) // Shoot
		{
			projectile.setPosition(Vector2f(playerCenter.x - projectile.getRadius(), playerCenter.y + projectile.getRadius()));
			projectiles.push_back(CircleShape(projectile));

			shootTimer = 0;
		}

		for (size_t i = 0; i < projectiles.size(); i++)
		{
			projectiles[i].move(0.f, -10.f);

			if (projectiles[i].getPosition().y <= 0)
				projectiles.erase(projectiles.begin() + i);
		}

		// Enemies

		if (enemySpawnTimer < 20) 
			enemySpawnTimer++;
		else
		{
			enemy.setPosition((rand() % (window.getSize().x) - enemy.getSize().x), 0);
			enemies.push_back(RectangleShape(enemy));

			enemySpawnTimer = 0;
		}

		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].move(0.f, 5.f);

			if (enemies[i].getPosition().y > window.getSize().y)
				enemies.erase(enemies.begin() + i);
		}

		// Collision

		for (size_t i = 0; i < projectiles.size(); i++)
		{
			for (size_t k = 0; k < enemies.size(); k++)
			{
				if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
				{
					projectiles.erase(projectiles.begin() + i);
					enemies.erase(enemies.begin() + k);

					break;
				}
			}
		}

		//// Draw

		window.clear();

		window.draw(player);

		for (size_t i = 0; i < enemies.size(); i++)
		{
			window.draw(enemies[i]);
		}

		for (size_t i = 0; i < projectiles.size(); i++)
		{
			window.draw(projectiles[i]);
		}

		window.display();
	}

	return 0;
}
