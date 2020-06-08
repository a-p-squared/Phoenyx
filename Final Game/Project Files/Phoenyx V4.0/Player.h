#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Collision.h"

using namespace sf;
using namespace std;

class Player
{
private:
	Vector2f FireBallSpawnPoint;
	
	Texture PhoenixTexture;
	Texture FireBallTexture;
	
	int Direction = 1;
	int FireDirection;

public:

	Time FireStart;
	Time FireEnd;

	Sprite PhoenixSprite;
	Sprite FireBallSprite;
	bool isFiring = false;

	Player()
	{
		if (!Collision::CreateTextureAndBitmask(PhoenixTexture,"Images/Phoenix.png"))
		{
			cout << "Cannot Load Phoenix Texture!" << endl;
		}

		PhoenixSprite.setTexture(PhoenixTexture);
		PhoenixSprite.setPosition(960, 540);
		PhoenixSprite.setScale(0.7, 0.7);
		PhoenixSprite.setOrigin(100, 100);

		if (!Collision::CreateTextureAndBitmask(FireBallTexture,"Images/Fireball.png"))
		{
			cout << "Cannot load Fireball Texture!" << endl;
		}

		FireBallSprite.setTexture(FireBallTexture);
		FireBallSprite.setScale(0.7, 0.7);
	}

	void PlayerMovement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			PhoenixSprite.move(-5, 0);
			PhoenixSprite.setRotation(270);
			Direction = 4;
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				PhoenixSprite.move(0, -2);
				PhoenixSprite.setRotation(315);
				Direction = 5;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				PhoenixSprite.move(0, 2);
				PhoenixSprite.setRotation(225);
				Direction = 8;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			PhoenixSprite.move(5, 0);
			PhoenixSprite.setRotation(90);
			Direction = 2;
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				PhoenixSprite.move(0, -2);
				PhoenixSprite.setRotation(45);
				Direction = 6;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				PhoenixSprite.move(0, 2);
				PhoenixSprite.setRotation(135);
				Direction = 7;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			PhoenixSprite.move(0, -5);
			PhoenixSprite.setRotation(0);
			Direction = 1;
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				PhoenixSprite.move(-2, 0);
				PhoenixSprite.setRotation(315);
				Direction = 5;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				PhoenixSprite.move(2, 0);
				PhoenixSprite.setRotation(45);
				Direction = 6;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			PhoenixSprite.move(0, 5);
			PhoenixSprite.setRotation(180);
			Direction = 3;
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				PhoenixSprite.move(-2, 0);
				PhoenixSprite.setRotation(225);
				Direction = 8;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				PhoenixSprite.move(2, 0);
				PhoenixSprite.setRotation(135);
				Direction = 7;
			}
		}
	}

	void AdjustFireballSpawnPoint()
	{
		switch (Direction)
		{
		case 1:
			FireBallSpawnPoint.x -= 25;
			FireBallSpawnPoint.y -= 75;
			break;
		case 2:
			FireBallSpawnPoint.x += 50;
			FireBallSpawnPoint.y -= 50;
		case 3:
			FireBallSpawnPoint.x -= 25;
			FireBallSpawnPoint.y += 25;
			break;
		case 4:
			FireBallSpawnPoint.x -= 75;
			FireBallSpawnPoint.y -= 25;
		}
	}

	void FireMovement()
	{
		switch (FireDirection)
		{
		case 1:
			FireBallSprite.move(0, -10);
			break;
		case 2:
			FireBallSprite.move(10, 0);
			break;
		case 3:
			FireBallSprite.move(0, 10);
			break;
		case 4:
			FireBallSprite.move(-10, 0);
			break;
		case 5:
			FireBallSprite.move(-10, -10);
			break;
		case 6:
			FireBallSprite.move(10, -10);
			break;
		case 7:
			FireBallSprite.move(10, 10);
			break;
		case 8:
			FireBallSprite.move(-10, 10);
			break;
		}
	}

	void Fire(Clock &GameClock)
	{
		isFiring = true;
		FireStart = GameClock.getElapsedTime();
		FireBallSpawnPoint = PhoenixSprite.getPosition();
		AdjustFireballSpawnPoint();
		FireBallSprite.setPosition(FireBallSpawnPoint);
		FireDirection = Direction;
	}

	void StopFire(Clock &GameClock)
	{
		if (isFiring)
		{
			FireEnd = GameClock.getElapsedTime();
			if (FireEnd.asSeconds() - FireStart.asSeconds() >= 5.f)
			{
				isFiring = false;
			}
		}
	}
};