#include "Pickups.h"

Pickups::Pickups()
{
}

Pickups::~Pickups()
{
}

void Pickups::chooseLevel(int level)
{
	if (level == 1)
	{
		this->initLevel1Pickups();
	}
	else if (level == 2)
	{
		this->initLevel2Pickups();
	}
	else if (level == 3)
	{
		this->initLevel3Pickups();
	}
}

void Pickups::render(RenderTarget & target)
{
	for (auto i = 0; i < list.size(); i++)
	{
		this->list[i]->render(target);
	}
}

void Pickups::clearPickups()
{
}

void Pickups::update(Spartan spartan)
{
	for (auto i = 0; i < list.size(); i++)
	{
		if (&list[i] == NULL)
			continue;
		if (abs(this->list[i]->getPosition().x - spartan.getPosition().x) <= 5)
		{
			this->list[i]->doSomething(spartan);
			list.erase(list.begin() + i);
		}
	}
}

void Pickups::initLevel1Pickups()
{
	Pickup *pickup1 = new HealthPickup(Vector2f(7000.f, 180.f)); // Main platform
	list.push_back(pickup1);
}

void Pickups::initLevel2Pickups()
{
}

void Pickups::initLevel3Pickups()
{
}
