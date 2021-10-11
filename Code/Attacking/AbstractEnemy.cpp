#include "AbstractEnemy.h"

AbstractEnemy::AbstractEnemy()
{

}

AbstractEnemy::~AbstractEnemy()
{
}

void AbstractEnemy::updateMovement(Sprite spartanSprite, float deltaTime)
{
	velocity.y += 981.0f*deltaTime;
	this->checkIfActive(abs(spartanSprite.getPosition().x - this->sprite.getPosition().x));
	if (this->canMove && this->isActive)
	{
		randomMovementX = rand() % this->updateMovementX + this->updateMovementY;

		if (spartanSprite.getPosition().x < this->sprite.getPosition().x) {
			this->sprite.move(-randomMovementX, 0.f); // following left
			this->animation->walk(&this->sprite, true, deltaTime);
		}

		if (spartanSprite.getPosition().x > this->sprite.getPosition().x) {
			this->sprite.move(randomMovementX, 0.f); // following right
			this->animation->walk(&this->sprite, false, deltaTime);
		}
		//isAttacking = false;
		//isWalking = true;

	}
	this->sprite.move(velocity*deltaTime);
}

void AbstractEnemy::render(RenderTarget & target)
{
	target.draw(this->sprite);
	this->updateHealthBar(this->maxHealth);
	this->healthBar->Draw(target);
}

void AbstractEnemy::updateHealthBar(int maxHealth)
{
	//cout << "MAX HEALTH : " << maxHealth << endl;
	this->healthBar->updateHealth(this->health, maxHealth, this->sprite);
}

int AbstractEnemy::dealDamage()
{

	attackSound.setBuffer(attackBuffer);
	attackSound.play();
	return this->damage;
}

Projectile AbstractEnemy::shoot(Vector2f distance)
{
	//sound
	return Projectile();
}

std::string AbstractEnemy::getName()
{
	//cout << "My name is :" << this->name << endl;
	return this->name;
}

void AbstractEnemy::onCollision(Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//cout << "Collision on the left." << endl;
		velocity.x = 0.0f;
	}

	if (direction.x > 0.0f)
	{
		//cout<<"Collision on the right."<<endl;
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		this->isMidAir = false;
		//cout << "Collision on the bottom." << endl;
		velocity.y = 0.0f;
		//canJump = true;
	}

	if (direction.y > 0.0f)
	{
		//cout << "Collision on the top." << endl;
		velocity.y = 0.0f;
	}
}

void AbstractEnemy::checkIfActive(float distance)
{
	if (distance <= this->activationRange)
		this->unfreeze();
}

void AbstractEnemy::die()
{
	//sound
	//animation
	//
}

bool AbstractEnemy::dropPickup()
{
	for (int i = 0; i < this->value; i++)
	{
		if (rand() % 2 == 0)
			return true;
	}
	return false;
}

void AbstractEnemy::setTexture()
{
	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
}

