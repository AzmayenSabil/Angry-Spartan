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

class SpartanAttackAnimation
{

public:

	SpartanAttackAnimation();
	~SpartanAttackAnimation();

	IntRect currentFrameHeavyAttack;

	void updateCloseQuarterAttackAnimation(Sprite *playerSprite, string type, float deltaTime);

private:

	Texture heavyAttackTexture;
	Sprite heavyAttackSprite;

	float totalTime;
	float switchTime;

};

