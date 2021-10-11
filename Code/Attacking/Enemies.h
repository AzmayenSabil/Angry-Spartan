#pragma once

#include "AbstractEnemy.h"
#include "Enemy.h"
#include "Spawner.h"
#include "UIElements.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

//this is a container class to keep all the enemies

class Enemies
{
public:
	Enemies(float defaultY);
	~Enemies();

	vector <Enemy *> swordsmen; // Close quarter enemy vector
	vector <Enemy *> archers; // Ranged Eney vector
	vector <Enemy *> brutes; // Ranged Eney vector

	vector<AbstractEnemy* > enemyList;

	void chooseLevel(int level);

	void updateMovements(Sprite spartan, float deltaTime);
	void updateHealthBars();
	void render(RenderTarget & target);

	void clearEnemies();

	void setDefaultY(float defaultY) { this->defaultY = defaultY; }

private:
	Spawner spawner = Spawner();

	void initLevel1Enemies();
	void initLevel2Enemies();
	void initLevel3Enemies();

	float defaultY;

};

