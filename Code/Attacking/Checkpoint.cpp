#include "Checkpoint.h"

Checkpoint::Checkpoint(float location)
{
	this->locationX = location;


}

Checkpoint::~Checkpoint()
{
}

bool Checkpoint::checkIfReached(float location, int levelNumber, int health)
{
	if (!this->isReached && this->locationX < location)
	{
		std::ofstream file;
		file.open("Test.txt");
		file << levelNumber << " " << this->locationX << " " << health;
		cout << "Checkpoint reached at: " << this->locationX << endl;
		this->isReached = true;
		file.close();
		return true;
	}
	return false;
}


