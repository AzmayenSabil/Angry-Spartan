#pragma once

#include "Collider.h"
#include "ScoreSystem.h"
#include "Enemy.h"
#include "Animation.h"



#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <math.h>
#include <fstream>

#include <SFML/system.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>

#include <dos.h> //for delay
#include <windows.h>
#include <thread>
#include <stdbool.h>

using namespace std;
using namespace sf;

class Checkpoint
{
public:
	Checkpoint(float location);
	~Checkpoint();

	bool checkIfReached(float location, int levelNumber, int health);

	bool isDone() { return this->isReached;  }

	

private:
	float locationX;

	bool isReached = false;

	
};

