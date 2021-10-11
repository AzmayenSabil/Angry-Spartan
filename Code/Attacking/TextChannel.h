#pragma once

#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <dos.h> //for delay
#include <windows.h>
#include <thread>
#include <stdbool.h>


using namespace std;
using namespace sf;

class TextChannel
{
public:
	TextChannel();
	~TextChannel();

	vector <string> texts;
	vector <float> xPos;
	vector <float> yPos;

	Font font;
	Text text;

	void updateText(string text);
	void draw(RenderTarget & target, Vector2f pos, float x, float y);


};

