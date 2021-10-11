#include "Immortal.h"

Immortal::Immortal(Vector2f location)
{
	this->name = "Immortal";

	this->texture.loadFromFile("images/Immortal attack.png");
	this->currentFrame = IntRect(0, 0, 190, 136);

	randomX = rand() % 2000 + 406;

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(-0.4f, 0.4f);
	this->sprite.setPosition(location); // 812.f = x


	//cout << randomX << endl;
	this->health = 500;
	this->maxHealth = 500;

	this->scoreIfKilled = 50;

	this->updateMovementX = 2;
	this->updateMovementY = .65;

	this->canMove = true;

	//this->arrows = Projectiles();


	//this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 97, 134), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 190, 136), IntRect(), IntRect(), 0.f, 570.f, 0.f, 0.f, 0.f, 0.f, Vector2f(190, 136), Vector2f(.4f, .4f));
	//this->attackAnimation = new Animation(0.f, 200.f, IntRect(), IntRect(), IntRect(), IntRect(0, 0, 160, 160), 0.f, 0.f, 0.f, 0.f, 0.f, 570.f, Vector2f(190.f, 190.f), Vector2f(.75f, .75f));
	this->healthBar = new HealthBar();

	this->damage = 50;
	this->activationRange = 300;
	this->combatRange = Vector2f(200.f, 20.f);
	this->value = 8;


	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
}

Immortal::~Immortal()
{
}

void Immortal::updateAnimation()
{
	
}

void Immortal::attack()
{
	//attack animation here
	if (faceRight) {
		//this->animation->walk(&this->sprite, false, deltaTime);
		cout << "spartan on right of brute" << endl;
	}
	else {
		//this->animation->walk(&this->sprite, true, deltaTime);
		cout << "spartan on left of brute" << endl;
	}
}

Projectile Immortal::shoot()
{
	return Projectile();
}

void Immortal::jump()
{
}
