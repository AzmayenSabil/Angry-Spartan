#include "Spartan.h"

thread* t1;

void Spartan::initPlayer()
{
	this->spartanTextureSheet.loadFromFile("images/allspriteofspartan.png");
	this->spartanTextureSheet.setSmooth(true);
	this->spartanSprite.setTexture(this->spartanTextureSheet);

	this->currentFrame = IntRect(0, 0, 97, 134);

	this->spartanSprite.setTextureRect(this->currentFrame);
	this->spartanSprite.setScale(.5f, .5f);
	this->spartanSprite.setPosition(450.f, 260.f); // (5,260)
}

void Spartan::initVariables()
{
	this->jumpHeight = 150.f;
	this->speed = 200.f;
	this->canJump = true;
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	this->health = 5000;
	this->switchTime = 200.f;
	this->totalTime = 0.f;
	this->faceRight = true;

}


void Spartan::chargeSpeed()  //need to implement timelimit
{
	Clock clock1;
	Time t1 = clock1.getElapsedTime();
	/*while (t1.asSeconds() != 3)
	{
		velocity.x *= 3;
		t1 = clock1.getElapsedTime();
	}*/
	while (abs(velocity.x) < 600)
		velocity.x *= 1.5;
}

void Spartan::updateHeavyAttackLocation()
{
	if (heavyAttacking)
		this->heavyAttackLocation = getPosition().x;
	else
		this->heavyAttackLocation = -1;
}

bool Spartan::isChargeAble()
{
	if (this->getPosition().x + velocity.x < 2428.f && this->getPosition().x + velocity.x > 1.f)
		return true;
	return false;
}

void Spartan::regenerateStamina()
{

	regenTime = regenClock.getElapsedTime();
	if (!isBlocking && !isCharging && isIdle() && regenTime.asSeconds() >= 1)
	{
		cout << "Stamina Increased" << endl;
		this->increaseStamina(1);
		regenClock.restart();
	}
}

void Spartan::regenerateHealth()
{
	regenTime = regenClock.getElapsedTime();
	if (!isBlocking && !isCharging && isIdle() && regenTime.asSeconds() >= 1)
	{
		this->increaseHealth(2);
		if (this->health > 100) {
			this->health = 100;
		}
		regenClock.restart();
	}
}

void Spartan::rageMode()
{
	rageTime = rageClock.getElapsedTime();
	if (!this->isRageOn  && sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && this->rage >= this->maxRage)
	{
		cout << "rage triggered" << endl;
		rageClock.restart();
		this->isRageOn = true;
		this->takeDamageMultiplier = 0.1;
		this->dealDamageMultiplier = 5;
		this->spartanSprite.setColor(Color::Red);
	}
	if (this->isRageOn && rageTime.asSeconds() >= 1)
	{
		this->reduceRage(5);
		rageClock.restart();
		rageTime = rageClock.getElapsedTime();
	}
	if (this->isRageOn && this->isRageEmpty())
	{
		this->isRageOn = false;
		this->takeDamageMultiplier = 1;
		this->dealDamageMultiplier = 1;
		this->spartanSprite.setColor(Color::White);
	}
}

void Spartan::reduceRage(int amount)
{
	this->rage -= amount;
	if (this->isRageEmpty())
		this->rage = 0;
}

Spartan::Spartan()
{
	this->initPlayer();
	this->initVariables();

	lightAttackBuffer.loadFromFile("sounds/light-Attack.wav");
	lightAttackSound.setBuffer(lightAttackBuffer);
	lightAttackSound.setVolume(20);

	swordBlockBuffer.loadFromFile("sounds/sword_hit_shield.wav");
	swordBlockSound.setBuffer(swordBlockBuffer);
	swordBlockSound.setVolume(20);

	animation.setLightAttackFrame(IntRect(1455, 0, 97, 134), 1455.f, 1649.f);
	animation.setHeavyAttackFrame(IntRect(1164, 0, 97, 134), 1164.f, 1358.f);
	animation.setBlockingFrame(IntRect(1746, 0, 97, 134), 1746.f, 1940.f);

}

Spartan::~Spartan()
{

}

