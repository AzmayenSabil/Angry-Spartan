#pragma once

#include "AbstractEnemy.h"

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
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Swordsman : public AbstractEnemy
{
public:
	Swordsman(Vector2f location);
	~Swordsman();

	void updateAnimation();


	void attack();


private:
	SoundBuffer stabBuffer;
	Sound stabSound;

};

