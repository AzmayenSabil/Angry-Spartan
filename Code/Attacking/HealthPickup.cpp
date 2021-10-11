#include "HealthPickup.h"

HealthPickup::HealthPickup(Vector2f location)
{
	
	this->amount = 200;
	this->texture.loadFromFile("images/red-orb.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(IntRect(0, 0, 600, 600));
	this->sprite.setScale(1 / 40.f, 1 / 40.f);
	//this->sprite.setPosition(100.f, 260.f);
	this->sprite.setPosition(location);
	
}

HealthPickup::~HealthPickup()
{
}

void HealthPickup::doSomething(Spartan spartan)
{
	cout << "Health increased" << endl;
	spartan.increaseHealth(this->amount);
}
