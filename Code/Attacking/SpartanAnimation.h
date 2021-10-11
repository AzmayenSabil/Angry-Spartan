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

class SpartanAnimation
{
public:
	SpartanAnimation();
	~SpartanAnimation();

	void updateAnimation(Sprite *playerSprite, string type, float deltaTime);

	IntRect currentFrameWalking;
	IntRect currentFrameJumping;
	IntRect currentFrameIdle;

private:
	
	float totalTime;
	float switchTime;
};

