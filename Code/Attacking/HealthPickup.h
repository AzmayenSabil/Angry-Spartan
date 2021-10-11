#pragma once

#include "Pickup.h"
#include "Spartan.h"

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


class HealthPickup : public Pickup
{
public:

	HealthPickup(Vector2f location);
	~HealthPickup();

	void doSomething(Spartan spartan);

private:


};

