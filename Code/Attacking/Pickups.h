#pragma once

#include "Pickup.h"
#include "HealthPickup.h"

#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>


using namespace std;
using namespace sf;

class Pickups
{
public:
	Pickups();
	~Pickups();

	vector<Pickup*> list;

	void chooseLevel(int level);

	void render(RenderTarget & target);

	void clearPickups();

	void update(Spartan spartan);

	void add(Vector2f location) { this->list.push_back(new HealthPickup(location)); }

private:
	Texture texture;

	void initLevel1Pickups();
	void initLevel2Pickups();
	void initLevel3Pickups();
};

