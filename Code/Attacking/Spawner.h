#pragma once

#include "Enemy.h"
#include "Swordsman.h"
#include "Archer.h"
#include "Brute.h"
#include "Immortal.h"

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
class Spawner
{
public:
	Spawner();
	~Spawner();

	//enemies should spawn when player reaches a certain position
	void spawnEnemy(int number, String type, vector <Enemy *>& list);

	void spawnEnemy1(int number, String type, vector <AbstractEnemy *>& list, Vector2f location);

	vector <Enemy *> closeQuarterEnemyList; // Close quarter enemy vector
	vector <Enemy *> rangedEnemyList; // Ranged Eney vector

	//this functions spawns the enemies
	//void spawnCloseQuarterEnemy(int numberOfEnemy, vector <Enemy *>& closeQuarterEnemyList);
	//void spawnRangedEnemy(int numberOfEnemy, vector <Enemy *>& rangedEnemyList);


private:

};

