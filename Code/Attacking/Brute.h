#pragma once

#include "AbstractEnemy.h"
#include <thread>

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

class Brute : public AbstractEnemy
{
public:
	Brute(Vector2f location);
	~Brute();

	void updateAnimation();


	void attack();
};


