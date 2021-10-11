#pragma once

#include "Collider.h"
#include "ScoreSystem.h"
#include "Enemy.h"
#include "Animation.h"
#include "TextChannel.h"


#include "SpartanAttack.h"

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
#include <SFML/Audio.hpp>

#include <dos.h> //for delay
#include <windows.h>
#include <thread>
#include <stdbool.h>


using namespace std;
using namespace sf;

class Spartan
{

private:

	IntRect currentFrame;

	void initPlayer();
	void initVariables();

	Vector2f velocity;
	bool canJump;
	bool faceRight;
	float jumpHeight;
	float speed;

	float switchTime;
	float totalTime;


	void chargeSpeed();

	bool idle = true;

	void updateHeavyAttackLocation();

	bool heavyAttackGoing = false;
	bool lightAttackGoing = false;

	SpartanAttack spartanAttack = SpartanAttack();

	TextChannel textChannel = TextChannel();

	int score = 0;

	int lightAttackDamage = 5;
	int heavyAttackDamage = 50; // 30

	bool isChargeAble();

	bool isBlocking = false;
	bool isCharging = false;
	bool verticalMoving = false;

	int rage = 0;
	int stamina = 20;

	void regenerateStamina();
	void regenerateHealth();
	Clock regenClock, chargeClock, rageClock;
	Time regenTime, chargeTime, rageTime;

	int maxStamina = 20;
	//int maxHealth = 100; //eta niche public kora ache
	int maxRage = 20;

	void rageMode();

	bool isRageOn = false;

	float takeDamageMultiplier = 1;

	float dealDamageMultiplier = 1;

	void reduceRage(int amount);

	SoundBuffer lightAttackBuffer, heavyAttackBuffer, swordBlockBuffer;
	Sound lightAttackSound, heavyAttackSound, swordBlockSound;

public:

	Spartan();
	~Spartan();


	//--------------COLLIDER CLASS------------//
	Collider GetCollider() {
		return Collider(spartanSprite);
	}

	/*Collider* GetCollider2() {
		return &Collider(spartanSprite);
	}*/
	//----------------------------------------//

	//SpartanAnimation spartanAnimation = SpartanAnimation();
	//spartanCloseQuarterAttack closeQuarterAttack = spartanCloseQuarterAttack();
	Animation animation = Animation(0.f, 200.f, IntRect(0, 0, 97, 134), IntRect(97, 0, 97, 134), IntRect(582, 0, 97, 134), IntRect(1164, 0, 97, 134), 97.f,
		582.f, 679.f, 1067.f, 1164.f, 1358.f, Vector2f(97.f, 134.f), Vector2f(0.5f, 0.5f));

	ScoreSystem scoreSystem = ScoreSystem();

	int health;
	int MAX_HEALTH = 5000;

	Texture spartanTextureSheet;
	Sprite spartanSprite;

	void updateMovement(float deltaTime);
	void updateAnimation(float deltaTime);
	//void updateCloseQuarterAttack(float deltaTime, Enemy *closeQuarter);
	void onCollision(Vector2f direction);

	Vector2f GetPosition() { return spartanSprite.getPosition(); }

	void render(RenderTarget & target);

	int getHealth() { return this->health; }

	Vector2f getPosition();

	bool checkIfDead();

	void takeDamage(float damage);

	//----new -----//

	float heavyAttack();

	void lightAttack();

	Sprite getSprite() { return spartanSprite; }

	void update(float deltaTime);

	bool block(float deltaTime);

	bool charge();

	void throwSpear();

	bool isIdle();

	bool isHorizontalMoving();

	bool isVerticalMoving();

	bool heavyAttacking = false;

	float heavyAttackLocation = -1;

	bool getHeavyAttackStatus() { return this->heavyAttackGoing; }
	bool getLightAttackStatus() { return this->lightAttackGoing; }

	void finishHeavyAttack();

	void finishLightAttack();

	void startHeavyAttack();

	void updateScore(int scored) { this->score += scored; }

	int dealLightAttackDamage() { return this->lightAttackDamage * this->dealDamageMultiplier; }
	int dealHeavyAttackDamage() { return this->heavyAttackDamage * this->dealDamageMultiplier; }

	int getScore() { return this->score; }

	void setPosition(float positionX) { this->spartanSprite.setPosition(positionX, 260.f); }

	void setHealth(int health) { this->health = health; }

	int getRage() { return this->rage; }

	void setRage(int rage) { this->rage = rage; }

	bool isRageFull() { return this->rage >= this->maxRage; }
	bool isRageEmpty() { return this->rage <= 0; }

	int getStamina() { return this->stamina; }

	void reduceStamina(int amount) { this->stamina -= amount; }
	void increaseStamina(int amount);

	void increaseHealth(int amount) { this->health += amount; }

	void setStamina(int stamina) { this->stamina = stamina; }

	bool isStaminaFull() { return this->stamina == 20; }
	bool isStaminaEmpty();

	void blockAttack(bool isDirectionRight);
};

