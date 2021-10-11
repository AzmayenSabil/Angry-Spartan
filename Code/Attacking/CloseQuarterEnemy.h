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


using namespace std;
using namespace sf;

class CloseQuarterEnemy
{
public:

	CloseQuarterEnemy();
	~CloseQuarterEnemy();

	Texture closeQuarterTexture;
	Sprite closeQuarterSprite;

	IntRect currentFrame;
	Vector2f velocity;
	float speed;

	float randomX;
	float randomMovementX;

	int health;
	

	void updateMovement(Sprite spartanSprite);

	void renderCloseQuarter(RenderTarget& target);

private:

	void initEnemy();

};

