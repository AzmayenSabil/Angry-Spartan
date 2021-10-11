#include "SpartanAnimation.h"
//should be animation class, independent
SpartanAnimation::SpartanAnimation()
{
	this->totalTime = 0.f;
	this->switchTime = 200.f;
	
	// IntRect takes 4 parameters -> left, top, width, height
	// 97,134 == width,height

	this->currentFrameIdle = IntRect(0, 0, 97, 134);
	this->currentFrameWalking = IntRect(97, 0, 97, 134);  // 97,0 -> starting of walking animation
	this->currentFrameJumping = IntRect(582, 0, 97, 134); // 582,0 ->  starting of jumping animation

}

SpartanAnimation::~SpartanAnimation()
{

}


//refactor so that understandable
void SpartanAnimation::updateAnimation(Sprite *playerSprite, string type, float deltaTime)
{
	totalTime += deltaTime * 2000.f; // 2000.f is a random value that I picked to make the animation smoother

	if (type == "moveRight") //D
	{
		//cout << "running animation 1 -- D " << totalTime <<" "<<switchTime<< endl;

		currentFrameWalking.top = 0.f;

		if (totalTime >= switchTime) {

			totalTime -= switchTime;

			currentFrameWalking.left += 97.f;
			//cout << currentFrameWalking.left << " D" << endl;
			//cout << endl;

			if (currentFrameWalking.left >= 582.f)
				currentFrameWalking.left = 97;
		}
		
		playerSprite->setTextureRect(currentFrameWalking);

		playerSprite->setScale(.5f, .5f);
		playerSprite->setOrigin(0.f, 0.f);
		
	}


	else if (type == "moveLeft") // A
	{
		//cout << "running animation 2 -- A "<< totalTime << endl;

		currentFrameWalking.top = 0.f;

		if (totalTime >= switchTime) {

			totalTime -= switchTime;

			currentFrameWalking.left += 97.f;
			//cout << currentFrameWalking.left << " A" << endl;
			//cout << endl;

			if (currentFrameWalking.left >= 582.f)
				currentFrameWalking.left = 97;
		}

		playerSprite->setTextureRect(currentFrameWalking);


		playerSprite->setScale(-0.5f, 0.5f);
		playerSprite->setOrigin(playerSprite->getGlobalBounds().width / 0.5f, 0.5f);

	}

	else if (type == "jumpFacingRight") // space (facing right)
	{
		//cout << "running animation 3 -- space" << totalTime << endl;

		currentFrameJumping.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameJumping.left += 97.f;

			//cout << currentFrameJumping.left << " space " << endl;
			//cout << endl;

			if (currentFrameJumping.left >= 1067.f)
				currentFrameJumping.left = 582.f;

		}

		playerSprite->setTextureRect(currentFrameJumping);

		playerSprite->setScale(0.5f, 0.5f);
		playerSprite->setOrigin(0.f, 0.f);

	}

	else if (type == "jumpFacingLeft") // space (facing left)
	{
		//cout << "running animation 4 -- space "<< totalTime << endl;

		currentFrameJumping.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameJumping.left += 97.f;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentFrameJumping.left >= 1067.f)
				currentFrameJumping.left = 582.f;
		}

		playerSprite->setTextureRect(currentFrameJumping);

		playerSprite->setScale(-0.5f, 0.5f);
		playerSprite->setOrigin(playerSprite->getGlobalBounds().width / 0.5f, 0.5f);

	}

	else if (type == "jumpAndMoveFacingRight") // space D
	{
		//cout << "running animation 3 -- space D " << totalTime << endl;

		currentFrameJumping.top = 0.f;
			
		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameJumping.left += 97.f;

			//cout << currentFrameJumping.left << " space D" << endl;
			//cout << endl;

			if (currentFrameJumping.left >= 1067.f)
				currentFrameJumping.left = 582.f;
		
		}

		playerSprite->setTextureRect(currentFrameJumping);

		playerSprite->setScale(0.5f, 0.5f);
		playerSprite->setOrigin(0.f, 0.f);

	}

	else if (type == "jumpAndMoveFacingLeft") // space A
	{
		//cout << "running animation 4 -- space A "<< totalTime << endl;

		currentFrameJumping.top = 0.f;

		if (totalTime >= 350.f) {

			totalTime -= 350.f;

			currentFrameJumping.left += 97.f;
			//cout << currentFrameJumping.left << " W A" <<endl;
			//cout << endl;

			if (currentFrameJumping.left >= 1067.f)
				currentFrameJumping.left = 582.f;
		}

		playerSprite->setTextureRect(currentFrameJumping);

		playerSprite->setScale(-0.5f, 0.5f);
		playerSprite->setOrigin(playerSprite->getGlobalBounds().width / 0.5f, 0.5f);

	}

	else if (type == "idleRight") { // idle -- facing right
		
		playerSprite->setTextureRect(currentFrameIdle);

		playerSprite->setScale(0.5f, 0.5f);
		playerSprite->setOrigin(0.f, 0.f);
	
    }

	else if (type == "idleLeft") { // idle -- facing left

		playerSprite->setTextureRect(currentFrameIdle);

		playerSprite->setScale(-0.5f, 0.5f);
		playerSprite->setOrigin(playerSprite->getGlobalBounds().width / 0.5f, 0.5f);

	}


}
