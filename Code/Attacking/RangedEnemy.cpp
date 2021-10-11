#include "RangedEnemy.h"

//this class is depreciated, use enemy class instead

void RangedEnemy::initEnemy()
{
	this->rangedEnemyTexture.loadFromFile("images/AttackingSpartanAnimation.png");
	this->rangedEnemyTexture.setSmooth(true);
	this->rangedEnemySprite.setTexture(this->rangedEnemyTexture);

	this->currentFrame = IntRect(0, 0, 64, 48);

	randomX = rand() % 406 + 406;

	this->rangedEnemySprite.setTextureRect(this->currentFrame);
	this->rangedEnemySprite.setScale(-1.5f, 1.5f);
	this->rangedEnemySprite.setPosition(randomX, 255.f); // 812.f = x
	this->rangedEnemySprite.setColor(Color::Cyan);

	this->health = 100;
}

RangedEnemy::RangedEnemy()
{
	this->initEnemy();
}

RangedEnemy::~RangedEnemy()
{

}

void RangedEnemy::updateMovement(Sprite spartanSprite)
{
	randomMoveX = rand() % 2 + .65;

	if (spartanSprite.getPosition().x < this->rangedEnemySprite.getPosition().x) {
		this->rangedEnemySprite.move(-randomMoveX, 0.f); // following left
	}

	if (spartanSprite.getPosition().x > this->rangedEnemySprite.getPosition().x) {
		this->rangedEnemySprite.move(randomMoveX, 0.f); // following right
	}
}

void RangedEnemy::renderrangedEnemy(RenderTarget & target)
{
	target.draw(this->rangedEnemySprite);
}
