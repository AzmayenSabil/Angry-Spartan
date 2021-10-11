#pragma once

#include "Collider.h"

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

class Platform
{
public:
	Platform(Texture* bodyTexture, IntRect rect, Vector2f pos, Vector2f resize);
	~Platform();

	Collider GetCollider() {
		return Collider(bodySprite);
	}

	void draw(RenderTarget & target);

	Sprite getSprite();

	Sprite bodySprite;
	
};

