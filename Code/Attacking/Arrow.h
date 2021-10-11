//this function is depreciated 

//please use projectile instead
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

class Arrow
{

public:
	Arrow();
	~Arrow();

	Texture arrowTexture;
	Sprite arrowSprite;

	int direction;

	Collider GetCollider() {
		return Collider(arrowSprite);
	}
	//move and draw function not understood
	void Move();
	void Draw(RenderTarget & target);
};

