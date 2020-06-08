#pragma once
#include<time.h>
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Collision.h"

using namespace std;
using namespace sf;

class Archer
{
private:
	Time TimeToShoot;
	Time PreviousShoot;
	Time ArrowLife;
	bool CanFire = false;
	int ArrowDirection;
	

public:

	Sound ArrowShoot;
	SoundBuffer ArrowShootBuffer;

	Sound ArrowHit;
	SoundBuffer ArrowHitBuffer;

	bool isShooting = false;
	float ArrowSpeed = 20.f;
	Vector2f TargetVector;
	Vector2f ArrowSpawnPoint;

	Texture ArcherTexture;
	Texture ArrowTexture;
	int RandomX[2] = { -200, 2120 };
	Vector2f ArcherSpawnPoint;
	Sprite ArcherSprite;
	Sprite ArrowSprite;
	Archer()
	{

		ArrowShootBuffer.loadFromFile("Music/ArrowShoot.wav");
		ArrowShoot.setBuffer(ArrowShootBuffer);

		ArrowHitBuffer.loadFromFile("Music/ArrowHit.wav");
		ArrowHit.setBuffer(ArrowHitBuffer);

		if (!Collision::CreateTextureAndBitmask(ArcherTexture,"Images/Archer.png"))
		{
			cout << "Cannot Load Archer Texture!" << endl;
		}

		if (!Collision::CreateTextureAndBitmask(ArrowTexture, "Images/Arrow.png"))
		{
			cout << "Cannot Load Arrow Texture!" << endl;
		}

		ArcherSpawnPoint.y = rand() % 880;
		ArcherSpawnPoint.x = RandomX[rand() % 2];

		ArcherSprite.setPosition(ArcherSpawnPoint);
		ArcherSprite.setTexture(ArcherTexture);
		ArcherSprite.setScale(0.7, 0.7);

		ArrowSprite.setTexture(ArrowTexture);
		ArrowSprite.setScale(0.7, 0.7);

		if (ArcherSpawnPoint.x == -200)
		{
			if (ArcherSpawnPoint.y > 540)
				ArrowDirection = 2;
			else
				ArrowDirection = 1;
		}
		else
		{
			if (ArcherSpawnPoint.y > 540)
				ArrowDirection = 4;
			else
				ArrowDirection = 3;
		}
	}
		
	void ArcherMove()
	{
		if (ArcherSpawnPoint.x == -200)
		{
			if (ArcherSprite.getPosition().x < 100)
			{
				ArcherSprite.move(3, 0);
			}
			else
				CanFire = true;
		}
		else
		{
			if (ArcherSprite.getPosition().x > 1620)
			{
				ArcherSprite.move(-3, 0);
			}
			else
				CanFire = true;
		}
	}

	void ArcherShoot(Sprite &Target, Clock &GameClock)
	{
		if (CanFire && !isShooting)
		{
			TimeToShoot = GameClock.getElapsedTime();
			if (TimeToShoot.asSeconds() - PreviousShoot.asSeconds() >= 3.f)
			{
				isShooting = true;
				ArrowShoot.play();
				PreviousShoot = GameClock.getElapsedTime();
				ArrowSpawnPoint = ArcherSprite.getPosition();
				ArrowSprite.setPosition(ArrowSpawnPoint);
				switch (ArrowDirection)
				{
				case 1:
					ArrowSprite.setRotation(135);
					break;
				case 2:
					ArrowSprite.setRotation(45);
					break;
				case 3:
					ArrowSprite.setRotation(-135);
					break;
				case 4:
					ArrowSprite.setRotation(-45);
					break;
				}
				TargetVector = (Target.getPosition() - ArrowSpawnPoint) / sqrt(pow((Target.getPosition().x - ArrowSpawnPoint.x), 2) + pow((Target.getPosition().y - ArrowSpawnPoint.y), 2));
			}
		}
	}

	void ArrowMovement(Clock &GameClock)
	{
		ArrowSprite.move(TargetVector.x * ArrowSpeed, TargetVector.y * ArrowSpeed);
		ArrowLife = GameClock.getElapsedTime();
		if (ArrowLife.asSeconds() - PreviousShoot.asSeconds() >= 5.f)
		{
			isShooting = false;
		}
	}
};