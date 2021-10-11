#include "Combat.h"
#include<thread>

void Combat::attack(Spartan* spartan, Enemies* enemies, vector<Projectile> &projectiles, float deltaTime)
{
	for (int i = 0; i < enemies->enemyList.size(); i++) {
		//
		//this->rangedEnemyAttack.attack(&spartan, enemies.rangedEnemyList[i], arrows, deltaTime);
		if (enemies->enemyList[i]->getName() == "Swordsman" || enemies->enemyList[i]->getName() == "Brute" ||
			enemies->enemyList[i]->getName() == "Immortal")
		{
			this->enemyCloseAttack(spartan, enemies->enemyList[i], deltaTime);
			thread t1(&Combat::enemyCloseAttack, this, spartan, enemies->enemyList[i], deltaTime);
			t1.detach();
		}

		else if (enemies->enemyList[i]->getName() == "Archer" && enemies->enemyList[i]->isActive)
			this->rangedEnemyAttack1(spartan, enemies->enemyList[i], projectiles, deltaTime);
	}

}

void Combat::spartanAttack(Spartan * spartan, Enemies * enemies, vector<Projectile>& projectiles, float deltaTime, int* score)
{
	if (enemies->enemyList.size() < 1)
	{
		spartan->finishHeavyAttack();
		spartan->finishLightAttack();
		return;
	}

	if (spartan->getHeavyAttackStatus())
	{
		this->spartanHeavyAttack(spartan, enemies);
	}

	if (spartan->getLightAttackStatus())
	{
		this->spartanLightAttack(spartan, enemies);
	}


}

void heavyAttack(Spartan* spartan, Enemy* enemy, float deltaTime) {
	cout << "Thread Called";
	//spartan->heavyAttack(enemy, deltaTime);
}

void Combat::spartanCloseAttack(Spartan * spartan, AbstractEnemy * enemy, float deltaTime)
{

	totalTime += deltaTime * 4000.f;

	if (totalTime >= switchTime) {

		totalTime -= switchTime;

		//Heavy attack//
		/*if (spartan->heavyAttacking)
		{
			float attackLocation = spartan->heavyAttack();
			cout << "Attack location: "<< attackLocation << endl;
			cout << "Enemy location: " << enemy->getPositon().x << endl;
			if ( (attackLocation - enemy->getPositon().x <= 200))
				cout << "Attack landed on enemy" << endl;
		}*/


		/*if (isSpartanIdle  &&  Keyboard::isKeyPressed(Keyboard::Q)) {
			this->attackedHeavily = true;
			this->countKeyClick++;
		}

		if (this->attackedHeavily && this->countKeyClick == 1)
		{
			cout << "Heavy ATTACK" << endl;


			if (spartan->getSprite().getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {


				thread t2(&Spartan::heavyAttack, spartan, enemy, deltaTime, &isSpartanAttackFinished);
				t2.join();
				if (isSpartanAttackFinished)
				{

					isSpartanIdle = true;
				}


				cout << "ENEMY HAS BEEN HEAVILY ATTACKED" << endl;

				if (enemy->health >= 0) {
					cout << enemy->health << endl;
					enemy->health -= 10;
				}

				else if (enemy->health <= 0)
					cout << "ENEMY IS DEAD!! WOHOO!!" << endl;
			}

			//spartan heavy attack animation will be called from here//
			//spartanAttackAnimation.updateCloseQuarterAttackAnimation(spartan, "heavyAttack", deltaTime);
			//-------------------------------------------------------//

		}


		if (this->countKeyClick > 1) {
			this->countKeyClick = 0;
			this->attackedHeavily = false;
		}*/


		//------heavy attack ended----//

		//Light attack

		/*if (Mouse::isButtonPressed(Mouse::Left)) {
			this->attackedLightly = true;
			this->countMouseClick++;
		}

		if (this->attackedLightly && this->countMouseClick == 1) {

			cout << "light ATTACK" << endl;


			if (spartan->getSprite().getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {

				cout << "ENEMY HAS BEEN LIGHTLY ATTACKED" << endl;

				if (enemy->getHealth() >= 0) {
					cout << enemy->getHealth() << endl;
					enemy->takeDamage(spartan->dealLightAttackDamage());
				}

				else if (enemy->isDead())
					cout << "ENEMY IS DEAD!! WOHOO!!" << endl;
			}
		}

		if (this->mouseEvent.MouseButtonReleased) {
			this->countMouseClick = 0;
			this->attackedLightly = false;
		}*/

		//---------------light attack ended------------------------------------//

	}
}

