#pragma once
#include<vector>
#include"MenuFunctions.h"
#include"Collision.h"
#include"Player.h"
#include"Archer.h"
#include"UI.h"

#define MaxArchers 10

int ArcherCount = 0;
vector<Archer*> archers;

Time ArcherPreviousSpawn;
Time ArcherNextSpawn;

Time PlayerCollisionTime;
Time PlayerPreviousCollisionTime;

void SpawnArcher(Clock &GameClock)
{
	Archer* archer;
	ArcherNextSpawn = GameClock.getElapsedTime();
	if (ArcherNextSpawn.asSeconds() - ArcherPreviousSpawn.asSeconds() >= 3.f && ArcherCount < MaxArchers)
	{
		archer = new Archer;
		archers.push_back(archer);
		ArcherPreviousSpawn = ArcherNextSpawn;
		ArcherCount++;
	}
}

void ArcherMovement()
{
	for (int c = 0; c < ArcherCount; c++)
	{
		archers[c]->ArcherMove();
	}
}

void ArcherDraw(RenderWindow &window)
{
	for (int c = 0; c < ArcherCount; c++)
	{
		window.draw(archers[c]->ArcherSprite);
	}
}

void ArcherKill(Sprite &FireBall, bool &isFiring, UI &UIobj)
{
	for (int c = 0; c < archers.size(); c++)
	{
		if(Collision::PixelPerfectTest(archers[c]->ArcherSprite, FireBall))
		{
			UIobj.Scorevalue += 100;
			archers.erase(archers.begin() + c);
			isFiring = false;
			ArcherCount--;
		}
	}
}

void ArcherShoot(Sprite &Phoenix, Clock &GameClock)
{
	for (int c = 0; c < ArcherCount; c++)
	{
		archers[c]->ArcherShoot(Phoenix, GameClock);
	}
}

void ArrowMovement(Clock &GameClock)
{
	for (int c = 0; c < ArcherCount; c++)
	{
		if (archers[c]->isShooting)
		{
			archers[c]->ArrowMovement(GameClock);
		}
	}
}

void ArrowDraw(RenderWindow &window)
{
	for (int c = 0; c < ArcherCount; c++)
	{
		if (archers[c]->isShooting)
		{
			window.draw(archers[c]->ArrowSprite);
		}
	}
}

void PlayerKill(Sprite &Player, int &Life, Clock &GameClock)
{
	for (int c = 0; c < archers.size(); c++)
	{
		if (Collision::PixelPerfectTest(archers[c]->ArrowSprite, Player))
		{
			PlayerCollisionTime = GameClock.getElapsedTime();
			if (PlayerCollisionTime.asSeconds() - PlayerPreviousCollisionTime.asSeconds() >= 2.f)
			{
				archers[c]->isShooting = false;
				archers[c]->ArrowHit.play();
				if (Life > 0)
					Life--;
				PlayerPreviousCollisionTime = GameClock.getElapsedTime();
			}
		}
	}
}