void Spartan::updateMovement(float deltaTime)
{
	//cout << "Player position is: " << this->getPosition().x << endl;

	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		velocity.x -= speed;
		/*if (this->getPosition().x < 1.f)
			velocity.x = 0;*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += speed;
		/*if (this->getPosition().x > 2428.f)
			velocity.x = 0;*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}


	if (charge())
		this->chargeSpeed();


	//--------------------------------------------------------------------//
	velocity.y += 981.0f*deltaTime;
	//--------------------------------------------------------------------//



	this->spartanSprite.move(velocity*deltaTime);
}


void Spartan::updateAnimation(float deltaTime)
{
	//totalTime += deltaTime * 2000.f; // 2000.f is a random value that I picked to make the animation smoothee
	isVerticalMoving();
	if (isHorizontalMoving() && !this->verticalMoving)
	{
		//spartanAnimation.updateAnimation(&spartanSprite, "moveRight", deltaTime);
		this->animation.walk(&this->spartanSprite, !faceRight, deltaTime);

	}

	if (Keyboard::isKeyPressed(Keyboard::LControl)) { // BLOCK
		if (faceRight) {
			this->animation.block(&this->spartanSprite, false, deltaTime);
		}
		else {
			this->animation.block(&this->spartanSprite, true, deltaTime);
		}
	}

	//-------------------------//


	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (faceRight) {
			this->animation.lightAttack(&this->spartanSprite, false, deltaTime);
		}
		else {
			this->animation.lightAttack(&this->spartanSprite, true, deltaTime);
		}
	}

	/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (faceRight) {
			this->animation.heavyAttack(&this->spartanSprite, false, deltaTime);
		}
		else {
			this->animation.heavyAttack(&this->spartanSprite, true, deltaTime);
		}
	}*/
	//---------------------//

	else if (this->verticalMoving && !isHorizontalMoving() && faceRight)
	{
		//spartanAnimation.updateAnimation(&spartanSprite, "jumpFacingRight", deltaTime);
		//this->animation.jump(&this->spartanSprite, !faceRight, deltaTime);
		this->animation.idle(&this->spartanSprite, !faceRight, deltaTime);
	}

	else if (this->verticalMoving && isHorizontalMoving())
	{
		//spartanAnimation.updateAnimation(&spartanSprite, "jumpAndMoveFacingRight", deltaTime);
		//this->faceRight = true;
		//this->animation.jump(&this->spartanSprite, !faceRight, deltaTime);
		this->animation.idle(&this->spartanSprite, !faceRight, deltaTime);
	}



	else if (velocity.x == 0 && !this->isBlocking)
	{
		//spartanAnimation.updateAnimation(&spartanSprite, "idleRight", deltaTime);
		this->animation.idle(&this->spartanSprite, !faceRight, deltaTime);
		textChannel.updateText("IDLE");
	}


}

/*void Spartan::updateCloseQuarterAttack(float deltaTime, Enemy * closeQuarter)
{
	this->closeQuarterAttack.setSpartan(&spartanSprite);
	this->closeQuarterAttack.setcloseQuarterEnemy(closeQuarter);

	this->closeQuarterAttack.closeQuarterAttack(deltaTime);

	if (this->closeQuarterAttack.checkCloseQuarterDeadOrNot()) {
		scoreSystem.updateScore("Swordsman");
	}
}*/



//------------------COLLISION PART----------------------------------//

void Spartan::onCollision(sf::Vector2f direction)
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
		this->verticalMoving = false;
		//cout << "Collision on the bottom." << endl;
		velocity.y = 0.0f;
		canJump = true;
	}

	if (direction.y > 0.0f)
	{
		//cout << "Collision on the top." << endl;
		velocity.y = 0.0f;
	}

}

// ---------------------------------------------------------------// 


void Spartan::render(RenderTarget & target)
{
	target.draw(spartanSprite);
	//target.draw(scoreSystem.scoreText);
	textChannel.draw(target, spartanSprite.getPosition(), -10.f, -20.f);
	textChannel.updateText("");
}

Vector2f Spartan::getPosition()
{
	return spartanSprite.getPosition();
}

bool Spartan::checkIfDead()
{
	if (this->getHealth() <= 0)
		return true;

	return false;
}

void Spartan::takeDamage(float damage)
{
	this->health -= damage * this->takeDamageMultiplier;
	if (!this->isRageFull())
		this->rage += damage / 5;
	if (this->rage > this->maxRage)
		this->rage = this->maxRage;
	cout << "Rage is currently at:" << this->rage << endl;
}

