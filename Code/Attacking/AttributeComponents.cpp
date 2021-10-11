#include "AttributeComponents.h"

AttributeComponents::AttributeComponents()
{
	rageFrameTexture.loadFromFile("images/rageFrame.png");
	ragefillTexture.loadFromFile("images/rageFill.png");
	rageframeSprite.setTexture(rageFrameTexture);
	ragefillSprite.setTexture(ragefillTexture);

	spearTexture.loadFromFile("images/spear.png");
	spearSprite.setTexture(spearTexture);

	staminaTexture.loadFromFile("images/stamina bar.png"); // 1045 x 145
	staminaSprite.setTexture(staminaTexture);

}

AttributeComponents::~AttributeComponents()
{

}

void AttributeComponents::updateStaminaBar(int stamina)
{
	float MAX_STAMINA = 20;
	if (stamina <= MAX_STAMINA) {
		float scaleX = (float(stamina) / MAX_STAMINA);
		staminaSprite.setScale(2.5*(scaleX/15.f), 1.4*(1/15.f));
		staminaSprite.setColor(Color::Green);
	}
	if (stamina == MAX_STAMINA) {
		staminaSprite.setColor(Color::Red);
	}
}

void AttributeComponents::updateRageBar(int rage)
{
	//std::cout << "RAGE : " << rage << endl;

	if (rage >= 1 && rage <= 7) {
		this->rageCount = 1;
	}
	else if (rage > 7 && rage <= 14) {
		this->rageCount = 2;
	}
	else if (rage > 14 && rage <= 20) {
		this->rageCount = 3;
	}
	else {
		this->rageCount = 0;
	}
}

void AttributeComponents::updateSpearBar(int spear)
{

}

void AttributeComponents::draw(RenderTarget & target, Vector2f pos)
{
	//std::cout << "RAGE-count: " << rageCount<< endl;
	//--------ragebar----//
	for (int i = 0; i < 3; i++) {
		rageframeSprite.setScale(1 / 50.f, 1 / 50.f);
		rageframeSprite.setPosition(pos.x - 435.f + gap, pos.y - 200.f);
		rageframeSprite.setColor(Color::Black);
		target.draw(rageframeSprite);
		gap += 50;
	}
	gap = 0;
	for (int i = 0; i < this->rageCount; i++) {
		ragefillSprite.setScale(1 / 41.f, 1 / 41.f);
		ragefillSprite.setPosition(pos.x - 431.f + gap, pos.y - 197.5f);
		ragefillSprite.setColor(Color::Red);
		target.draw(ragefillSprite);
		gap += 50;
	}
	gap = 0;

	//-----spear-----//
	/*for (int i = 0; i < 3; i++) {
		spearSprite.setScale(1 / 30.f, 1 / 30.f);
		spearSprite.setPosition(pos.x - 230.f + gap, pos.y - 250.f);
		spearSprite.setColor(Color::Red);
		target.draw(spearSprite);
		gap += 50;
	}*/
	gap = 0;

	//----stamina----//
	//staminaSprite.setScale(3.3f, 2.f);
	staminaSprite.setPosition(pos.x - 435.f, pos.y - 215.f);
	target.draw(staminaSprite);
}
