#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"UI.h"

using namespace sf;

void MainMenu(RenderWindow &window);

void Gameplay(RenderWindow &window);

void HowToPlay(RenderWindow &window);

void GameOver(RenderWindow &window, UI &UIObj);