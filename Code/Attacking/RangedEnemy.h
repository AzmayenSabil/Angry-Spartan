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

class RangedEnemy
{
public:

	RangedEnemy();
	~RangedEnemy();

	Texture rangedEnemyTexture;
	Sprite rangedEnemySprite;

	IntRect currentFrame;
	Vector2f velocity;
	float speed;

	float randomX;
	float randomMoveX;

	int health;

	void updateMovement(Sprite spartanSprite);

	void renderrangedEnemy(RenderTarget& target);

private:

	void initEnemy();

};

