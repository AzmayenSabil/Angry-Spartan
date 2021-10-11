#include "Wall.h"

Wall::Wall(IntRect rect, Vector2f pos, Vector2f resize)
{
	texture.loadFromFile("images/platform.png");
	bodySprite.setTexture(texture);
	bodySprite.setTextureRect(rect);
	bodySprite.setPosition(pos);
	bodySprite.setScale(resize);
}

Wall::~Wall()
{
}

void Wall::draw(RenderTarget & target)
{
	target.draw(bodySprite);
}

Sprite Wall::getSprite()
{
	return this->bodySprite;
}
