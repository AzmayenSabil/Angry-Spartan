#pragma once

#include "Collider.h"
#include "ScoreSystem.h"
#include "Enemy.h"
#include "Animation.h"
#include "Checkpoint.h"



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

#include <dos.h> //for delay
#include <windows.h>
#include <thread>
#include <stdbool.h>

using namespace std;
using namespace sf;

class Checkpoints
{
public:
	Checkpoints();
	~Checkpoints();

	void update(float location, int levelNumber, int health);

	void addCheckpoint(float location) { checkpointList.push_back(Checkpoint(location)); }
	void clear() { checkpointList.clear(); }

	void chooseLevel(int level);

	

private:
	vector<Checkpoint> checkpointList;

	void initLevel1Checkpoints();
	void initLevel2Checkpoints();
	void initLevel3Checkpoints();
};

