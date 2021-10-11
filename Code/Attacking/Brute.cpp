#include "Brute.h"

Brute::Brute(Vector2f location)
{
	this->name = "Brute";

	this->texture.loadFromFile("images/Brute attack resized.png");
	this->currentFrame = IntRect(0, 0, 160, 139);
	this->sprite.setScale(-.5f, .5f);
	//this->sprite.setPosition(randomX, 225.f); // x = 748.f
	//this->sprite.setColor(Color::Black);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setPosition(location);

	/*this->attackTexture.loadFromFile("images/Brute attack.png");
	this->currentFrameAttacking = IntRect(0, 0, 160, 160);
	this->attackSprite.setScale(-.5f, .5f);
	//this->attackSprite.setPosition(randomX, 225.f); // x = 748.f
	//this->sprite.setColor(Color::Black);
	this->attackSprite.setTextureRect(this->currentFrameAttacking);
	this->attackSprite.setPosition(location);*/

	randomX = rand() % 406 + 380;

	this->health = 100;
	this->maxHealth = 100;

	this->updateMovementX = 1;
	this->updateMovementY = 0.75;

	this->canMove = true;

	this->scoreIfKilled = 20;
	this->damage = 7; //20
	this->activationRange = 200;
	this->combatRange = Vector2f(100.f, 100.f);

	//this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 97, 134), IntRect(), IntRect(), 64.f, 0.f, 0.f, Vector2f(64, 48), Vector2f(1.5f, 1.5f));
	this->animation = new Animation(0.f, 200.f, IntRect(), IntRect(0, 0, 160.f, 139.f), IntRect(), IntRect(), 0.f, 800.f, 0.f, 0.f, 0.f, 0.f, Vector2f(160.f, 139.f), Vector2f(.5f, .5f));
	//this->attackAnimation = new Animation(0.f, 200.f, IntRect(), IntRect(), IntRect(), IntRect(0, 0, 160, 160), 0.f, 0.f, 0.f, 0.f, 0.f, 800.f, Vector2f(160.f, 160.f), Vector2f(.5f, .5f));
	this->healthBar = new HealthBar();

	this->value = 4;

	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);

	this->attackTexture.setSmooth(true);
	this->attackSprite.setTexture(this->attackTexture);
}

Brute::~Brute()
{
}

void Brute::updateAnimation()
{

}

void Brute::attack()
{
	if (faceRight) {
		//this->animation->attack(&this->sprite, false, deltaTime);
		cout << "spartan on right of brute" << endl;
	}
	else {
		//this->animation->attack(&this->sprite, true, deltaTime);
		cout << "spartan on left of brute" << endl;
	}

	//isAttacking = true;
	//isWalking = false;

	this_thread::sleep_for(1s);
}

