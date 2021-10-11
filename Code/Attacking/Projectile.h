#pragma once

#include "Collider.h"

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

using namespace std;
using namespace sf;

class Projectile
{

public:
	Projectile();
	Projectile(String type);
	Projectile(String type, float velocity);
	Projectile(Texture texture, IntRect rect, Vector2f size, bool isFriendly, float damage);
	~Projectile();

	//-------variables----------
	Texture texture;//maybe this is not needed
	Sprite sprite;

	bool isLeftDirected;	//true if goes to left, false if goes to right

	bool isFriendly;		//there will be friendly and non-friendly projectiles

	float damage = 5;	//this means the damage dealt when projectile hits






	//----functions--------




	Collider GetCollider() {
		return Collider(sprite);
	}

	//move and draw function not understood
	void move();
	void draw(RenderTarget & target);

	void hit(Sprite target);

	void setVelocityX(float velocityX) { this->velocity.x = velocityX; }

	void dealDamage();

	SoundBuffer attackBuffer;
	Sound attackSound;

	bool isGravity = false;

private:

	void chooseType(String type);

	Vector2f velocity;


};

