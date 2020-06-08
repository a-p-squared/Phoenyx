#include <SFML/Graphics.hpp>
#include"MenuFunctions.h"
#include"Collision.h"
#include"UI.h"

using namespace std;
using namespace sf;

void GameOver(RenderWindow &window, UI &UIObj)
{
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
				if(event.key.code == Keyboard::Enter)
					MainMenu(window);
			}
		}

			window.clear();
			window.draw(BackgroundSprite);

			PhoenyxSprite.setScale(2, 2);
			PhoenyxSprite.setOrigin(300, 0);
			PhoenyxSprite.setPosition(window.getSize().x / 2, 10);
			window.draw(PhoenyxSprite);

			UIObj.Print.setString("FINAL SCORE");
			UIObj.Print.setScale(2, 2);
			UIObj.Print.setPosition(window.getSize().x / 2, 403);
			window.draw(UIObj.Print);

			UIObj.Print.setString(to_string(UIObj.Scorevalue));
			UIObj.Print.setScale(3, 3);
			UIObj.Print.setPosition(window.getSize().x/2, 600);
			window.draw(UIObj.Print);

			window.display();
	}
}