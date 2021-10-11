#pragma once

#include "CloseQuarterEnemy.h"
#include "Enemy.h"
#include "SpartanAttackAnimation.h"

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


class spartanCloseQuarterAttack
{

private:

	Sprite *spartan;
	Enemy *closeQuarterEnemy;

	//ATTACKING
	bool attackedLightly;
	bool attackedHeavily;
	int countMouseClick;
	int countKeyClick;

	float totalTime;
	float switchTime;

	//Event keyEvent;
	Event mouseEvent;


public:

	spartanCloseQuarterAttack();
	~spartanCloseQuarterAttack();

	void initVariables();

	SpartanAttackAnimation spartanAttackAnimation = SpartanAttackAnimation();

	//---SETTERS
	void setSpartan(Sprite *spartan);
	void setcloseQuarterEnemy(Enemy *closeQuarterEnemy);

	void closeQuarterAttack(float deltaTime);
	bool checkCloseQuarterDeadOrNot();

};

