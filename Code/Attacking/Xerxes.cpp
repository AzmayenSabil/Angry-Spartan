#include "Xerxes.h"

Xerxes::Xerxes(Vector2f location)
{
	this->name = "Xerxes";

	this->texture.loadFromFile("images/Xerxes idle.png");
	this->currentFrame = IntRect(0, 0, 160, 160);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(location); // 812.f = x

	//this->arrows = Projectiles();


	//this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 97, 134), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	this->animation = new Animation(0.f, 200.f, IntRect(0, 0, 160, 160), IntRect(), IntRect(), IntRect(), 0.f, 160.f, 0.f, 0.f, 0.f, 0.f, Vector2f(160, 160), Vector2f(.5f, .5f));

	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
}

Xerxes::~Xerxes()
{

}

string Xerxes::getName()
{
	return this->name;
}

void Xerxes::update()
{

}

void Xerxes::render(RenderTarget & target)
{
	target.draw(this->sprite);
}
