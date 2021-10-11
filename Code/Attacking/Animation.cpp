#include "Animation.h"

Animation::Animation(float totalTime, float switchTime,
	IntRect currentFrameIdle, IntRect currentFrameWalking, IntRect currentFrameJumping, IntRect currentFrameAttacking,
	float walkingFrameStart, float walkingFrameEnd, float jumpingFrameStart, float jumpingFrameEnd,
	float attackingFrameStart, float attackingFrameEnd,
	Vector2f frameWidthAndHeight, Vector2f scale)
{
	this->totalTime = totalTime;
	this->switchTime = switchTime;

	// IntRect takes 4 parameters -> left, top, width, height

	this->currentFrameIdle = currentFrameIdle;
	this->currentFrameWalking = currentFrameWalking;
	this->currentFrameJumping = currentFrameJumping;
	this->currentFrameAttacking = currentFrameAttacking;

	this->walkingFrameStart = walkingFrameStart;
	this->walkingFrameEnd = walkingFrameEnd;
	this->jumpingFrameStart = jumpingFrameStart;
	this->jumpingFrameEnd = jumpingFrameEnd;
	this->attackingFrameStart = attackingFrameStart;
	this->attackingFrameEnd = attackingFrameEnd;

	this->frameWidthAndHeight = frameWidthAndHeight;
	this->scale = scale;
}

Animation::~Animation()
{
}

void Animation::setLightAttackFrame(IntRect currentLightAttackingFrame, float lightAttackingFrameStart, float lightAttackingFrameEnd)
{
	this->currentLightAttackingFrame = currentLightAttackingFrame;
	this->lightAttackingFrameStart = lightAttackingFrameStart;
	this->lightAttackingFrameEnd = lightAttackingFrameEnd;
}

void Animation::setHeavyAttackFrame(IntRect currentHeavyAttackingFrame, float heavyAttackingFrameStart, float heavyAttackingFrameEnd)
{
	this->currentHeavyAttackingFrame = currentHeavyAttackingFrame;
	this->heavyAttackingFrameStart = heavyAttackingFrameStart;
	this->heavyAttackingFrameEnd = heavyAttackingFrameEnd;
}

void Animation::setBlockingFrame(IntRect currentFrameBlocking, float blockingFrameStart, float blockingFrameEnd)
{
	this->currentFrameBlocking = currentFrameBlocking;
	this->blockingFrameStart = blockingFrameStart;
	this->blockingFrameEnd = blockingFrameEnd;
}

void Animation::idle(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	totalTime += deltaTime * 2000.f;

	if (!isFacingLeft) { // idle -- facing right

		sprite->setTextureRect(currentFrameIdle);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

		//cout << "Is Idle Right" << endl;

	}

	else if (isFacingLeft) { // idle -- facing left

		sprite->setTextureRect(currentFrameIdle);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

		//cout << "Is Idle left" << endl;
	}
}

void Animation::walk(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	totalTime += deltaTime * 2000.f; // 2000.f is a random value that I picked to make the animation smoother

	if (!isFacingLeft) //D
	{
		//cout << "running animation 1 -- D " << totalTime <<" "<<switchTime<< endl;

		currentFrameWalking.top = 0.f;

		if (totalTime >= switchTime) {

			totalTime -= switchTime;

			currentFrameWalking.left += frameWidthAndHeight.x;
			//cout << currentFrameWalking.left << " D" << endl;
			//cout << endl;

			if (currentFrameWalking.left >= walkingFrameEnd)
				currentFrameWalking.left = walkingFrameStart;
		}

		sprite->setTextureRect(currentFrameWalking);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

		//cout << "Is Moving Right" << endl;

	}


	else if (isFacingLeft) // A
	{
		//cout << "running animation 2 -- A "<< totalTime << endl;

		currentFrameWalking.top = 0.f;

		if (totalTime >= switchTime) {

			totalTime -= switchTime;

			currentFrameWalking.left += frameWidthAndHeight.x;
			//cout << currentFrameWalking.left << " A" << endl;
			//cout << endl;

			if (currentFrameWalking.left >= walkingFrameEnd)
				currentFrameWalking.left = walkingFrameStart;
		}

		sprite->setTextureRect(currentFrameWalking);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

		//cout << "Is Moving Left" << endl;

	}
}

void Animation::attack(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	totalTime += deltaTime * 2000.f;

	if (!isFacingLeft) // space (facing right)
	{
		//cout << "running animation 3 -- space" << totalTime << endl;

		currentFrameAttacking.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameAttacking.left += frameWidthAndHeight.x;

			//cout << currentFrameJumping.left << " space " << endl;
			//cout << endl;

			if (currentFrameAttacking.left >= attackingFrameEnd)
				currentFrameAttacking.left = attackingFrameStart;

		}

		sprite->setTextureRect(currentFrameAttacking);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

	}

	else if (isFacingLeft) // space (facing left)
	{
		//cout << "running animation 4 -- space "<< totalTime << endl;

		currentFrameAttacking.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameAttacking.left += frameWidthAndHeight.x;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentFrameAttacking.left >= attackingFrameEnd)
				currentFrameAttacking.left = attackingFrameStart;
		}

		sprite->setTextureRect(currentFrameAttacking);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

	}

}

