#include "Swordsman.h"

Swordsman::Swordsman(Vector2f location)
{
	this->name = "Swordsman";

	this->texture.loadFromFile("images/AttackingSpartanAnimation.png");
	this->currentFrame = IntRect(0, 0, 64, 48);

	randomX = rand() % 406 + 380;

	this->sprite.setScale(-1.25f, 1.25f);
	this->sprite.setPosition(randomX, 267.f); // x = 748.f
	this->sprite.setColor(Color::Red);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setPosition(location);

	this->health = 100;
	this->maxHealth = 100;

	this->scoreIfKilled = 5;

	this->updateMovementX = 3;
	this->updateMovementY = 0.65;

	this->canMove = true;

	this->damage = 3; //5

	//this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 64, 48), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));


	this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 64, 48), IntRect(0, 192, 64, 48), IntRect(), 0.f, 384.f, 0.f, 0.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.25f, 1.25f));
	this->healthBar = new HealthBar();

	this->activationRange = 250;
	this->combatRange = Vector2f(100.f, 10.f);
	this->value = 1;

	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
	attackBuffer.loadFromFile("sounds/knife stab.wav");
	attackSound.setVolume(20);

}

Swordsman::~Swordsman()
{
}

void Swordsman::updateAnimation()
{
}



void Swordsman::attack()
{
}



