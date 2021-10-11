#pragma once

#include "Spartan.h"

#include "Enemies.h" // from Enemies.cpp we call the spawn.cpp class


//#include "CloseQuarterEnemyAttack.h"
//#include "RangedEnemyAttack.h"

#include "Platform.h"
#include "Platforms.h"

#include "UIElements.h"

#include "Projectile.h"
#include "Projectiles.h"

#include "AbstractEnemy.h"

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
#include <thread>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>


using namespace std;
using namespace sf;

class Combat
{
public:
	//Arrow arrow = Arrow();
	Projectile projectile = Projectile("Arrow");
	Projectiles projectiles = Projectiles();

	void closeEnemyAttack(Spartan* spartan, Enemy* enemy, float deltaTime);
	void rangedEnemyAttack(Spartan * spartan, Enemy * rangedEnemy, vector<Projectile> &projectiles, float deltaTime);

	void rangedEnemyAttack1(Spartan * spartan, AbstractEnemy * rangedEnemy, vector<Projectile> &projectiles, float deltaTime);

	void hitWithProjectile(vector<Projectile> &projectiles, Spartan &spartan);
	void decreaseHealthOfSpartan(Spartan *spartan);

	void attack(Spartan* spartan, Enemies* enemies, vector<Projectile> &projectiles, float deltaTime);
	void spartanAttack(Spartan* spartan, Enemies* enemies, vector<Projectile> &projectiles, float deltaTime, int* score);
	void spartanCloseAttack(Spartan *spartan, AbstractEnemy *enemy, float deltaTime);

	void update(Spartan* spartan, Enemies* enemies, vector<Projectile> &projectiles, float deltaTime, int* score);

	void enemyCloseAttack(Spartan* spartan, AbstractEnemy* enemy, float deltaTime);

	Vector2f dropPickup();
	vector<Vector2f>pickupLocations;

	int getPickupsNum() { return this->pickupLocations.size(); }

private:

	//ATTACKING
	bool attackedLightly;
	bool attackedHeavily;
	int countMouseClick;
	int countKeyClick;

	bool isSpartanAttackFinished = false;
	bool isSpartanIdle = true;
	bool isPlayerBlocking = false;

	//float totalTime;
	//float switchTime;

	//Event keyEvent;
	Event mouseEvent;

	float totalTime = 0;
	float switchTime = 200.f;

	void spartanHeavyAttack(Spartan* spartan, Enemies* enemies);

	void spartanLightAttack(Spartan* spartan, Enemies* enemies);

	bool removeDeadEnemy(Spartan * spartan, Enemies* enemies, int index);

	int findClosestEnemy(Spartan * spartan, Enemies* enemies);

	int dropPickups = 0;





	Vector2f pickupLocation;

	void setPickup(Vector2f location) { this->pickupLocations.push_back(location); }

	float arrowDamage = 5;

	Spartan *spartan;

};

