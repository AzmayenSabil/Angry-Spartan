#include "Spawner.h"

//this class spawns everything
Spawner::Spawner()
{
}

Spawner::~Spawner()
{
}

void Spawner::spawnEnemy(int number, String type, vector <Enemy *>& list)
{
	list.clear();
	for (int i = 1; i <= number; i++) {
		list.push_back(new Enemy(type));
		//cout << enemyList.size() << endl;
	}

}

void Spawner::spawnEnemy1(int number, String type, vector<AbstractEnemy *>& list, Vector2f location)
{

	//list.push_back(new Swordsman(Vector2f(location.x + (i*50.f), location.y)));
	for (int i = 1; i <= number; i++) {
		if (type == "Swordsman")
			//list.push_back(new Swordsman(location));
			list.push_back(new Swordsman(Vector2f(location.x + ((i - 1)*50.f), location.y)));
		else if (type == "Archer")
			list.push_back(new Archer(Vector2f(location.x + ((i - 1)*50.f), location.y)));
		else if (type == "Brute")
			list.push_back(new Brute(Vector2f(location.x + ((i - 1)*50.f), location.y)));
		else if (type == "Immortal")
			list.push_back(new Immortal(Vector2f(location.x + ((i - 1)*50.f), location.y)));
		//cout << enemyList.size() << endl;
	}
}








