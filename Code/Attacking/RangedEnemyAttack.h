#pragma once

#include "Spartan.h"

#include "Arrow.h"

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

class RangedEnemyAttack
{
public:

	RangedEnemyAttack();
	~RangedEnemyAttack();

	//Arrow arrow = Arrow();
	Projectile projectile = Projectile("Arrow");

	float totalTime;
	float switchTime;

	void attack(Spartan *spartan, Enemy* rangedEnemy, vector<Projectile> &projectiles, float deltaTime);
	void decreaseHealthOfSpartan(Spartan *spartan);
	bool checkSpartanDeadOrNot(Spartan *spartan);

};

