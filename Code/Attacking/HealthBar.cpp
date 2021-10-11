#include "HealthBar.h"

HealthBar::HealthBar()
{
	frameTexture.loadFromFile("images/HealthBarFrame.png");
	fillTexture.loadFromFile("images/HealthBarFill.png");

	frameSprite.setTexture(frameTexture);
	frameSprite.setColor(Color::Black);
	fillSprite.setTexture(fillTexture);
	//fillSprite.setColor(Color::Yellow);

	showFill = true;
	//MAX_HEALTH = 100;

}


HealthBar::~HealthBar()
{
}

void HealthBar::updateHealth(int health, int maxHealth, Sprite sprite)
{
	frameSprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 7.f);
	fillSprite.setPosition(sprite.getPosition().x + 2.f, sprite.getPosition().y -5.f);

	float factor = 1; // maxHealth / 100.f;

	float scaleX = (float(health) / maxHealth);
	fillSprite.setScale(scaleX*factor, 1.0f);

	if (health <= 0)
	{
		showFill = false;
	}
	else
	{
		showFill = true;
	}
}

void HealthBar::updateSpartanHealth(int health, int maxHealth , RenderTarget& target)
{
	//frameSprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 5.f);
	//fillSprite.setPosition(sprite.getPosition().x + 2.f, sprite.getPosition().y + 7.f);

	//float factor = maxHealth / 500.f; //500 = 5

	float scaleX = (float(health) / maxHealth); // 400/500 = 4/5
	frameSprite.setScale(3.f, 3.f);
	fillSprite.setScale(3.2*scaleX, 3.5f); // 3.2*1*(5)

	if (health <= 0)
	{
		showFill = false;
	}
	else
	{
		showFill = true;
	}
}


void HealthBar::Draw(sf::RenderTarget & target)
{
	//cout << "running" << endl;
	if (showFill == true)
	{
		target.draw(fillSprite);
	}

	target.draw(frameSprite);
}
