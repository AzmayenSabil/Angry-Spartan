#pragma once

#include "Spartan.h"
#include "Enemy.h"

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

class CloseQuarterEnemyAttack
{

public:
	CloseQuarterEnemyAttack();
	~CloseQuarterEnemyAttack();

	void attack(Spartan *spartan, Enemy* closeQuarterEnemy, float deltaTime);
	bool checkSpartanDeadOrNot(Spartan *spartan);

private:

	float totalTime;
	float switchTime;

};

