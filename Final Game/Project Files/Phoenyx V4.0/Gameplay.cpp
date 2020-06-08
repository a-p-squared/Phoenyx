#include <SFML/Graphics.hpp>
#include"MenuFunctions.h"
#include"UI.h"
#include"Archer.h"																																												
#include"Player.h"
#include"Enemy.h"

using namespace sf;
using namespace std;

void Gameplay(RenderWindow &window)
{
	//Start

	Sound FireShoot;
	SoundBuffer FireShootBuffer;
	FireShootBuffer.loadFromFile("Music/FireShoot.wav");
	FireShoot.setBuffer(FireShootBuffer);

	Sound FireMovement;
	SoundBuffer FireMovementBuffer;
	FireMovementBuffer.loadFromFile("Music/FireSound.wav");
	FireMovement.setBuffer(FireMovementBuffer);

	UI UIobj;
	
	Clock GameClock;
	Time GameRunTime;

	Texture BackgroundTexture;
	if (!Collision::CreateTextureAndBitmask(BackgroundTexture,"Images/Grassland.jpg"))
	{
		cout << "Cannot Load Background Texture!" << endl;
	}

	Sprite BackgroundSprite(BackgroundTexture);

	Player Phoenyx;

	//Update
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					MainMenu(window);
				}
				if (event.key.code == Keyboard::Space)
				{
					if (!Phoenyx.isFiring)
					{
						FireShoot.play();
						Phoenyx.Fire(GameClock);
					}
				}
			}
		}
		
		SpawnArcher(GameClock);

		Phoenyx.StopFire(GameClock);

		Phoenyx.PlayerMovement();

		ArcherShoot(Phoenyx.PhoenixSprite, GameClock);

		ArcherMovement();

		PlayerKill(Phoenyx.PhoenixSprite, UIobj.lives, GameClock);

		if (Phoenyx.isFiring)
		{
			FireMovement.play();
			Phoenyx.FireMovement();
		}

		ArcherKill(Phoenyx.FireBallSprite, Phoenyx.isFiring, UIobj);

		ArrowMovement(GameClock);

		UIobj.UpdateScore();
		UIobj.UpdateLife();

		if (UIobj.lives == 0)
		{
			GameOver(window, UIobj);
		}

		//Display
		window.clear();
		window.draw(BackgroundSprite);
		ArcherDraw(window);
		if (Phoenyx.isFiring) Phoenyx.FireMovement();
		if (Phoenyx.isFiring) window.draw(Phoenyx.FireBallSprite);
		ArrowDraw(window);
		window.draw(Phoenyx.PhoenixSprite);

		//UI
		window.draw(UIobj.Score);
		window.draw(UIobj.LivesLeft);

		window.display();
	}
}