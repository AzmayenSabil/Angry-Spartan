#pragma once

#include "Spartan.h"

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

class Pickup
{
public:
	Pickup();
	~Pickup();

	virtual void doSomething(Spartan spartan) = 0;

	void render(RenderTarget & target);

	Vector2f getPosition() { return this->sprite.getPosition(); }

protected:
	Sprite sprite;
	Texture texture;
	int amount;
};

