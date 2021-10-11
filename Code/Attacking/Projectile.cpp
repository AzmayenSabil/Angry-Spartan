#include "Projectile.h"

Projectile::Projectile()
{
	attackBuffer.loadFromFile("sounds/sword_hit_shield.wav");
	attackSound.setBuffer(attackBuffer);
	attackSound.setVolume(20);
}

Projectile::Projectile(String type)
{
	this->chooseType(type);
	velocity.y = 0;
	attackBuffer.loadFromFile("sounds/sword_hit_shield.wav");
	attackSound.setBuffer(attackBuffer);
	attackSound.setVolume(20);
}

Projectile::Projectile(String type, float velocity)
{
	this->velocity.x = velocity;
	this->chooseType(type);
	attackBuffer.loadFromFile("sounds/sword_hit_shield.wav");
	attackSound.setBuffer(attackBuffer);
	attackSound.setVolume(20);
}

Projectile::Projectile(Texture texture, IntRect rect, Vector2f size, bool isFriendly, float damage)
{
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(rect);
	this->sprite.setScale(size);
	this->damage = damage;
	this->isFriendly = isFriendly;
	attackBuffer.loadFromFile("sounds/sword_hit_shield.wav");
	attackSound.setBuffer(attackBuffer);
	attackSound.setVolume(20);
}

Projectile::~Projectile()
{
}

void Projectile::move()
{
	if (this->isGravity)
	{
		//cout << velocity.x << velocity.y << endl;
		velocity.y += 981.0f;
		//velocity = Vector2f(velocity.x / 1000, velocity.y / 100);
		if (this->isLeftDirected == true) {
			sprite.setScale(1 / 18.f, 1 / 18.f);
			//sprite.move(-3.f, 0.f);

			sprite.move(-velocity.x / 20000, velocity.y / 30000);
			//cout << velocity.x << velocity.y << endl;
		}

		if (this->isLeftDirected == false) {
			sprite.setScale(-1 / 18.f, 1 / 18.f);
			//sprite.move(3.f, 0.f);
			sprite.move(velocity.x / 20000, velocity.y / 30000);
			//cout << velocity.x << velocity.y << endl;
		}
	}
	else
	{
		if (this->isLeftDirected == true) {
			sprite.setScale(1 / 18.f, 1 / 18.f);
			sprite.move(-3.f, 0.f);

			//sprite.move(-velocity.x / 20000, velocity.y / 30000);
			//cout << velocity.x << velocity.y << endl;
		}

		if (this->isLeftDirected == false) {
			sprite.setScale(-1 / 18.f, 1 / 18.f);
			sprite.move(3.f, 0.f);
			//sprite.move(velocity.x / 20000, velocity.y / 30000);
			//cout << velocity.x << velocity.y << endl;
		}
	}

}

void Projectile::draw(RenderTarget & target)
{
	target.draw(sprite);
}

void Projectile::hit(Sprite target)
{
	if (this->sprite.getGlobalBounds().intersects(target.getGlobalBounds())) {


	}
}

void Projectile::dealDamage()
{
	attackSound.play();
	//return this->damage;
}

void Projectile::chooseType(String type)
{
	if (type == "Arrow")
	{
		this->texture.loadFromFile("images/arrow.png");
		this->sprite.setTexture(texture);
		this->sprite.setTextureRect(IntRect(0, 0, 531, 1505));
		this->sprite.setScale(Vector2f(1 / 18.f, 1 / 18.f));
		this->damage = 5.f; // 10
		this->isFriendly = false;
	}
}



