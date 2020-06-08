#include <SFML/Graphics.hpp>
#include<iostream>
#include"MenuFunctions.h"
#include"UI.h"
#include"Collision.h"

using namespace sf;
using namespace std;

void HowToPlay(RenderWindow &window)
{
	UI UIobj;

	Sound MenuSelect;
	SoundBuffer SoundPlayer;
	if (!SoundPlayer.loadFromFile("Music/MenuSelect.wav"))
	{
		cout << "Cannot Load MenuSelect.wav!" << endl;
	}
	MenuSelect.setBuffer(SoundPlayer);

	String HowToString = "1. Use Arrow Keys to Control the Phoenyx\n2. Press SpaceBar to Shoot FireBall\n3. If Fireball Misses Target, Wait for 5 Seconds Before Being Able to Fire Again\n4. Lose a Life if hit By an Arrow or Collide With Enemy\n5. Lose 3 Lives and GAME OVER!";

	Texture BackgroundTexture;
	if (!Collision::CreateTextureAndBitmask(BackgroundTexture, "Images/Grassland.jpg"))
	{
		cout << "Cannot Load Background Texture!" << endl;
	}

	Sprite BackgroundSprite(BackgroundTexture);

	Texture PhoenyxTexture;
	if (!Collision::CreateTextureAndBitmask(PhoenyxTexture, "Images/Phoenyx.png"))
	{
		cout << "Cannot Load Phoenyx Title texture!" << endl;
	}

	Sprite PhoenyxSprite(PhoenyxTexture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				MenuSelect.play();
				MainMenu(window);
			}

			window.clear();
			window.draw(BackgroundSprite);

			PhoenyxSprite.setScale(2, 2);
			PhoenyxSprite.setOrigin(300, 0);
			PhoenyxSprite.setPosition(window.getSize().x / 2, 10);
			window.draw(PhoenyxSprite);

			UIobj.Print.setString(HowToString);
			UIobj.Print.setScale(1.3, 1.3);
			UIobj.Print.setPosition(20, 500);
			window.draw(UIobj.Print);

			UIobj.Print.setString("Press Any Key To Continue...");
			UIobj.Print.setScale(2, 2);
			UIobj.Print.setPosition(500, 900);
			window.draw(UIobj.Print);

			window.display();
		}
	}
}