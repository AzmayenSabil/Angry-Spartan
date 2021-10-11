#include "SpartanAttackAnimation.h"

SpartanAttackAnimation::SpartanAttackAnimation()
{
	//this->currentFrameHeavyAttack = IntRect(0, 0, 90, 120);

	this->totalTime = 0.f;
	this->switchTime = 200.f;

}

SpartanAttackAnimation::~SpartanAttackAnimation()
{

}

void SpartanAttackAnimation::updateCloseQuarterAttackAnimation(Sprite * playerSprite, string type, float deltaTime)
{
	totalTime += deltaTime * 2000.f; // 2000.f is a random value that I picked to make the animation smoother

	if (type == "heavyAttack") {

		cout << "heavy attack animation 1 -- pressed q " << totalTime <<" "<<switchTime<< endl;

		currentFrameHeavyAttack.top = 0.f;

		if (totalTime >= switchTime) {

			totalTime -= switchTime;

			currentFrameHeavyAttack.left += 90.f;
			//cout << currentFrameHeavyAttack.left << " D" << endl;
			//cout << endl;

			if (currentFrameHeavyAttack.left >= 270.f)
				currentFrameHeavyAttack.left = 0;
		}

		playerSprite->setTextureRect(currentFrameHeavyAttack);

		playerSprite->setScale(1.1f, 1.1f);
		playerSprite->setOrigin(0.f, 0.f);

	}
	
}
