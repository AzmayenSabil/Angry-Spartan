#include "Checkpoints.h"

Checkpoints::Checkpoints()
{
}

Checkpoints::~Checkpoints()
{
}

void Checkpoints::update(float location, int levelNumber, int health)
{
	for (int i = 0; i < checkpointList.size(); i++)
	{
		if (checkpointList[i].checkIfReached(location, levelNumber, health))
		{
			checkpointList.erase(checkpointList.begin() + i);
			i -= 1;
		}

	}
}

void Checkpoints::chooseLevel(int level)
{
	if (level == 1)
	{
		this->initLevel1Checkpoints();
	}
	else if (level == 2)
	{
		this->initLevel2Checkpoints();
	}
	else if (level == 3)
	{
		this->initLevel3Checkpoints();
	}
}


void Checkpoints::initLevel1Checkpoints()
{
	this->clear();

	this->addCheckpoint(500);
	this->addCheckpoint(1200);
}

void Checkpoints::initLevel2Checkpoints()
{
	this->addCheckpoint(500);
	this->addCheckpoint(1200);
}

void Checkpoints::initLevel3Checkpoints()
{
}
