#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void PlayerMovement(Sprite &Player, int &Direction)
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		Player.move(-1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Player.move(0, -0.2);
			Player.setRotation(-45);
			Direction = 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Player.move(0, 0.2);
			Player.setRotation(-135);
			Direction = 8;
		}
		else
		{
			Player.setRotation(-90);
			Direction = 4;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		Player.move(1, 0);
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Player.move(0, -0.2);
			Player.setRotation(45);
			Direction = 6;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Player.move(0, 0.2);
			Player.setRotation(135);
			Direction = 7;
		}
		else
		{
			Player.setRotation(90);
			Direction = 2;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		Player.move(0, -1);
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Player.move(-0.2, 0);
			Player.setRotation(-45);
			Direction = 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Player.move(0.2, 0);
			Player.setRotation(45);
			Direction = 6;
		}
		else
		{
			Player.setRotation(0);
			Direction = 1;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Player.move(0, 1);
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Player.move(-0.2, 0);
			Player.setRotation(-135);
			Direction = 8;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Player.move(0.2, 0);
			Player.setRotation(135);
			Direction = 7;
		}
		else
		{
			Player.setRotation(180);
			Direction = 3;
		}
	}
}

void AdjustFireballSpawnPoint(Vector2f &SpawnPoint, int &Direction)
{
	switch (Direction)
	{
	case 1:
		SpawnPoint.x -= 25;
		SpawnPoint.y -= 75;
		break;
	case 2:
		SpawnPoint.x += 50;
		SpawnPoint.y -= 50;
	case 3:
		SpawnPoint.x -= 25;
		SpawnPoint.y += 25;
		break;
	case 4:
		SpawnPoint.x -= 75;
		SpawnPoint.y -= 25;
	}
}

void FireMovement(Sprite &Fire, int &Direction)
{
	switch (Direction)
	{
	case 1:
		Fire.move(0, -1);
		break;
	case 2:
		Fire.move(1, 0);
		break;
	case 3:
		Fire.move(0, 1);
		break;
	case 4:
		Fire.move(-1, 0);
		break;
	case 5:
		Fire.move(-1, -1);
		break;
	case 6:
		Fire.move(1, -1);
		break;
	case 7:
		Fire.move(1, 1);
		break;
	case 8:
		Fire.move(-1, 1);
		break;
	}
}

void ArcherMovement(Sprite &Archer, Vector2f SpawnPoint)
{
	if (SpawnPoint.x == -200)
	{
		if (Archer.getPosition().x < 100)
		{
			Archer.move(1, 0);
		}
	}
	else
	{
		if (Archer.getPosition().x > 700)
		{
			Archer.move(-1, 0);
		}
	}
}

int main()
{
	RenderWindow window(VideoMode(960, 540), "PHOENYX V3.0");

	Texture BackgroundTexture;
	if (!BackgroundTexture.loadFromFile("Grassland.jpg"))
	{
		cout << "Cannot Load Background Texture!" << endl;
	}

	Sprite BackgroundSprite(BackgroundTexture);
	BackgroundSprite.setScale(0.5, 0.5);

	Texture PhoenixTexture;
	if (!PhoenixTexture.loadFromFile("Phoenix.png"))
	{
		cout << "Cannot Load Phoenix Texture!" << endl;
	}

	Sprite PhoenixSprite(PhoenixTexture);
	PhoenixSprite.setPosition(400, 300);
	PhoenixSprite.setScale(0.5, 0.5);
	PhoenixSprite.setOrigin(100, 100);

	Texture FireBallTexture;
	if (!FireBallTexture.loadFromFile("Fireball.png"))
	{
		cout << "Cannot load Fireball Texture!" << endl;
	}

	Sprite FireBallSprite(FireBallTexture);
	FireBallSprite.setScale(0.5, 0.5);

	Texture ArcherTexture;
	if (!ArcherTexture.loadFromFile("Archer.png"))
	{
		cout << "Cannot Load Archer Texture!" << endl;
	}

	Sprite ArcherSprite(ArcherTexture);
	ArcherSprite.setScale(0.5, 0.5);
	vector<Sprite> ArcherVector;
	ArcherVector.push_back(ArcherSprite);
	ArcherVector.push_back(ArcherSprite);

	Vector2f FireBallSpawnPoint;
	Vector2f ArcherSpawnPoint(0,0);
	//int RandomX[2] = { -200,1000 };
	int RandomX[2] = { -200,1000 };

	int Direction = 1;
	int FireDirection;

	bool isFiring = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					isFiring = true;
					FireBallSpawnPoint = PhoenixSprite.getPosition();
					AdjustFireballSpawnPoint(FireBallSpawnPoint, Direction);
					FireBallSprite.setPosition(FireBallSpawnPoint);
					FireDirection = Direction;
				}
				if (event.key.code == Keyboard::F)
				{
					for (int c = 0; c < ArcherVector.size(); c++)
					{
						ArcherSpawnPoint.y = rand() % 450;
						ArcherSpawnPoint.x = RandomX[rand() % 2];
						cout << "Archer Spawn Point " << endl << ArcherSpawnPoint.x << " " << ArcherSpawnPoint.y << endl;
						ArcherVector[c].setPosition(ArcherSpawnPoint);
					}
				}
			}
		}

		PlayerMovement(PhoenixSprite,Direction);
		FireMovement(FireBallSprite, FireDirection);
		//ArcherMovement(ArcherSprite,ArcherSpawnPoint);

		window.clear();
		window.draw(BackgroundSprite);
		window.draw(PhoenixSprite);
		if(isFiring) window.draw(FireBallSprite);
		for (int c = 0; c < ArcherVector.size(); c++)
		{
			window.draw(ArcherVector[c]);
		}
		window.display();
	}
}