#pragma once

#include "Animation.h"

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

using namespace std;
using namespace sf;

class Leonidas
{
public:

	Leonidas(Vector2f location);
	~Leonidas();

	string name;
	string getName();

	Texture texture;
	Sprite sprite;

	IntRect currentFrame;

	Animation *animation;

	void update();
	void render(RenderTarget& target);

};