float Spartan::heavyAttack()  //bool Spartan::heavyAttack(Enemy * enemy, float deltatime, bool* finished)
{
	if (isIdle() && !this->verticalMoving && Keyboard::isKeyPressed(Keyboard::K))
	{
		textChannel.updateText("Heavy Attacking");

		if (faceRight) {
			this->animation.heavyAttack(&this->spartanSprite, false, 0);
		}
		else {
			this->animation.heavyAttack(&this->spartanSprite, true, 0);
		}

		cout << "Player is now heavy attacking" << endl;



		using namespace std::literals::chrono_literals;

		Clock c1;
		Time t1 = c1.getElapsedTime();
		//while (t1.asSeconds() != 3.0f)
			//t1 = c1.getElapsedTime();

		this->idle = false;
		this_thread::sleep_for(0.5s);
		this->heavyAttackGoing = true;

		updateHeavyAttackLocation();

		//animation.attack(&enemy->getSprite(), !faceRight, deltatime);

		//*finished = true;

		cout << getPosition().x << endl;



		//this->spartanAttack.HeavyAttack(getPosition());


		return getPosition().x;
	}

	return false;
}

void Spartan::lightAttack()
{
	if (isIdle() && Keyboard::isKeyPressed(Keyboard::J))
	{
		textChannel.updateText("Light Attacking");

		this->lightAttackSound.play();
		if (faceRight) {
			this->animation.lightAttack(&this->spartanSprite, false, 0);
		}
		else {
			this->animation.lightAttack(&this->spartanSprite, true, 0);
		}

		cout << "Player is now light attacking" << endl;

		this->idle = false;

		this->lightAttackGoing = true;



		//animation.attack(&enemy->getSprite(), !faceRight, deltatime);

		//*finished = true;

		cout << getPosition().x << endl;



		//this->spartanAttack.HeavyAttack(getPosition());


	}
}

void Spartan::update(float deltaTime)
{
	if (isIdle())
	{
		//cout << "this is update" << endl;
		this->updateMovement(deltaTime);
		this->updateAnimation(deltaTime);
		this->block(deltaTime);
		this->charge();
		//thread t2(&Spartan::heavyAttack, this);
		//t1 = &t2;
		this->heavyAttack();
		this->lightAttack();
		//t2.join();
		this->regenerateStamina();
		this->regenerateHealth();
		this->rageMode();

	}


}

bool Spartan::block(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::LControl) && !isStaminaEmpty())
	{
		textChannel.updateText("Blocking");
		//this->reduceStamina(2);
		this->isBlocking = true;
		cout << "Player is blocking" << endl;
		if (faceRight) {
			this->animation.block(&this->spartanSprite, false, deltaTime);
		}
		else {
			this->animation.block(&this->spartanSprite, true, deltaTime);
		}
		return true;
	}
	this->isBlocking = false;

	return false;

}

bool Spartan::charge()
{
	if (isHorizontalMoving() && !this->verticalMoving && Keyboard::isKeyPressed(Keyboard::LShift) && this->stamina > 5)
	{
		textChannel.updateText("Charging");
		this->isCharging = true;
		chargeTime = chargeClock.getElapsedTime();
		if (chargeTime.asSeconds() >= 1)
		{
			this->reduceStamina(5);
			if (stamina < 0)
				stamina = 0;
			chargeClock.restart();
		}

		cout << "Player is charging" << endl;

		return true;
	}
	this->isCharging = false;
	return false;
}

void Spartan::throwSpear()
{

}

bool Spartan::isIdle()
{


	return idle;
}

bool Spartan::isHorizontalMoving()
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->faceRight = true;
		return true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->faceRight = false;
		return true;
	}
	return false;
}

bool Spartan::isVerticalMoving()
{
	if (Keyboard::isKeyPressed(Keyboard::Space)) //need a way to know if player is in mid air
	{
		this->verticalMoving = true;
		//cout << abs(velocity.y) << endl;
		return true;
	}
	return false;
}

void Spartan::finishHeavyAttack()
{
	this->heavyAttackGoing = false;
	this->idle = true;
}

void Spartan::finishLightAttack()
{
	this->lightAttackGoing = false;
	this->idle = true;
}

void Spartan::startHeavyAttack()
{
	this->heavyAttackGoing = true;
	this->idle = false;
}

void Spartan::increaseStamina(int amount)
{
	this->stamina += amount;
	if (this->stamina > this->maxStamina)
		this->stamina = this->maxStamina;
}

bool Spartan::isStaminaEmpty()
{
	if (this->stamina <= 0)
	{
		cout << "Stamina depleted" << endl;
		return true;
	}

	return  false;
}

void Spartan::blockAttack(bool isDirectionRight)
{
	this->swordBlockSound.play();
	cout << "Attack Blocked" << endl;
	this->reduceStamina(5);
	if (stamina < 0)
		stamina = 0;
	if (isDirectionRight)
		this->spartanSprite.move(-20.0f, 0.0f);
	else
		this->spartanSprite.move(20.0f, 0.0f);
}
