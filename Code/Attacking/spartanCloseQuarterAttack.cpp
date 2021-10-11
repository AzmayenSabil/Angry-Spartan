#include "spartanCloseQuarterAttack.h"
#include "spartanCloseQuarterAttack.h"



void spartanCloseQuarterAttack::initVariables()
{
	this->attackedLightly = false;
	this->attackedHeavily = false;
	this->countMouseClick = 0;
	this->countKeyClick = 0;

	this->totalTime = 0;
	this->switchTime = 200.f;
}

void spartanCloseQuarterAttack::setSpartan(Sprite *spartan)
{
	this->spartan = spartan;
}

void spartanCloseQuarterAttack::setcloseQuarterEnemy(Enemy * closeQuarterEnemy)
{
	this->closeQuarterEnemy = closeQuarterEnemy;
}


spartanCloseQuarterAttack::spartanCloseQuarterAttack()
{
	this->initVariables();
}

spartanCloseQuarterAttack::~spartanCloseQuarterAttack()
{

}


void spartanCloseQuarterAttack::closeQuarterAttack(float deltaTime)
{
	
	totalTime += deltaTime * 4000.f;

	if (totalTime >= switchTime) {

		totalTime -= switchTime;

		//Heavy attack//

		if (Keyboard::isKeyPressed(Keyboard::Q)) {
			this->attackedHeavily = true;
			this->countKeyClick++;
		}

		if (this->attackedHeavily && this->countKeyClick == 1)
		{
			cout << "Heavy ATTACK" << endl;


			if (this->spartan->getGlobalBounds().intersects(this->closeQuarterEnemy->sprite.getGlobalBounds())) {

				cout << "ENEMY HAS BEEN HEAVILY ATTACKED" << endl;

				if (this->closeQuarterEnemy->health >= 0) {
					cout << this->closeQuarterEnemy->health << endl;
					this->closeQuarterEnemy->health -= 10;
				}

				else if (this->closeQuarterEnemy->health <= 0)
					cout << "ENEMY IS DEAD!! WOHOO!!" << endl;
			}

			//spartan heavy attack animation will be called from here//
			//spartanAttackAnimation.updateCloseQuarterAttackAnimation(spartan, "heavyAttack", deltaTime);
			//-------------------------------------------------------//

		}


		if (this->countKeyClick > 1) {
			this->countKeyClick = 0;
			this->attackedHeavily = false;
		}


		//------heavy attack ended----//

		//Light attack

		if (Mouse::isButtonPressed(Mouse::Left)) {
			this->attackedLightly = true;
			this->countMouseClick++;
		}

		if (this->attackedLightly && this->countMouseClick == 1) {

			cout << "light ATTACK" << endl;


			if (this->spartan->getGlobalBounds().intersects(this->closeQuarterEnemy->sprite.getGlobalBounds())) {

				cout << "ENEMY HAS BEEN LIGHTLY ATTACKED" << endl;

				if (this->closeQuarterEnemy->health >= 0) {
					cout << this->closeQuarterEnemy->health << endl;
					this->closeQuarterEnemy->health -= 5;
				}

				else if (this->closeQuarterEnemy->health <= 0)
					cout << "ENEMY IS DEAD!! WOHOO!!" << endl;
			}
		}

		if (this->mouseEvent.MouseButtonReleased) {
			this->countMouseClick = 0;
			this->attackedLightly = false;
		}

		//---------------light attack ended------------------------------------//

	}
}

bool spartanCloseQuarterAttack::checkCloseQuarterDeadOrNot()
{
	if (closeQuarterEnemy->health <= 0) {
		return true;
	}
	
	return false;
}

