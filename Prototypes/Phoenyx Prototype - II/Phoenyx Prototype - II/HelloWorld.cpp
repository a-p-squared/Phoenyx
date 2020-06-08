#include<iostream>
#include<SFML/Graphics.hpp>
#include<Box2D/Box2D.h>

using namespace std;
using namespace sf;

b2Vec2 Gravity(0, - 9.8);
b2World Batworld(Gravity);

int main()
{
	RenderWindow window(VideoMode(800, 600), "Box2D Test");

}

//#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
//
//
//const float SCALE = 30.f;
//const float DEG = 57.29577f;
//
//b2Vec2 Gravity(0.f, 9.8f);
//b2World World(Gravity);
//
//
//void setWall(int x, int y, int w, int h)
//{
//	b2PolygonShape gr;
//	gr.SetAsBox(w / SCALE, h / SCALE);
//	b2BodyDef bdefw;
//	bdefw.position.Set(x / SCALE, y / SCALE);
//	b2Body *b_ground = World.CreateBody(&bdefw);
//	b_ground->CreateFixture(&gr, 1);
//}
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Red Ball C++");
//	window.setFramerateLimit(70);
//
//	sf::Texture t, t1, t2, t3, t4, t5, t6;
//	t.loadFromFile("images/ground.png");
//	t1.loadFromFile("images/player.png");
//	t2.loadFromFile("images/objects1.png");
//	t3.loadFromFile("images/objects2.png");
//	t4.loadFromFile("images/platform.png");
//	t5.loadFromFile("images/flag.png");
//	t6.loadFromFile("images/back.png");
//
//	t1.setSmooth(true);
//	t2.setSmooth(true);
//	t3.setSmooth(true);
//
//	sf::Sprite sGround(t), sPlayer(t1), sBox(t2), sStone(t2), sSwing(t3), sPlatform(t4), sFlag(t5), sBackground(t6);
//
//	sBox.setTextureRect(sf::IntRect(81, 0, 61, 61));   sBox.setOrigin(30, 30);
//	sPlayer.setTextureRect(sf::IntRect(0, 160, 32, 32)); sPlayer.setOrigin(16, 16);
//	sSwing.setTextureRect(sf::IntRect(378, 0, 28, 242)); sSwing.setOrigin(20, 121);
//	sStone.setTextureRect(sf::IntRect(0, 0, 80, 80)); sStone.setOrigin(40, 40);
//
//	sGround.setPosition(0, 320);
//	sFlag.setPosition(587, 19);
//
//	/////////box2d///////////
//	setWall(400, 490, 2000, 10);
//	setWall(400, 0, 2000, 1);
//	setWall(55, 438, 64, 60);
//	setWall(710, 435, 100, 60);
//	setWall(158, 224, 33, 10);
//	setWall(608, 114, 33, 10);
//
//
//	b2PolygonShape shape;
//	shape.SetAsBox(30 / SCALE, 30 / SCALE);
//
//	b2BodyDef bdef;
//	bdef.type = b2_dynamicBody;
//
//	for (int i = 0; i < 3; i++)
//	{
//		bdef.position.Set(20, 10);
//		b2Body *body = World.CreateBody(&bdef);
//		body->CreateFixture(&shape, 2);
//		body->SetUserData((void *)("box"));
//	}
//
//	bdef.position.Set(5, 14);
//	b2Body *body = World.CreateBody(&bdef);
//	body->CreateFixture(&shape, 2);
//	body->SetUserData((void *)("box"));
//
//	///////////////////////
//	bdef.position.Set(2, 2);
//	b2CircleShape circle;
//	circle.m_radius = 16 / SCALE;
//	b2Body *playerBody = World.CreateBody(&bdef);
//	playerBody->CreateFixture(&circle, 2);
//	playerBody->SetUserData((void *)("player"));
//
//	/////////////////////////
//	bdef.position.Set(5, 1);
//	circle.m_radius = 40 / SCALE;
//	b2Body *b = World.CreateBody(&bdef);
//	b->CreateFixture(&circle, 8);
//	b->SetUserData((void *)("stone"));
//
//	/////////////////////////
//	bdef.position.Set(11, 15);
//	bdef.angle = 90 * DEG;
//	b = World.CreateBody(&bdef);
//	shape.SetAsBox(5 / SCALE, 120 / SCALE);
//	b->CreateFixture(&shape, 1);
//	circle.m_radius = 2 / SCALE;
//	circle.m_p.Set(-20 / SCALE, 0);
//	b->CreateFixture(&circle, 1);
//	b->SetUserData((void *)("swing"));
//
//
//	while (window.isOpen())
//	{
//		sf::Event e;
//		while (window.pollEvent(e)) { if (e.type == sf::Event::Closed) window.close(); }
//		World.Step(1 / 60.f, 8, 3);
//		/////check if onGround//////
//		bool onGround = 0;
//		b2Vec2 pos = playerBody->GetPosition();
//		pos.y += 17 / SCALE;
//		for (b2Body* it = World.GetBodyList(); it != 0; it = it->GetNext())
//			for (b2Fixture *f = it->GetFixtureList(); f != 0; f = f->GetNext())
//				if (f->TestPoint(pos))  onGround = true;
//		/////////////////////////////
//
//		b2Vec2 Skorost = playerBody->GetLinearVelocity();
//		float  angVel = playerBody->GetAngularVelocity();
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) if (Skorost.x < 10) { playerBody->ApplyForceToCenter(b2Vec2(40, 0), 1); if (angVel < 15)  playerBody->ApplyTorque(10, 1); }
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  if (Skorost.x > -10) { playerBody->ApplyForceToCenter(b2Vec2(-40, 0), 1); if (angVel > -15)  playerBody->ApplyTorque(-10, 1); }
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) if (onGround) playerBody->ApplyForceToCenter(b2Vec2(0, -1200), 1);
//		//////////Draw///////////////
//		window.draw(sBackground);
//		window.draw(sGround);
//		window.draw(sFlag);
//
//		sPlatform.setPosition(100, 200);	window.draw(sPlatform);
//		sPlatform.setPosition(550, 90);	window.draw(sPlatform);
//
//
//		for (b2Body* it = World.GetBodyList(); it != 0; it = it->GetNext())
//		{
//			b2Vec2 pos = it->GetPosition();
//			float angle = it->GetAngle();
//
//			if (it->GetUserData() == "box")
//			{
//				sBox.setPosition(pos.x*SCALE, pos.y*SCALE);
//				sBox.setRotation(angle*DEG);
//				window.draw(sBox);
//			}
//
//			if (it->GetUserData() == "player")
//			{
//				sPlayer.setPosition(pos.x*SCALE, pos.y*SCALE);
//				sPlayer.setRotation(angle*DEG);
//				window.draw(sPlayer);
//			}
//
//			if (it->GetUserData() == "swing")
//			{
//				sSwing.setPosition(pos.x*SCALE, pos.y*SCALE);
//				sSwing.setRotation(angle*DEG);
//				window.draw(sSwing);
//			}
//
//			if (it->GetUserData() == "stone")
//			{
//				sStone.setPosition(pos.x*SCALE, pos.y*SCALE);
//				sStone.setRotation(angle*DEG);
//				window.draw(sStone);
//			}
//		}
//
//
//		window.display();
//	}
//
//	return 0;
//}
