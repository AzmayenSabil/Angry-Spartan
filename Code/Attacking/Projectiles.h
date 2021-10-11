#pragma once

#include "Collider.h"
#include "Projectile.h"
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
class Projectiles
{
public: 
	Projectiles();
	~Projectiles();

	vector <Projectile> list; // projectile container

	void hit(Sprite target);
};

