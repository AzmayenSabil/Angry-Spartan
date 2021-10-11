#include "Platform.h"

Platform::Platform(Texture* bodyTexture, IntRect rect, Vector2f pos, Vector2f resize)
{
	bodySprite.setTexture(*bodyTexture);
	bodySprite.setTextureRect(rect); 
	bodySprite.setPosition(pos);
	bodySprite.setScale(resize);

}

Platform::~Platform()
{

}

void Platform::draw(RenderTarget & target)
{
	target.draw(bodySprite);
}

Sprite Platform::getSprite()
{
	return this->bodySprite;
}
