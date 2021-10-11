#include "CloseQuarterEnemy.h"

//this class is depreciated, use enemy class instead

void CloseQuarterEnemy::initEnemy()
{
	this->closeQuarterTexture.loadFromFile("images/AttackingSpartanAnimation.png");
	this->closeQuarterTexture.setSmooth(true);
	this->closeQuarterSprite.setTexture(this->closeQuarterTexture);
	
	this->currentFrame = IntRect(0, 0, 64, 48);

	randomX = rand() % 406 + 380;

	this->closeQuarterSprite.setTextureRect(this->currentFrame);
	this->closeQuarterSprite.setScale(-1.25f, 1.25f);
	this->closeQuarterSprite.setPosition(randomX, 267.f); // x = 748.f
	this->closeQuarterSprite.setColor(Color::Red);

	this->health = 100;
}



CloseQuarterEnemy::CloseQuarterEnemy()
{
	initEnemy();
}

CloseQuarterEnemy::~CloseQuarterEnemy()
{

}

void CloseQuarterEnemy::updateMovement(Sprite spartanSprite)
{
	randomMovementX = rand() % 3 + 0.75;

	if (spartanSprite.getPosition().x < this->closeQuarterSprite.getPosition().x) {
		this->closeQuarterSprite.move(-randomMovementX, 0.f); // following left
	}

	if (spartanSprite.getPosition().x > this->closeQuarterSprite.getPosition().x) {
		this->closeQuarterSprite.move(randomMovementX, 0.f); // following right
	}
}


void CloseQuarterEnemy::renderCloseQuarter(RenderTarget & target)
{
	target.draw(this->closeQuarterSprite);
}
