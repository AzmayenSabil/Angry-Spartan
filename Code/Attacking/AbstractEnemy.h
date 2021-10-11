#pragma once

//#include "CloseQuarterEnemy.h"
//#include "RangedEnemy.h"
#include "Animation.h"
#include "HealthBar.h"
#include "Collider.h"
#include "Projectile.h"

//#include "Projectiles.h"

#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include <string.h>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

class AbstractEnemy
{
public:

	AbstractEnemy();
	~AbstractEnemy();

	Texture texture;
	Sprite sprite;
	Texture attackTexture;//not needed ig
	Sprite attackSprite;  //not needed ig

	IntRect currentFrame;
	IntRect currentFrameAttacking; // not needed ig

	Vector2f velocity;
	float speed;

	float randomX;
	float randomMovementX;

	bool faceRight;
	bool isWalking = true;
	bool isAttacking = false;
	float deltaTime;

	int maxHealth;

	void updateMovement(Sprite spartanSprite, float deltaTime);

	void render(RenderTarget& target);

	//void initEnemy();

	int getHealth() { return this->health; }

	bool isDead() { return health <= 0; };

	//virtual void enemyAttack(Sprite target);

	Vector2f getPositon() { return this->sprite.getPosition(); }

	Animation *animation;
	Animation *attackAnimation;
	//Animation animation = Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 64, 48), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	HealthBar *healthBar;
	void updateHealthBar(int maxHealth);

	virtual void updateAnimation() = 0;

	int dealDamage();

	Sprite getSprite() { return sprite; }

	virtual void attack() = 0;
	Projectile shoot(Vector2f distance);

	string getName();

	int getScore() { return this->scoreIfKilled; }

	void takeDamage(int damage) { this->health -= damage; }

	Collider GetCollider() {
		return Collider(sprite);
	}

	void onCollision(Vector2f direction);

	void freeze() { this->isActive = false; }
	void unfreeze() { this->isActive = true; }

	void checkIfActive(float distance);

	Vector2f getCombatRange() { return this->combatRange; }

	void die();

	bool dropPickup();

	bool isActive = false;

	bool isAlive() { return this->health > 0; }

protected:

	void setLocation(Vector2f location) { this->sprite.setPosition(location); }
	int updateMovementX;
	float updateMovementY;

	bool canMove;

	int health;
	int damage;
	int scoreIfKilled;

	void setTexture();


	string name;

	Vector2f location;

	//bool faceRight;

	bool idle = true;

	bool isMidAir = true;



	//float range = 0;

	float activationRange = 0;
	Vector2f combatRange = Vector2f(0.f, 0.f);

	int value = 0;

	SoundBuffer attackBuffer;
	Sound attackSound;
};



