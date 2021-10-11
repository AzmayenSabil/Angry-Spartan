//this function is depreciated 

//please use projectile instead
#include "Arrow.h"
#include "Projectile.h"

Arrow::Arrow()
{
	this->arrowTexture.loadFromFile("images/arrow.png");
	this->arrowSprite.setTexture(arrowTexture);
	this->arrowSprite.setTextureRect(IntRect(0, 0, 531, 1505));
	this->arrowSprite.setScale(Vector2f(1 / 18.f, 1 / 18.f));
}

Arrow::~Arrow()
{

}

//what is direction? ans-> from RangedEnemyAttack class, the direction will be set to 1 or -1. 
// -1 = spartan is to the left, so the arrow will move to the left
// 1 = spartan is to the right, so the arrow will move to the right

void Arrow::Move()
{
	if (direction == -1) {
		arrowSprite.setScale(1 / 18.f, 1 / 18.f);
		arrowSprite.move(-3.f, 0.f);
	}

	if (direction == 1) {
		arrowSprite.setScale(-1 / 18.f, 1 / 18.f);
		arrowSprite.move(3.f, 0.f);
	}
}

void Arrow::Draw(RenderTarget & target)
{
	target.draw(arrowSprite);
}
