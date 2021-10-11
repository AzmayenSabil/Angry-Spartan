#include "Archer.h"

Archer::Archer(Vector2f location)
{
	this->name = "Archer";

	this->texture.loadFromFile("images/archersprite.png");
	this->currentFrame = IntRect(0, 0, 97, 134);

	randomX = rand() % 2000 + 406;

	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(-0.5f, 0.5f);
	this->sprite.setPosition(location); // 812.f = x
	

	//cout << randomX << endl;
	this->health = 100;
	this->maxHealth = 100;

	this->scoreIfKilled = 10;

	this->updateMovementX = 2;
	this->updateMovementY = .65;

	this->canMove = false;

	//this->arrows = Projectiles();


	//this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 97, 134), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	this->animation = new Animation(0.f, 200.f, IntRect(0, 0, 97, 134), IntRect(0, 0, 97, 134), IntRect(), IntRect(0, 0, 97, 134), 0.f, 376.f, 0.f, 0.f, 0.f, 388.f, Vector2f(97, 134), Vector2f(.5f, .5f));
	this->healthBar = new HealthBar();

	this->damage = 4; //7
	this->activationRange = 500; //700
	this->combatRange = Vector2f(500.f, 300.f); //700,500
	this->value = 2;

	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
}

Archer::~Archer()
{
}

void Archer::updateAnimation()
{
	if (faceRight) {
		animation->attack(&sprite, false, deltaTime);
		cout << "spartan on right of archer" << endl;
	}
	else {
		animation->attack(&sprite, true, deltaTime);
		cout << "spartan on left of archer" << endl;
	}
}

void Archer::attack()
{

}

Projectile Archer::shoot()
{
	//this->animation->attack();
	return Projectile("Arrow");
}