void Combat::update(Spartan* spartan, Enemies* enemies, vector<Projectile> &projectiles, float deltaTime, int* score)
{
	this->spartan = spartan;
	isPlayerBlocking = spartan->block(deltaTime);

	thread t1(&Combat::attack, this, spartan, enemies, ref(projectiles), deltaTime);
	//this->attack(spartan, enemies, projectiles, deltaTime);

	thread t2(&Combat::hitWithProjectile, this, ref(projectiles), ref(*spartan));
	//this->hitWithProjectile(projectiles, *spartan);

	thread t3(&Combat::spartanAttack, this, spartan, enemies, ref(projectiles), deltaTime, score);
	//this->spartanAttack(spartan, enemies, projectiles, deltaTime, score);

	t1.join();
	t2.join();
	t3.join();
}

void Combat::enemyCloseAttack(Spartan * spartan, AbstractEnemy * enemy, float deltaTime)
{
	totalTime += deltaTime * 400.f;

	if (totalTime >= switchTime) {

		totalTime -= switchTime;

		bool canHit = abs(spartan->getPosition().x - enemy->getPositon().x) <= enemy->getCombatRange().x &&
			abs(spartan->getPosition().y - enemy->getPositon().y) <= enemy->getCombatRange().y;

		//-----------------------------//

		if (spartan->spartanSprite.getPosition().x < enemy->sprite.getPosition().x) {
			enemy->faceRight = false;
		}
		else if (spartan->spartanSprite.getPosition().x > enemy->sprite.getPosition().x) {
			enemy->faceRight = true;
		}

		enemy->deltaTime = deltaTime;

		//-----------------------------//

		if (spartan->block(deltaTime)) {
			if (canHit) {
				enemy->attack();
				this_thread::sleep_for(1s);
				if (canHit && enemy->isAlive())
				{
					spartan->blockAttack(spartan->getPosition().x < enemy->getPositon().x);
					cout << "ATTACK BLOCKED" << endl;
				}
			}
		}

		else if (canHit && enemy->isAlive()) {

			if (!spartan->checkIfDead())
			{
				enemy->attack();
				this_thread::sleep_for(1s);
				if (canHit && enemy->isAlive())
					spartan->takeDamage(enemy->dealDamage());
			}

			cout << "player health: " << spartan->health << endl;

			if (spartan->health <= 0) {
				cout << " D   E   A   D" << endl;
			}
		}
	}
}

Vector2f Combat::dropPickup()
{
	return this->pickupLocations.back();
}


void Combat::spartanHeavyAttack(Spartan* spartan, Enemies* enemies)
{
	cout << "Heavy Attack on: " << spartan->GetPosition().x << endl;
	for (int i = 0; i < enemies->enemyList.size(); i++) {

		cout << "Attack location: " << spartan->getPosition().x << endl;
		cout << "Enemy location: " << enemies->enemyList[i]->getPositon().x << endl;
		if (abs(spartan->getPosition().x - enemies->enemyList[i]->getPositon().x) <= 200 &&
			abs(spartan->getPosition().y - enemies->enemyList[i]->getPositon().y) <= 50)
		{
			//spartan->heavyAttack();
			cout << "Attack landed on enemy" << endl;
			enemies->enemyList[i]->takeDamage(spartan->dealHeavyAttackDamage());
		}
		if (this->removeDeadEnemy(spartan, enemies, i))
			i -= 1;

	}
	spartan->finishHeavyAttack();
}

