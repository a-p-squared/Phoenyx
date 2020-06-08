#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class UI
{
private:
	String ScoreString = "SCORE\n";
	String LivesString = "LIFE LEFT\n";
public:
	Font GameFont;
	Text Score;
	Text Print;
	Text LivesLeft;
	int Scorevalue = 0;
	int lives = 3;

	UI()
	{
		ScoreString.insert(ScoreString.getSize(), to_string(Scorevalue));
		LivesString.insert(LivesString.getSize(), to_string(lives));

		if (!GameFont.loadFromFile("GameFont.ttf"))
		{
			cout << "Failed To Load Game Font!" << endl;
		}

		Print.setFont(GameFont);

		Score.setFont(GameFont);
		Score.setString(ScoreString);
		Score.setPosition(0, 0);
		Score.setScale(2, 2);

		LivesLeft.setFont(GameFont);
		LivesLeft.setString(LivesString);
		LivesLeft.setPosition(1600, 0);
		LivesLeft.setScale(2, 2);
	}

	void UpdateScore()
	{
		ScoreString = "SCORE\n";
		ScoreString.insert(ScoreString.getSize(), to_string(Scorevalue));
		Score.setString(ScoreString);
	}

	void UpdateLife()
	{
		String LivesString = "LIFE LEFT\n";
		LivesString.insert(LivesString.getSize(), to_string(lives));
		LivesLeft.setString(LivesString);
	}
};