void Animation::heavyAttack(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	
	totalTime += deltaTime * 500.f; // 2000.f

	if (!isFacingLeft) // space (facing right)
	{
		//cout << "running animation 3 -- space" << totalTime << endl;

		currentHeavyAttackingFrame.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentHeavyAttackingFrame.left += frameWidthAndHeight.x;

			//cout << currentFrameJumping.left << " space " << endl;
			//cout << endl;

			if (currentHeavyAttackingFrame.left >= heavyAttackingFrameEnd)
				currentHeavyAttackingFrame.left = heavyAttackingFrameStart;

		}

		sprite->setTextureRect(currentHeavyAttackingFrame);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

	}

	else if (isFacingLeft) // space (facing left)
	{
		//cout << "running animation 4 -- space "<< totalTime << endl;

		currentHeavyAttackingFrame.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentHeavyAttackingFrame.left += frameWidthAndHeight.x;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentHeavyAttackingFrame.left >= heavyAttackingFrameEnd)
				currentHeavyAttackingFrame.left = heavyAttackingFrameStart;
		}

		sprite->setTextureRect(currentHeavyAttackingFrame);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

	}
}

void Animation::lightAttack(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	totalTime += deltaTime * 2000.f;

	if (!isFacingLeft) // space (facing right)
	{
		//cout << "running animation 3 -- space" << totalTime << endl;

		currentLightAttackingFrame.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentLightAttackingFrame.left += frameWidthAndHeight.x;

			//cout << currentFrameJumping.left << " space " << endl;
			//cout << endl;

			if (currentLightAttackingFrame.left >= lightAttackingFrameEnd)
				currentLightAttackingFrame.left = lightAttackingFrameStart;

		}

		sprite->setTextureRect(currentLightAttackingFrame);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

	}

	else if (isFacingLeft) // space (facing left)
	{
		//cout << "running animation 4 -- space "<< totalTime << endl;

		currentLightAttackingFrame.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentLightAttackingFrame.left += frameWidthAndHeight.x;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentLightAttackingFrame.left >= lightAttackingFrameEnd)
				currentLightAttackingFrame.left = lightAttackingFrameStart;
		}

		sprite->setTextureRect(currentLightAttackingFrame);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

	}
}

void Animation::block(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	totalTime += deltaTime * 2000.f;

	if (!isFacingLeft) // space (facing right)
	{
		//cout << "blocking animation 3 -- space" << totalTime << endl;

		currentFrameBlocking.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameBlocking.left += frameWidthAndHeight.x;

			//cout << currentFrameJumping.left << " space " << endl;
			//cout << endl;

			if (currentFrameBlocking.left >= blockingFrameEnd)
				currentFrameBlocking.left = blockingFrameStart;

		}

		sprite->setTextureRect(currentFrameBlocking);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

	}

	else if (isFacingLeft) // space (facing left)
	{
		//cout << "blocking animation 4 -- space "<< totalTime << endl;

		currentFrameBlocking.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameBlocking.left += frameWidthAndHeight.x;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentFrameBlocking.left >= blockingFrameEnd)
				currentFrameBlocking.left = blockingFrameStart;
		}

		sprite->setTextureRect(currentFrameBlocking);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

	}

}

void Animation::jump(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	totalTime += deltaTime * 2000.f;

	if (!isFacingLeft) // space (facing right)
	{
		//cout << "running animation 3 -- space" << totalTime << endl;

		currentFrameJumping.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 400.f; //350

			currentFrameJumping.left += frameWidthAndHeight.x;

			//cout << currentFrameJumping.left << " space " << endl;
			//cout << endl;

			if (currentFrameJumping.left >= jumpingFrameEnd)
				currentFrameJumping.left = jumpingFrameStart;

		}

		sprite->setTextureRect(currentFrameJumping);

		sprite->setScale(scale);
		sprite->setOrigin(0.f, 0.f);

	}

	else if (isFacingLeft) // space (facing left)
	{
		//cout << "running animation 4 -- space "<< totalTime << endl;

		currentFrameJumping.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 400.f; //350

			currentFrameJumping.left += frameWidthAndHeight.x;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentFrameJumping.left >= jumpingFrameEnd)
				currentFrameJumping.left = jumpingFrameStart;
		}

		sprite->setTextureRect(currentFrameJumping);

		sprite->setScale(-scale.x, scale.y);
		sprite->setOrigin(sprite->getGlobalBounds().width / scale.x, scale.y);

	}
}

void Animation::die(Sprite * sprite, bool isFacingLeft, float deltaTime)
{
	
}
