#include "Enemy.h"


Enemy::Enemy(String type)
{
	this->chooseType(type);

	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
	
}

Enemy::~Enemy()
{

}


void Enemy::updateMovement(Sprite spartanSprite, float deltaTime)
{

	if (this->canMove == true)
	{
		randomMovementX = rand() % this->updateMovementX + this->updateMovementY;

		if (spartanSprite.getPosition().x < this->sprite.getPosition().x) {
			//this->sprite.move(-randomMovementX, 0.f); // following left
			//this->animation->walk(&this->sprite, true, deltaTime);
		}

		if (spartanSprite.getPosition().x > this->sprite.getPosition().x) {
			//this->sprite.move(randomMovementX, 0.f); // following right
			//this->animation->walk(&this->sprite, false, deltaTime);
		}
	}
}

void Enemy::updateHealthBar()
{
	this->healthBar->updateHealth(this->health, 0, this->sprite);
}

void Enemy::renderEnemy(RenderTarget & target)
{
	target.draw(this->sprite);
	this->healthBar->Draw(target);
}

int Enemy::getHealth()
{
	return this->health;
}

bool Enemy::isDead()
{
	return this->health <= 0;
}

void Enemy::enemyAttack(Sprite target)
{

}

Vector2f Enemy::getPositon()
{
	return this->sprite.getPosition();
}

void Enemy::updateAnimation()
{

}

int Enemy::dealDamage()
{
	return this->damage;
}



void Enemy::chooseType(String type)
{
	if (type == "Swordsman")
	{
		this->initSwordsman();
	}
	else if (type == "Archer")
	{
		this->initArcher();
	}
	else if (type == "Brute")
	{
		this->initHeavy();
	}
	else if (type == "Hybrid")
	{
		this->initHybrid();
	}
}

void Enemy::initSwordsman()
{
	this->texture.loadFromFile("images/AttackingSpartanAnimation.png");
	this->currentFrame = IntRect(0, 0, 64, 48);

	randomX = rand() % 406 + 380;	

	this->sprite.setScale(-1.25f, 1.25f);
	this->sprite.setPosition(randomX, 267.f); // x = 748.f
	this->sprite.setColor(Color::Red);
	this->sprite.setTextureRect(this->currentFrame);

	this->health = 100;

	this->updateMovementX = 5.f;
	this->updateMovementY = 0.75;

	this->canMove = true;

	this->score = 5;

	this->damage = 5;

	this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 64, 48), IntRect(0, 192, 64, 48), IntRect(), 0.f, 384.f, 0.f, 0.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.25f, 1.25f));
	this->healthBar = new HealthBar();

}

void Enemy::initArcher()
{
	this->texture.loadFromFile("images/archersprite.png");
	this->currentFrame = IntRect(0, 0, 97, 134);

	randomX = rand() % 2000 + 406;

	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(-0.5f, 0.5f);
	this->sprite.setPosition(randomX, 260.f); // 812.f = x
	this->sprite.setColor(Color::Cyan);

	//cout << randomX << endl;
	this->health = 100;

	this->updateMovementX = 2;
	this->updateMovementY = .65;

	this->canMove = true;

	//this->arrows = Projectiles();


	this->score = 10;

	this->animation = new Animation(0.f, 200.f, IntRect(0, 0, 97, 134), IntRect(0, 0, 97, 134), IntRect(), IntRect(), 0.f, 376.f, 0.f, 0.f, 0.f, 0.f, Vector2f(97, 134), Vector2f(.5f, .5f));
	this->healthBar = new HealthBar();

}

void Enemy::initHeavy()
{
	this->texture.loadFromFile("images/AttackingSpartanAnimation.png");
	this->currentFrame = IntRect(0, 0, 64, 48);

	randomX = rand() % 406 + 380;

	this->sprite.setScale(-1.25f, 1.25f);
	this->sprite.setPosition(randomX, 267.f); // x = 748.f
	this->sprite.setColor(Color::Black);
	this->sprite.setTextureRect(this->currentFrame);

	this->health = 300;

	this->updateMovementX = 3;
	this->updateMovementY = 0.75;

	this->canMove = true;

	this->score = 5;
	this->damage = 20;

	this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 97, 134), IntRect(), IntRect(), 0.f, 64.f, 0.f, 0.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	this->healthBar = new HealthBar();

}

void Enemy::initHybrid()
{

}


