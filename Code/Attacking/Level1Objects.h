#pragma once

#include "Spartan.h"

#include "Enemies.h" // from Enemies.cpp we call the spawn.cpp class
#include "Enemy.h"

#include "Platforms.h"

#include "UIElements.h"
#include "Combat.h"
#include "Projectile.h"
#include "LevelObjects.h"


#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include <sstream> 
#include <fstream>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>


using namespace std;
using namespace sf;
class Level1Objects : public LevelObjects
{
public:
	Level1Objects();
	~Level1Objects();

	Platforms platforms = Platforms();
	Enemies enemies = Enemies();

private:
	
};

