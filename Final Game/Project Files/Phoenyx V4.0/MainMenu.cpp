#include <SFML/Graphics.hpp>
#include<iostream>
#include"MenuFunctions.h"
#include"UI.h"
#include"Collision.h"

using namespace sf;
using namespace std;

void MainMenu(RenderWindow &window)
{
	UI UIobj;

	int Selection = 1;

	Sound MenuSelect;
	SoundBuffer SoundPlayer;
	if (!SoundPlayer.loadFromFile("Music/MenuSelect.wav"))
	{
		cout << "Cannot Load MenuSelect.wav!" << endl;
	}
	MenuSelect.setBuffer(SoundPlayer);

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
				if (event.key.code == Keyboard::Enter)
				{
					MenuSelect.play();
					switch (Selection)
					{
					case 1:
						Gameplay(window);
						break;
					case 2:
						HowToPlay(window);
						break;
					case 3:
						window.close();
						break;
					}
				}
				if (event.key.code == Keyboard::Up)
				{
					MenuSelect.play();
					if (Selection > 1)
						Selection--;
				}
				if (event.key.code == Keyboard::Down)
				{
					MenuSelect.play();
					if (Selection < 3)
						Selection++;
				}
			}
		}

		window.clear();
		window.draw(BackgroundSprite);

		PhoenyxSprite.setScale(2, 2);
		PhoenyxSprite.setOrigin(300, 0);
		PhoenyxSprite.setPosition(window.getSize().x/2, 10);
		window.draw(PhoenyxSprite);

		UIobj.Print.setString("MAIN MENU");
		UIobj.Print.setScale(3, 3);
		UIobj.Print.setStyle(Text::Bold);
		UIobj.Print.setPosition(728, 403);
		UIobj.Print.setFillColor(Color::White);
		window.draw(UIobj.Print);

		UIobj.Print.setString("Play");
		UIobj.Print.setScale(2, 2);
		UIobj.Print.setPosition(740, 590);
		Selection == 1? UIobj.Print.setFillColor(Color::Yellow) : UIobj.Print.setFillColor(Color::White);
		window.draw(UIobj.Print);

		UIobj.Print.setString("How To Play");
		UIobj.Print.setScale(2, 2);
		UIobj.Print.setPosition(740, 688);
		Selection == 2 ? UIobj.Print.setFillColor(Color::Yellow) : UIobj.Print.setFillColor(Color::White);
		window.draw(UIobj.Print);

		UIobj.Print.setString("Exit");
		UIobj.Print.setScale(2, 2);
		UIobj.Print.setPosition(740, 790);
		Selection == 3 ? UIobj.Print.setFillColor(Color::Yellow) : UIobj.Print.setFillColor(Color::White);
		window.draw(UIobj.Print);

		window.display();
	}
}