#include<iostream>
#include"MenuFunctions.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "PHOENYX V4.0", Style::Fullscreen);
	window.setFramerateLimit(60);

	Music BackGroundMusic;
	BackGroundMusic.setLoop(true);
	BackGroundMusic.setVolume(100);
	if (!BackGroundMusic.openFromFile("Music/BGM.wav"))
	{
		cout << "Cannot Load BackGround Music!" << endl;
	}

	BackGroundMusic.play();

	MainMenu(window);
	return 0;
}