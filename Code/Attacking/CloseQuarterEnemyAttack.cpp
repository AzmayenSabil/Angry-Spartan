#include "CloseQuarterEnemyAttack.h"

CloseQuarterEnemyAttack::CloseQuarterEnemyAttack()
{
	this->totalTime = 0;
	this->switchTime = 200.f;
}

CloseQuarterEnemyAttack::~CloseQuarterEnemyAttack()
{

}

void CloseQuarterEnemyAttack::attack(Spartan * spartan,Enemy * closeQuarterEnemy, float deltaTime)
{
	totalTime += deltaTime * 400.f;

	if (totalTime >= switchTime) {

		totalTime -= switchTime;

		if (Keyboard::isKeyPressed(Keyboard::LShift)) {

			if (spartan->spartanSprite.getGlobalBounds().intersects(closeQuarterEnemy->sprite.getGlobalBounds())) {

				cout << "ATTACK BLOCKED" << endl;
			}

		}

		else if (spartan->spartanSprite.getGlobalBounds().intersects(closeQuarterEnemy->sprite.getGlobalBounds())) {

			if (spartan->health > 0)
				spartan->health -= 5;

			cout << "player health: " << spartan->health << endl;


			if (spartan->health <= 0) {
				cout << " D   E   A   D" << endl;
			}

		}

	}
}

bool CloseQuarterEnemyAttack::checkSpartanDeadOrNot(Spartan * spartan)
{
	if (spartan->health <= 0)
		return true;
	else
		return false;
}
