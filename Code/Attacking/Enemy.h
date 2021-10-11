#pragma once

#include "Animation.h"
#include "HealthBar.h"

//#include "Projectiles.h"


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

class Enemy
{

public:
	Enemy(String type);
	~Enemy();

	//CloseQuarterEnemy closeQuarter = CloseQuarterEnemy();
	//RangedEnemy rangedEnemy = RangedEnemy();

    //Projectiles arrows;

	Texture texture;
	Sprite sprite;

	IntRect currentFrame;
	Vector2f velocity;
	float speed;

	float randomX;
	float randomMovementX;

	int health;
	int damage;


	void updateMovement(Sprite spartanSprite, float deltaTime);

	void renderEnemy(RenderTarget& target);

	//void initEnemy();

	int getHealth(); 

	bool isDead();

	void enemyAttack(Sprite target);

	Vector2f getPositon();

	int score;

	Animation *animation;
	//Animation animation = Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 64, 48), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	HealthBar *healthBar;

	void updateAnimation();
	void updateHealthBar();

	int dealDamage();

	Sprite getSprite() { return sprite; }

private:

	//don't have a better name for these two
	//if u do please rename them
	//they are used in updatemovement when I use modulo with rand() function
	int updateMovementX;
	float updateMovementY;
	
	bool canMove;

	void chooseType(String type);

	void initSwordsman();
	void initArcher();
	void initHeavy();
	void initHybrid();


};

