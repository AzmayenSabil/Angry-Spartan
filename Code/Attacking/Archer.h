#pragma once

#include "AbstractEnemy.h"
#include "Projectile.h"

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

class Archer : public AbstractEnemy
{
public:
	Archer(Vector2f location);
	~Archer();

	void updateAnimation();
	
	void attack();

	Projectile shoot();

private:

};