void Combat::spartanLightAttack(Spartan * spartan, Enemies * enemies)
{

	int i = findClosestEnemy(spartan, enemies);
	cout << "Light Attack on: " << spartan->GetPosition().x << endl;

	if (abs(spartan->getPosition().x - enemies->enemyList[i]->getPositon().x) <= 100 &&
		abs(spartan->getPosition().y - enemies->enemyList[i]->getPositon().y) <= 50)
	{
		cout << "Attack landed on enemy" << endl;
		enemies->enemyList[i]->takeDamage(spartan->dealLightAttackDamage());
		this->removeDeadEnemy(spartan, enemies, i);
	}

	/*for (int i = 0; i < enemies->enemyList.size(); i++) {

		cout << "Attack location: " << spartan->GetPosition().x << endl;
		cout << "Enemy location: " << enemies->enemyList[i]->getPositon().x << endl;
		if (abs(spartan->getPosition().x - enemies->enemyList[i]->getPositon().x) <= 50)
		{
			cout << "Attack landed on enemy" << endl;
			enemies->enemyList[i]->takeDamage(spartan->dealLightAttackDamage());
			this->removeDeadEnemy(spartan, enemies, i);
			break;
		}

	}*/
	spartan->finishLightAttack();
}

bool Combat::removeDeadEnemy(Spartan * spartan, Enemies* enemies, int i)
{
	if (enemies->enemyList[i]->isDead()) {
		spartan->updateScore(enemies->enemyList[i]->getScore());
		enemies->enemyList[i]->die();
		if (enemies->enemyList[i]->dropPickup())
			this->setPickup(enemies->enemyList[i]->getPositon());
		enemies->enemyList.erase(enemies->enemyList.begin() + i);
		return true;
	}
	return false;
}

int Combat::findClosestEnemy(Spartan * spartan, Enemies * enemies)
{
	double minX = INT_MAX, distance = 0.f;
	int index = -1;
	for (int i = 0; i < enemies->enemyList.size(); i++) {

		distance = abs(spartan->getPosition().x - enemies->enemyList[i]->getPositon().x);
		if (distance <= minX)
		{
			minX = distance;
			index = i;
		}

	}
	return index;
}

