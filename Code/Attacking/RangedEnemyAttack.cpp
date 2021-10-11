#include "RangedEnemyAttack.h"

RangedEnemyAttack::RangedEnemyAttack()
{
	this->totalTime = 0;
	this->switchTime = 200.f;
}

RangedEnemyAttack::~RangedEnemyAttack()
{

}

void RangedEnemyAttack::attack(Spartan * spartan, Enemy * rangedEnemy, vector<Projectile> &projectiles, float deltaTime)
{
	
	totalTime += deltaTime*400.f;

	if (totalTime >= switchTime) {

		totalTime -= 300.f;

		if (spartan->spartanSprite.getPosition().y >= rangedEnemy->sprite.getPosition().y &&
			spartan->spartanSprite.getPosition().x < rangedEnemy->sprite.getPosition().x) {
			
			/*arrow.arrowSprite.setPosition(rangedEnemy->sprite.getPosition().x - 64.f, rangedEnemy->sprite.getPosition().y + 36.f);
			arrow.direction = -1; // arrows will go left
			arrows.push_back((Arrow)arrow);*/
			this->projectile.sprite.setPosition(rangedEnemy->sprite.getPosition().x - 64.f, rangedEnemy->sprite.getPosition().y + 36.f);
			this->projectile.isLeftDirected = true;
			projectiles.push_back((Projectile)projectile);
		
		}

		else if (spartan->spartanSprite.getPosition().y >= rangedEnemy->sprite.getPosition().y &&
			spartan->spartanSprite.getPosition().x > rangedEnemy->sprite.getPosition().x) {
			
			/*arrow.arrowSprite.setPosition(rangedEnemy->sprite.getPosition().x, rangedEnemy->sprite.getPosition().y + 36.f);
			arrow.direction = 1; // arrows will go right
			arrows.push_back((Arrow)arrow);*/

			this->projectile.sprite.setPosition(rangedEnemy->sprite.getPosition().x - 64.f, rangedEnemy->sprite.getPosition().y + 36.f);
			this->projectile.isLeftDirected = false;
			projectiles.push_back((Projectile)projectile);
		
		}

	}

}

void RangedEnemyAttack::decreaseHealthOfSpartan(Spartan *spartan)
{
	if (spartan->health > 0)
		spartan->health -= 10;

	cout << "player health: " << spartan->health << endl;

	if (spartan->health <= 0) {
		cout << " D   E   A   D" << endl;
	}
}

bool RangedEnemyAttack::checkSpartanDeadOrNot(Spartan * spartan)
{
	if (spartan->health <= 0)
		return true;
	else
		return false;
}


