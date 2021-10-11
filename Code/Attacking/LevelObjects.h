#pragma once

#include "Spartan.h"
#include "GameMode.h"
#include "Levels.h"

#include "Enemies.h" // from Enemies.cpp we call the spawn.cpp class
#include "Enemy.h"
//#include "Xerxes.h"

#include "Platforms.h"

#include "UIElements.h"
#include "Combat.h"
#include "Projectile.h"
#include "Wall.h"
#include "Checkpoints.h"
//#include "HealthPickup.h"
#include "Pickups.h"


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
class LevelObjects
{
private:
	float defaultY = 260.f;
public:
	LevelObjects(int level, float defaultY);
	~LevelObjects();

	Platforms platforms = Platforms();
	Enemies enemies = Enemies(defaultY);
	//Xerxes xerxes = Xerxes(Vector2f(5.f,260.f));

	GameMode gameMode = GameMode(912.222f, 512.f);
	Levels levels = Levels(912.222f, 512.f);

	void chooseLevel(int level);

	Enemies getEnemies();
	Platforms getPlatforms();

	Texture bgTexture;
	Sprite bgSprite;

	void renderObjects(RenderTarget& target);

	Checkpoints checkpoints = Checkpoints();

	//Wall wall1 = Wall(IntRect(0, 0, 90, 180), Vector2f(-0.0f, 230.f), Vector2f(1 / 1.25f, 20 / 2.5f));

	void update(Spartan spartan);

	void addPickups(Vector2f location);

private:

	Pickups pickups = Pickups();
	int level;

	void initBackground(IntRect rect, Vector2f pos, Vector2f resize);
	void initLevel0Objects();
	void initLevel1Objects();
	void initLevel2Objects();
	void initLevel3Objects();

	
};