void Combat::closeEnemyAttack(Spartan * spartan, Enemy * enemy, float deltaTime)
{
	totalTime += deltaTime * 400.f;

	if (totalTime >= switchTime) {

		totalTime -= switchTime;

		if (spartan->block(deltaTime)) {

			if (spartan->spartanSprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {

				cout << "ATTACK BLOCKED" << endl;
			}

		}

		else if (spartan->spartanSprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {

			if (!spartan->checkIfDead())
				spartan->takeDamage(enemy->dealDamage());


			cout << "player health: " << spartan->health << endl;


			if (spartan->health <= 0) {
				cout << " D   E   A   D" << endl;
			}

		}

	}
}

void Combat::rangedEnemyAttack(Spartan * spartan, Enemy * enemy, vector<Projectile> &projectiles, float deltaTime)
{
	totalTime += deltaTime * 400.f;

	if (totalTime >= switchTime) {

		totalTime -= 300.f;

		if (spartan->spartanSprite.getPosition().y >= enemy->sprite.getPosition().y &&
			spartan->spartanSprite.getPosition().x < enemy->sprite.getPosition().x) {

			this->projectile.sprite.setPosition(enemy->sprite.getPosition().x - 64.f, enemy->sprite.getPosition().y + 36.f);
			this->projectile.isLeftDirected = true;
			projectiles.push_back((Projectile)projectile);

		}

		else if (spartan->spartanSprite.getPosition().y >= enemy->sprite.getPosition().y &&
			spartan->spartanSprite.getPosition().x > enemy->sprite.getPosition().x) {

			this->projectile.sprite.setPosition(enemy->sprite.getPosition().x - 64.f, enemy->sprite.getPosition().y + 36.f);
			this->projectile.isLeftDirected = false;
			projectiles.push_back((Projectile)projectile);

		}

	}
}

void Combat::rangedEnemyAttack1(Spartan * spartan, AbstractEnemy * enemy, vector<Projectile>& projectiles, float deltaTime)
{
	totalTime += deltaTime * 400.f;

	if (totalTime >= switchTime) {

		totalTime -= 300.f;

		if (spartan->spartanSprite.getPosition().y >= enemy->sprite.getPosition().y && // LEFT
			spartan->spartanSprite.getPosition().x < enemy->sprite.getPosition().x) {
			float distanceX = abs(spartan->getPosition().x - enemy->getPositon().x);
			float distanceY = abs(spartan->getPosition().y - enemy->getPositon().y);
			float velocity;
			if (distanceY > 10)
			{
				this->projectile.isGravity = true;
				velocity = sqrt(981.0f*distanceX*distanceX / 2 * distanceY);
			}

			else
			{
				velocity = sqrt(981.0f*distanceX*distanceX / 2 * 1);
				this->projectile.isGravity = false;
			}

			cout << velocity << endl;
			this->projectile.sprite.setPosition(enemy->sprite.getPosition().x - 20.f, enemy->sprite.getPosition().y + 30.f);
			this->projectile.isLeftDirected = true;
			this->projectile.setVelocityX(velocity);
			enemy->faceRight = false;
			enemy->deltaTime = deltaTime;
			enemy->updateAnimation();
			projectiles.push_back((Projectile)projectile);

		}

		else if (spartan->spartanSprite.getPosition().y >= enemy->sprite.getPosition().y && // RIGHT
			spartan->spartanSprite.getPosition().x > enemy->sprite.getPosition().x) {
			float distanceX = abs(spartan->getPosition().x - enemy->getPositon().x);
			float distanceY = abs(spartan->getPosition().y - enemy->getPositon().y);
			float velocity;
			if (distanceY != 0)
				velocity = sqrt(981.0f*distanceX*distanceX / 2 * distanceY);
			else
				velocity = sqrt(981.0f*distanceX*distanceX / 2 * 1);
			//cout << velocity << endl;

			this->projectile.sprite.setPosition(enemy->sprite.getPosition().x + 64.f, enemy->sprite.getPosition().y + 30.f);
			this->projectile.isLeftDirected = false;
			this->projectile.setVelocityX(velocity);
			enemy->faceRight = true;
			enemy->deltaTime = deltaTime;
			enemy->updateAnimation();
			projectiles.push_back((Projectile)projectile);

		}

	}
}

void Combat::hitWithProjectile(vector<Projectile> &projectiles, Spartan &spartan)
{
	Vector2f arrowDirection;
	/*for (int i = 0; i < projectiles.size(); i++) {  // checking collision between spartan and arrow
		if (projectiles[i].GetCollider().CheckCollision2(spartan.GetCollider(), arrowDirection, 0.0f)) {
			//cout << "Direction.x: " << arrowDirection.x << "Direction.y: " << arrowDirection.y << endl;
			projectiles.erase(projectiles.begin() + i);
			spartan.takeDamage(projectiles[i].damage);
		}
	}*/

	for (int i = 0; i < projectiles.size(); i++) {  // checking collision between spartan and arrow
		if (projectiles[i].GetCollider().CheckCollision2(spartan.GetCollider(), arrowDirection, 0.0f)) {
			//cout << "Direction.x: " << arrowDirection.x << "Direction.y: " << arrowDirection.y << endl;
			projectiles.erase(projectiles.begin() + i);
			if (!spartan.block(0))
			{
				projectiles[i].dealDamage();
				this->spartan->health -= this->arrowDamage;
				this->spartan->takeDamage(this->arrowDamage);
			}

			else
				cout << "Arrow blocked" << endl;
		}
	}
}

void Combat::decreaseHealthOfSpartan(Spartan * spartan)
{
	if (spartan->health > 0)
		spartan->health -= 10;

	cout << "player health: " << spartan->health << endl;

	if (spartan->health <= 0) {
		cout << " D   E   A   D" << endl;
	}
}



