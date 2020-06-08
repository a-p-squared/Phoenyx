//#include"SFML/Graphics.hpp"
//#include<iostream>
//#include<Box2D/Box2D.h>
//
//using namespace std;
//using namespace sf;
//
//void AdjustSpawnPoint(Vector2f &Spawn, int &Direction)
//{
//	switch (Direction)
//	{
//	case 1:
//		Spawn.x -= 20;
//		Spawn.y -= 40;
//		break;
//	case 2:
//		Spawn.x += 60;
//		Spawn.y += 40;
//		break;
//	case 3:
//		Spawn.x -= 10;
//		Spawn.y += 90;
//		break;
//	case 4:
//		Spawn.x -= 80;
//		Spawn.y += 40;
//		break;
//	}
//}
//
//void PlayerControl(Sprite &Player, int &Direction, Vector2f &Spawn)
//{
//	if (Keyboard::isKeyPressed(Keyboard::Left))
//	{
//		Player.move(-1, 0);
//		//Spawn.x -= 1;
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			Player.move(0, -0.2);
//			Player.setRotation(-45);
//		}
//		else if (Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			Player.move(0, 0.2);
//			Player.setRotation(-135);
//		}
//		else
//		{
//			Player.setRotation(-90);
//			Direction = 4;
//			//if (Direction != 4)
//			//{
//			//	//resetFireSpawnPosition(Spawn,Direction);
//			//	Spawn = Player.getPosition();
//			//	Spawn.x -= 80; Spawn.y += 40;
//			//	Direction = 4;
//			//}
//		}
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Right))
//	{
//		Player.move(1, 0);
//		//Spawn.x += 1;
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			Player.move(0, -0.2);
//			Player.setRotation(45);
//		}
//		else if (Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			Player.move(0, 0.2);
//			Player.setRotation(135);
//		}
//		else
//		{
//			Player.setRotation(90);
//			Direction = 2;
//			//if (Direction != 2)
//			//{
//			//	//resetFireSpawnPosition(Spawn, Direction);
//			//	Spawn = Player.getPosition();
//			//	Spawn.x += 60; Spawn.y += 40;
//			//	Direction = 2;
//			//}
//		}
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Up))
//	{
//		Player.move(0, -1);
//		//Spawn.y -= 1;
//		if (Keyboard::isKeyPressed(Keyboard::Left))
//		{
//			Player.move(-0.2, 0);
//			Player.setRotation(-45);
//		}
//		else if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			Player.move(0.2, 0);
//			Player.setRotation(45);
//		}
//		else
//		{
//			Player.setRotation(0);
//			Direction = 1;
//			//if (Direction != 1)
//			//{
//			//	//resetFireSpawnPosition(Spawn, Direction);
//			//	Spawn = Player.getPosition();
//			//	Spawn.x -= 20; Spawn.y -= 80;
//			//	Direction = 1;
//			//}
//		}
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Down))
//	{
//		Player.move(0, 1);
//		//Spawn.y += 1;
//		if (Keyboard::isKeyPressed(Keyboard::Left))
//		{
//			Player.move(-0.2, 0);
//			Player.setRotation(-135);
//		}
//		else if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			Player.move(0.2, 0);
//			Player.setRotation(135);
//		}
//		else
//		{
//			Player.setRotation(180);
//			Direction = 3;
//			//if (Direction != 3)
//			//{
//			//	//resetFireSpawnPosition(Spawn, Direction);
//			//	Spawn = Player.getPosition();
//			//	Spawn.x -= 10; Spawn.y += 90;
//			//	Direction = 3;
//			//}
//		}
//	}
//}
//
//int main()
//{
//	RenderWindow window(VideoMode(960, 540), "PHEONYX PROTOTYPE");
//
//	Texture BackgroundTexture;
//	if (!BackgroundTexture.loadFromFile("Grassland.jpg"))
//	{
//		cout << "Cannot Load Background Texture!" << endl;
//	}
//
//	Sprite Background(BackgroundTexture);
//	Background.setScale(0.5, 0.5);
//	
//	Texture PlayerTexture;
//	PlayerTexture.setRepeated(true);
//	if (!PlayerTexture.loadFromFile("Phoenix.png"))
//	{
//		cout << "Cannot Load Player Texture!" << endl;
//	}
//
//	Sprite PlayerSprite(PlayerTexture);
//	PlayerSprite.setScale(0.5,0.5);
//	PlayerSprite.setPosition(400, 300);
//	PlayerSprite.setOrigin(100, 100);
//
//	int Direction = 1;
//
//	Texture FireballTexture;
//	FireballTexture.setRepeated(true);
//	if (!FireballTexture.loadFromFile("Fireball.png"))
//	{
//		cout << "Cannot Load FireBall Texture!" << endl;
//	}
//
//	Vector2f FireBallSpawnPoint(PlayerSprite.getPosition());
//	FireBallSpawnPoint.x -= 20;
//	FireBallSpawnPoint.y -= 80;
//
//	Sprite FireBall(FireballTexture);
//	FireBall.setScale(0.5, 0.5);
//	
//	int FireLife = 5;
//	bool isFiring = false;
//	bool CanFire = false;
//
//	while (window.isOpen())
//	{
//		Event event;
//
//		while (window.pollEvent(event))
//		{
//			if ((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
//				window.close();
//			else
//			{
//				if (event.type == Event::MouseButtonPressed)
//				{
//					if (event.mouseButton.button == Mouse::Left)
//					{
//						cout << "IsFiring = True" << endl;
//						isFiring = true;
//					}
//				}
//			}
//			if (isFiring)
//			{
//				CanFire = true;
//				if (FireLife == 0)
//				{
//					isFiring = false;
//					FireLife = 5;
//				}
//				FireBallSpawnPoint = PlayerSprite.getPosition();
//				AdjustSpawnPoint(FireBallSpawnPoint, Direction);
//				FireBall.setPosition(FireBallSpawnPoint);
//				FireLife--;
//			}
//			Vector2f PlayerPosition = PlayerSprite.getPosition();
//			cout << "Player Position : " << PlayerPosition.x << " " << PlayerPosition.y;
//			cout << "\tSpawn Position : " << FireBallSpawnPoint.x << " " << FireBallSpawnPoint.y << endl;
//		}
//		PlayerControl(PlayerSprite, Direction, FireBallSpawnPoint);
//		window.clear();
//		window.draw(Background);
//		window.draw(PlayerSprite);
//		if (CanFire == true && isFiring == true)
//		{
//			window.draw(FireBall);
//			cout << "FIRE!" << endl;
//		}
//		window.display();
//	}
//	return 0;
//}
//
////#include"SFML/Graphics.hpp"
////#include<iostream>
////
////using namespace sf;
////using namespace std;
////
////int main()
////{
////	RenderWindow window(VideoMode(800, 600), "TESTS");
////
////	CircleShape circle(10);
////
////	Font font;
////	if (!font.loadFromFile("Font.ttf"))
////	{
////		cout << "Invalid Font!" << endl;
////	}
////
////	Text text;
////	text.setFont(font);
////	text.setFillColor(Color::Red);
////	text.setCharacterSize(100);
////	text.setString("HELLO WORLD");
////
////	while (window.isOpen())
////	{
////		Event event;
////		while (window.pollEvent(event))
////		{
////			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
////				window.close();
////		}
////		window.clear();
////		window.draw(text);
////		window.display();
////	}
////	return 0;
////}